/*
**
**  Project: multi channels module
**  File:      multi_channel_hook.c
**  Author: huangjunyuan
**  Date:    09/6/2015
**
**  Purpose:
**      multi channels module.
**
**  History:
**  <author>   <time>          <version >   <desc>
*/
#include <net/ip.h>
#include <linux/init.h>
#include <net/tcp.h>
#include <net/sock.h>
#include <linux/time.h>
#include <linux/init.h>
#include <net/netlink.h>
#include <linux/timer.h>
#include <linux/types.h>
#include <linux/skbuff.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/version.h>
#include <linux/proc_fs.h>
#include <linux/file.h>
#include <linux/icmp.h>
#include <net/icmp.h>
#include <linux/netfilter.h>
#include <linux/rtnetlink.h>
#include <linux/netfilter/xt_state.h>
#include <net/netfilter/ipv4/nf_reject.h>

#include <net/netfilter/nf_conntrack_core.h>
#include <net/netfilter/nf_conntrack_tuple.h>
#include <net/netfilter/nf_conntrack_ecache.h>
#include <linux/netfilter/nf_conntrack_common.h>

#ifdef CONFIG_SYSCTL
#include <linux/sysctl.h>
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("huangjunyuan0016003461@nubia.com.cn");
MODULE_DESCRIPTION("multi channels module");

#define K1S                         (HZ)        // ~1s
#define WIFI_INDEX                             0
#define LTE_INDEX                                2
#define CONGESTION_FLAG                 3
#define IDLE_BACK_RTT                       1
#define IF_NUM                                     4
#define DEV_NAME_LEA                        16
#define MIN_WEIGHT                             10           //wifi min weight
#define MAX_WEIGHT                            90           //wifi max weight
#define MIN_SPEED_LEVEL                   5          //speed + rtt min 10KB/s
#define SHAKE_SPEED_LEVEL               50          //speed back standard
#define DEFAULT_LEVE_SPEED              25          //speed back standard
#define AVG_SPEED_LEVEL                   300         //5s avg speed 300kB/s
#define DOWN_LOAD_SPEED_LEVEL    400         //down load flag  speed 400kb/s
#define BACK_DOWN_LOAD_SPEED     100       //down load flag  speed 400kb/s
#define MAX_SPEED_LEVEL                   100          //calc weight by speed small limte
#define SYN_RTT_GOOD_LEVEL            250          //tcp rtt > 200ms
#define SYN_RTT_LEVEL                         500          //tcp rtt > 500ms
#define NETLINK_MULTI_CHANNEL       29
#define UUID_NUM                                  256
#define DEFAULT_SYN_RETRANSMIT_RTT  1000         //default retrasmit rtt = 1000ms
#define RESET_INFO_TIME                     60                 //60s
#define IS_DOWN_LOAD                         5

#define MULTI_WAN1 "wlan0"
#define MULTI_WAN2 "wlan1"
#define MULTI_WAN3 "rmnet_data0"
#define MULTI_WAN4 "eth0"

#define WIFI_1_DEFAULT_WEIGHT  2
#define LTE_1_DEFAULT_WEIGHT    1
#define WIFI_2_DEFAULT_WEIGHT  1
#define LTE_2_DEFAULT_WEIGHT    1


#define WIFI_SPEED_LEVEL_1  400          //KB/s
#define WIFI_SPEED_LEVEL_2  300
#define WIFI_SPEED_LEVEL_3  200
#define WIFI_SPEED_LEVEL_4  100

#define WIFI_WEIGHT_LEVEL_1  100          //100%
#define WIFI_WEIGHT_LEVEL_2  90
#define WIFI_WEIGHT_LEVEL_3  80
#define WIFI_WEIGHT_LEVEL_4  70
#define WIFI_WEIGHT_LEVEL_5  60
#define WIFI_WEIGHT_LEVEL_6  50
#define WIFI_WEIGHT_LEVEL_7  0

static struct timeval tv_reset_info_lasttime;

//#define MULTI_DEBUG 1
#ifdef MULTI_DEBUG
    #define MULTI_TAG                 "multi_channel_hook"
    #define MULTI_PRINT(args...) \
    do{ \
        printk(MULTI_TAG":"args); \
    }while(0)
#else
    #define MULTI_PRINT(args...) do{}while(0)
#endif

static int multi_channel_screen_state;
static int multi_channel_enable;
static unsigned int multi_weight[IF_NUM];
static struct timeval last_time;
static struct timeval tv_speed_lasttime;
static unsigned int multi_rtt[IF_NUM][3];
static struct timer_list multi_channel_timer;
static unsigned int speedtest_uid;
static struct sock *multi_channel_sock = NULL;
static char wan_dev[IF_NUM][DEV_NAME_LEA] = {MULTI_WAN1,MULTI_WAN2,MULTI_WAN3,MULTI_WAN4};

enum {
    NET_2G = 2,
    NET_3G = 3,
    NET_4G = 4,
};

enum {
    WIFI_WISP =0,
    WIFI_AP = 1,
};

enum {
    IF_DOWN =0,
    IF_UP = 1,
};


enum {
    WIFI_AUTHED = 0,
    WIFI_UNAUTHED = 1,
};

enum {
    DISABLE = 0,
    ENABLE = 1,
};

enum {
    MULTI_DROP = 0,
    MULTI_MARKED = 1,
    MULTI_ACEEPT = 2,
};

enum {
    IS_INVALID = 0,
    IS_VALID = 1,
};

enum {
    SCREEN_OFF = 0,
    SCREEN_ON = 1,
};

enum {
    SET_MULTI_CHANNEL_ENABLE=0x13,
    SET_MULTI_CHANNEL_DISABLE = 0x14,
    SET_MULTI_CHANNEL_IF_UP,
    SET_MULTI_CHANNEL_IF_DOWN,
    SET_MULTI_CHANNEL_LTE_MODE,
    SET_MULTI_CHANNEL_WIFI_MODE,
    SET_MULTI_CHANNEL_WIFI_AUTH,
    SET_MULTI_CHANNEL_WIFI_UUID,
    SET_MULTI_CHANNEL_LTE_UUID,
    SET_MULTI_CHANNEL_VALID_UUID,
    SET_MULTI_CHANNEL_WIFI_SIGNAL,
    SET_MULTI_CHANNEL_SCREEN_STATE,
};


struct inface_information{
    unsigned int if_up;
    unsigned int net_mode;
    unsigned int wifi_mode;
    unsigned int wifi_auth;
    unsigned int max_speed;
    unsigned int alive_speed;
    unsigned int avg_speed;
    unsigned int down_load;
    unsigned int rtt;
    unsigned int congestion_flag;
    unsigned long long last_bytes;
};

struct special_uid{
    int count;
    unsigned int uid[UUID_NUM];
};

static struct special_uid forbid_wifi_uuid;
static struct special_uid forbid_lte_uuid;
static struct special_uid multi_valid_uuid;
static struct inface_information if_info[IF_NUM];
extern int (*multi_calc_rtt)(struct sock *sk, struct sk_buff *skb);

DEFINE_RWLOCK(multi_channel_lock);
#define multi_read_lock()       read_lock_bh(&multi_channel_lock);
#define multi_read_unlock()     read_unlock_bh(&multi_channel_lock);
#define multi_write_lock()      write_lock_bh(&multi_channel_lock);
#define multi_write_unlock()    write_unlock_bh(&multi_channel_lock);
static unsigned int default_speed_level = 60;        //100kb/s

static int mark_speedtest_uuid_skb(unsigned int uuid,struct sk_buff *skb)
{
    static int speedtest_mark[IF_NUM-1]={0};

    if(speedtest_uid && uuid == speedtest_uid){
        if(!speedtest_mark[2] && if_info[3].if_up){
            speedtest_mark[2] = 1;
            skb->mark = 0x0400 & 0xFFFF;
        }
        else if(!speedtest_mark[1] && if_info[2].if_up){
            speedtest_mark[1] = 1;
            skb->mark = 0x0300 & 0xFFFF;
        }
        else if(!speedtest_mark[0] && if_info[1].if_up){
            speedtest_mark[0] = 1;
            skb->mark = 0x0200 & 0xFFFF;
        }
        else{
            speedtest_mark[0] = 0;
            speedtest_mark[1] = 0;
            speedtest_mark[2] = 0;
            if(if_info[0].if_up){
                skb->mark = 0x0100 & 0xFFFF;
            }
        }
        return MULTI_MARKED;
    }
    return MULTI_ACEEPT;
}

static int mark_nubia_firewall_uuid(unsigned int uuid, struct sk_buff *skb)
{
    int i = 0;
    int j = 0;
    int lte_mark;
    int ret = MULTI_ACEEPT;

    lte_mark = 0;
    multi_read_lock();
    for(i = 0; i < forbid_wifi_uuid.count; i++){
        if(forbid_wifi_uuid.uid[i]){
            if(uuid == forbid_wifi_uuid.uid[i]){
                if(if_info[LTE_INDEX].if_up){
                    skb->mark = 0x0300 & 0xFFFF;
                    lte_mark = 1;
                    ret = MULTI_MARKED;
                }
                else{
                    ret = MULTI_DROP;
                }
                break;
            }
        }
        else{
            break;
        }
    }

    for(j = 0; j < forbid_lte_uuid.count; j++){
        if(forbid_lte_uuid.uid[j]){
            if(uuid == forbid_lte_uuid.uid[j]){
                if(lte_mark || !if_info[WIFI_INDEX].if_up){
                    ret = MULTI_DROP;
                }
                else{
                    skb->mark = 0x0100 & 0xFFFF;
                    ret = MULTI_MARKED;
                }
                break;
            }
        }
        else{
            break;
        }
    }
    multi_read_unlock();

    return ret;
}

static int mark_special_uuid(unsigned int hook,struct sk_buff *skb)
{
    struct file *filp;
    unsigned int uuid;
    int ret = MULTI_ACEEPT;
    int ret1 = MULTI_ACEEPT;

    if (hook == NF_INET_LOCAL_OUT &&
        skb->sk != NULL &&
        skb->sk->sk_socket != NULL &&
        skb->sk->sk_socket->file != NULL){

        filp = skb->sk->sk_socket->file;
        uuid = filp->f_cred->fsuid.val;

        ret = mark_speedtest_uuid_skb(uuid,skb);

        ret1 = mark_nubia_firewall_uuid(uuid,skb);
        if(MULTI_DROP == ret1){
            goto multi_drop;
        }
        else if(MULTI_MARKED == ret1){
            ret = MULTI_MARKED;
        }

        if( uuid == 1000){
            skb->mark = 0x0 & 0xFFFF;
            ret = MULTI_MARKED;
        }
    }

    return ret;

multi_drop:
   nf_send_unreach(skb, ICMP_PORT_UNREACH,NF_INET_LOCAL_OUT);
    return MULTI_DROP;
}

static int is_dns_skb(struct sk_buff *skb){

    struct udphdr *udph;
    struct iphdr *iph;
    unsigned short dport;
    iph = ip_hdr(skb);
    if (iph->protocol == IPPROTO_UDP)
    {
        udph = (struct udphdr *)((char *)iph + iph->ihl*4);

#ifdef __LITTLE_ENDIAN
        dport = ntohs(udph->dest);
#else
        dport = udph->dest;
#endif
        if(dport == 53) {
            return 1;
        }
    }
    return 0;
}

static int is_valid_uuid(unsigned int hook,struct sk_buff *skb)
{
    struct file *filp;
    unsigned int uuid;
    int i = 0;

    if (hook == NF_INET_LOCAL_OUT &&
        skb->sk != NULL &&
        skb->sk->sk_socket != NULL &&
        skb->sk->sk_socket->file != NULL){

        filp = skb->sk->sk_socket->file;
	if(NULL != filp->f_cred){

           uuid = filp->f_cred->fsuid.val;
           multi_read_lock();
           for(i = 0; i < multi_valid_uuid.count; i++){
               if(uuid == multi_valid_uuid.uid[i]){
                   multi_read_unlock();
                   return IS_VALID;
               }
           }
           multi_read_unlock();
       }
    }
    return IS_INVALID;
}

static void set_syn_rtt_by_ct_mark(unsigned int ct_mark,int rtt)
{
    int i = -1;
    int j = 0;
    static int index[IF_NUM];

    if(0x0100  == ct_mark){
        i = 0;
    }
    else if(0x0200 == ct_mark){
        i = 1;
    }
    else if(0x0300 == ct_mark){
        i = 2;
    }
    else if(0x0400 == ct_mark){
        i = 3;
    }

    if(-1 != i){
        j = index[i];
        if(2 == index[i]){
            index[i] = 0;
        }
        else{
            index[i] += 1;
        }
        multi_rtt[i][j] = rtt;
    }
    return;
}

static int ct_multi_route_mark(struct nf_conn *ct)
{
    u_int32_t ct_mark = ct->mark & 0xFFFF;
    if(ct_mark == 0x0100 || ct_mark == 0x0200 ||
            ct_mark == 0x0300 || ct_mark== 0x0400){
            return 1;
    }
    return 0;
}

static int mark_retransmit_skb(unsigned int hook,struct nf_conn *ct, struct sk_buff *skb)
{
    int ret = MULTI_ACEEPT;
    u_int32_t ct_mark = ct->mark & 0xFFFF;
    if(ct_multi_route_mark(ct)){
        skb->mark = ct_mark;
        ret = MULTI_MARKED;
        set_syn_rtt_by_ct_mark(ct_mark,DEFAULT_SYN_RETRANSMIT_RTT);
    }
    return ret;
}

static unsigned int multi_channel_hook(void *priv,
                                      struct sk_buff *skb,
                                      const struct nf_hook_state *state)
{
    int ret = MULTI_ACEEPT;
    struct nf_conn *ct = NULL;
    enum ip_conntrack_info ctinfo;
    unsigned int state_mask = 0;
    unsigned int hook = state->hook;

    if(DISABLE == multi_channel_enable ||
        SCREEN_OFF == multi_channel_screen_state){
        goto OUT_DONE;
    }

    ct = nf_ct_get(skb, &ctinfo);
    if(NULL == ct){
        goto OUT_DONE;
    }

    state_mask = XT_STATE_BIT(ctinfo);
    if((state_mask & XT_STATE_BIT(IP_CT_ESTABLISHED)) ||
        (state_mask & XT_STATE_BIT(IP_CT_RELATED))){
        if(ct_multi_route_mark(ct)){
            skb->mark = ct->mark & 0xFFFF;
        }

    }else if(IP_CT_NEW == ctinfo){
        if(is_dns_skb(skb)){
            goto DNS_MARK;
        }

        if(IS_VALID == is_valid_uuid(hook,skb)){
            if(MULTI_ACEEPT == mark_retransmit_skb(hook,ct,skb)){
                ret = mark_special_uuid(hook,skb);
                if(MULTI_ACEEPT == ret){
                DNS_MARK:
                    multi_read_lock();
                    if((prandom_u32() & 0x7FFFFFFF) < (0x147ae14 * multi_weight[0])){
                        skb->mark = 0x0100 & 0xFFFF;
                    }
		    else if((prandom_u32() & 0x7FFFFFFF) < (0x147ae14 * multi_weight[2])){
                        skb->mark = 0x0300 & 0xFFFF;
                    }
                    else if((prandom_u32() & 0x7FFFFFFF) < (0x147ae14 * multi_weight[1])){
                        skb->mark = 0x0200 & 0xFFFF;
                    }
                    else if((prandom_u32() & 0x7FFFFFFF) < (0x147ae14 * multi_weight[3])){
                        skb->mark = 0x0400 & 0xFFFF;
                    }
                    multi_read_unlock();
                }
                else if(MULTI_DROP == ret){
                    return NF_DROP;
                }
            }
            ct->mark = skb->mark;
        }
    }
    else{
        goto OUT_DONE;
    }

    if(NF_INET_LOCAL_OUT == hook){
        if (ip_route_me_harder(state->net,skb, RTN_UNSPEC)){
            return NF_DROP;
        }
    }

OUT_DONE:
    return NF_ACCEPT;
}


static struct nf_hook_ops multi_channel_ops[] __read_mostly = {

    {
        .hook       = multi_channel_hook,
        .pf         = PF_INET,
        .hooknum    = NF_INET_LOCAL_OUT,
        .priority   = NF_IP_PRI_CONNTRACK + 1,
    },

};

static int calc_tcp_syn_rtt(struct sock *sk, struct sk_buff *skb)
{
    int tmp_rtt = 0;
    u_int32_t ct_mark = 0x0;
    struct nf_conn *ct = NULL;
    enum ip_conntrack_info ctinfo;
    struct tcp_sock *tp = tcp_sk(sk);
    struct inet_connection_sock *icsk = inet_csk(sk);

    if(TCP_SYN_SENT == sk->sk_state){
        ct = nf_ct_get(skb, &ctinfo);
        if(ct != NULL && !icsk->icsk_retransmits){
            tmp_rtt =  tcp_time_stamp - tp->retrans_stamp;
            if(tmp_rtt){
                ct_mark = ct->mark & 0xFFFF;
                tmp_rtt = jiffies_to_msecs(tmp_rtt);
                set_syn_rtt_by_ct_mark(ct_mark,tmp_rtt);
            }
        }
    }
    return 0;
}

static int dev_isalive(const struct net_device *dev)
{
    return dev->reg_state <= NETREG_REGISTERED;
}

static int cal_dev_speed(int spare_time)
{
    int i=0;
    unsigned int tmp_speed;
    unsigned int tmp_avg_speed;
    struct net_device *dev;
    const struct rtnl_link_stats64 *stats;
    struct rtnl_link_stats64 temp;

    for(i=0;i<IF_NUM;i++) {
         if(NET_4G == if_info[i].net_mode &&
            WIFI_AP != if_info[i].wifi_mode && if_info[i].if_up){
            dev = dev_get_by_name(&init_net, wan_dev[i]);
            if(dev) {
                 if (dev_isalive(dev) && (stats = dev_get_stats(dev, &temp))){
                    if(0 == if_info[i].last_bytes){
                        if_info[i].last_bytes = stats->rx_bytes;
                    }
                    else{
                        tmp_speed = if_info[i].avg_speed;
                        if(stats->rx_bytes < if_info[i].last_bytes){
                            if_info[i].avg_speed =(8 * stats->rx_bytes)/1024;
                        }else{
                            if_info[i].avg_speed = (8*(stats->rx_bytes - if_info[i].last_bytes))/1024;
                        }
                        if_info[i].last_bytes = stats->rx_bytes;
                        tmp_avg_speed = if_info[i].avg_speed / spare_time;
                        if_info[i].avg_speed = (tmp_avg_speed + tmp_speed)/2;

                        if(if_info[i].avg_speed >= DOWN_LOAD_SPEED_LEVEL &&
                           if_info[i].down_load < IS_DOWN_LOAD){
                             if_info[i].down_load += 1;
                        }
                        else if(if_info[i].avg_speed < BACK_DOWN_LOAD_SPEED){
                                  if_info[i].down_load = 0;
                        }

                        tmp_speed = if_info[i].avg_speed / 8;
                        if(tmp_speed > if_info[i].max_speed){
                            if_info[i].max_speed = tmp_speed;
                        }
                        else if(if_info[i].congestion_flag >= 2*CONGESTION_FLAG){
                            if(tmp_speed){
                               if_info[i].max_speed = tmp_speed;
                            }
                            else{
                               if_info[i].max_speed = if_info[i].max_speed/2;
                            }
                            if_info[i].congestion_flag =  CONGESTION_FLAG;
                        }

                        if(LTE_INDEX == i){
                           if(if_info[i].max_speed > AVG_SPEED_LEVEL){
                               if_info[i].max_speed = AVG_SPEED_LEVEL;
			   }

                           if(tmp_speed > AVG_SPEED_LEVEL){
                               tmp_speed = AVG_SPEED_LEVEL;
			   }
                        }

                        if_info[i].alive_speed = if_info[i].max_speed - tmp_speed;
                        MULTI_PRINT("func = %s,dev_name = %s ,max_speed = %u,remain_speed = %u,current speed is = %u,congestion_flag = %d,down_load = %u\n",
                                    __func__,wan_dev[i],if_info[i].max_speed,if_info[i].alive_speed,
                                    if_info[i].avg_speed,if_info[i].congestion_flag,if_info[i].down_load);
                    }
                 }
                 dev_put(dev);
              }
         }
    }

    return 0;
}

static void statistics_if_rtt(void)
{
    int j = 0;
    int rtt;

    for(j = 0;j < IF_NUM; j++){
        if(NET_4G == if_info[j].net_mode &&
                WIFI_AP != if_info[j].wifi_mode && if_info[j].if_up){

            if(multi_rtt[j][0] && multi_rtt[j][1] && multi_rtt[j][2]){

                rtt = (multi_rtt[j][0] + multi_rtt[j][1] + multi_rtt[j][2])/3;
                memset(multi_rtt[j],0x0,3*sizeof(unsigned int));
                MULTI_PRINT("func = %s,dev name = %s,rtt = %d\n",__func__,wan_dev[j],rtt);

                if(if_info[j].rtt >= SYN_RTT_LEVEL && rtt >= SYN_RTT_LEVEL){
                    if(DEFAULT_SYN_RETRANSMIT_RTT == rtt ){
                          if_info[j].congestion_flag += CONGESTION_FLAG;
                    }
                    else if(if_info[j].congestion_flag < CONGESTION_FLAG){
                         if_info[j].congestion_flag += 1;
                    }
                }
                else{
                    if(rtt < SYN_RTT_GOOD_LEVEL){
                        if_info[j].congestion_flag = 0;
                    }
                    else{
                        if(if_info[j].congestion_flag){
                            if(if_info[j].congestion_flag > CONGESTION_FLAG){
                               if_info[j].congestion_flag = CONGESTION_FLAG;
                            }
                            if_info[j].congestion_flag -= 1;
                        }
                    }
                }
                if_info[j].rtt = rtt;
            }
        }
    }
    return;
}

static int check_if_status(void)
{
    int i = 0;
    int sum_speed = if_info[WIFI_INDEX].avg_speed + if_info[LTE_INDEX].avg_speed;
    for(i = 0; i< IF_NUM; i++){
        if(WIFI_UNAUTHED == if_info[i].wifi_auth && if_info[i].if_up){
            multi_write_lock();
            memset(multi_weight,0x0,sizeof(multi_weight));
            multi_weight[i] = WIFI_WEIGHT_LEVEL_1;
            multi_write_unlock();
            MULTI_PRINT("func = %s,multi_weight[%d]= %d\n",__func__, i, multi_weight[i]);
            return 1;
        }
    }
    if(if_info[WIFI_INDEX].if_up &&
        if_info[LTE_INDEX].if_up &&
        (if_info[WIFI_INDEX].max_speed >= WIFI_SPEED_LEVEL_1 ||
        (!if_info[WIFI_INDEX].congestion_flag && sum_speed < default_speed_level ))){
        multi_write_lock();
        multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_1;
        multi_write_unlock();
        MULTI_PRINT("func = %s,wifi multi weight[%d]= %d\n",__func__, WIFI_INDEX, multi_weight[WIFI_INDEX]);
        return 1;
    }
    return 0;
}

static void calc_weight_by_wifi_speed(void){

    int wifi_speed = if_info[WIFI_INDEX].max_speed;
    multi_write_lock();
    if(if_info[WIFI_INDEX].if_up){
        if( if_info[LTE_INDEX].if_up &&
              NET_4G == if_info[LTE_INDEX].net_mode){
            if(wifi_speed >= WIFI_SPEED_LEVEL_1){
                multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_1;
            }
            else if(wifi_speed >= WIFI_SPEED_LEVEL_2){
                multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_2;
            }
            else if(wifi_speed >= WIFI_SPEED_LEVEL_3){
                multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_3;
            }
            else{
                multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_4;
            }
            multi_weight[LTE_INDEX] = WIFI_WEIGHT_LEVEL_1;
        }
        else{
            multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_1;
            multi_weight[LTE_INDEX] = WIFI_WEIGHT_LEVEL_7;
        }
    }
    else{
        multi_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_7;
        multi_weight[LTE_INDEX] = WIFI_WEIGHT_LEVEL_1;	
    }
    multi_write_unlock();
}

static void reset_info(void){

    int sum_speed = if_info[WIFI_INDEX].avg_speed + if_info[LTE_INDEX].avg_speed;
    if(sum_speed < default_speed_level){
	MULTI_PRINT("reset info\n");
        if_info[WIFI_INDEX].max_speed= 0;
        if_info[WIFI_INDEX].avg_speed = 0;
        if_info[LTE_INDEX].max_speed= 0;
        if_info[LTE_INDEX].avg_speed= 0;
        if(if_info[LTE_INDEX].congestion_flag >= CONGESTION_FLAG){
            if_info[LTE_INDEX].congestion_flag = CONGESTION_FLAG - 1;
        }
        else if(if_info[LTE_INDEX].congestion_flag > 1){
            if_info[LTE_INDEX].congestion_flag -= 1;
        }
	else{
           if_info[LTE_INDEX].congestion_flag = 0;
	}

        if(if_info[WIFI_INDEX].congestion_flag >= CONGESTION_FLAG){
            if_info[WIFI_INDEX].congestion_flag = CONGESTION_FLAG - 1;
        }
        else if(if_info[WIFI_INDEX].congestion_flag > 1){
           if_info[WIFI_INDEX].congestion_flag -= 1;
        }
	else{
          if_info[WIFI_INDEX].congestion_flag = 0;
	}
    }
}

static int calc_weight_for_wifi_lte_mode(void){
    int i = 0,j = 0;
    unsigned int sum_speed[IF_NUM] = {0};
    unsigned int tmp_weight[IF_NUM] = {0};
    unsigned int tmp_speed = 0;

    memset(tmp_weight,0x0,IF_NUM * sizeof(unsigned int));

    if(check_if_status()){
        return 0;
    }

    if( if_info[WIFI_INDEX].congestion_flag < CONGESTION_FLAG &&
        if_info[LTE_INDEX].congestion_flag < CONGESTION_FLAG &&
        IS_DOWN_LOAD != if_info[LTE_INDEX].down_load){
            calc_weight_by_wifi_speed();
            return 0;
    }

    for(j = 0;j < IF_NUM; j++){
        if(NET_4G == if_info[j].net_mode &&
            WIFI_AP != if_info[j].wifi_mode && if_info[j].if_up){
            
            for(i = j; i < IF_NUM; i++){
                if(if_info[i].if_up &&
                    NET_4G == if_info[i].net_mode &&
                    WIFI_AP != if_info[i].wifi_mode){
                    
                    tmp_speed = if_info[i].max_speed;
                    if(WIFI_INDEX == i){
                         sum_speed[j] += (2 * tmp_speed);
                    }
                    else{
                         sum_speed[j] += tmp_speed;
                    }
                }
            }

            tmp_speed = if_info[j].max_speed;
            if(sum_speed[j]){
               if(WIFI_INDEX == j) {
                   tmp_weight[j] = 2*100*tmp_speed/sum_speed[j];
               }
               else{
                  tmp_weight[j] =100 * tmp_speed/sum_speed[j];
               }
            }

        }
        else{
            if_info[j].max_speed = 0;
            if_info[j].alive_speed = 0;
            tmp_weight[j] = 0;
        }
    }

    if( if_info[WIFI_INDEX].congestion_flag &&
        if_info[WIFI_INDEX].alive_speed < DEFAULT_LEVE_SPEED &&
        NET_4G == if_info[LTE_INDEX].net_mode){
        if((if_info[WIFI_INDEX].congestion_flag >= CONGESTION_FLAG &&
	   (!if_info[LTE_INDEX].congestion_flag || if_info[WIFI_INDEX].max_speed < DEFAULT_LEVE_SPEED)) ||
            (tmp_weight[WIFI_INDEX] <= MIN_WEIGHT && if_info[LTE_INDEX].alive_speed > MAX_SPEED_LEVEL)){
            tmp_weight[WIFI_INDEX] = WIFI_WEIGHT_LEVEL_7;
            tmp_weight[LTE_INDEX] = WIFI_WEIGHT_LEVEL_1;
        }
    }

    multi_write_lock();
    memcpy(multi_weight,tmp_weight,sizeof(unsigned int) * IF_NUM);
    multi_write_unlock();

    return 0;
}

static int cal_dev_weight(void)
{
#ifdef MULTI_DEBUG
    int i = 0;
#endif
    struct timeval tv_now;
    int spare_time = 0;

    do_gettimeofday(&tv_now);
    spare_time = tv_now.tv_sec - last_time.tv_sec;

    if(spare_time >= 3){

        last_time = tv_now;

       cal_dev_speed(spare_time);

       calc_weight_for_wifi_lte_mode();

       if(tv_now.tv_sec - tv_reset_info_lasttime.tv_sec >= RESET_INFO_TIME){
           tv_reset_info_lasttime = tv_now;
           reset_info();
      }

#ifdef MULTI_DEBUG
        for(i = 0; i < IF_NUM; i++){
            MULTI_PRINT("func = %s,weight[%d] = %d\n",__func__, i,multi_weight[i]);
        }
#endif
    }
    return 0;
}

void get_timer_statistic(void)
{
    statistics_if_rtt();
    cal_dev_weight();
    return;
}


void multi_channel_timer_expire(void)
{
    get_timer_statistic();

    mod_timer(&multi_channel_timer, jiffies + K1S);
}

void multi_channel_timer_start(void)
{
    struct timeval tv_now;
    init_timer(&multi_channel_timer);
    multi_channel_timer.function = (void*)multi_channel_timer_expire;
    multi_channel_timer.expires = jiffies +  K1S;
    do_gettimeofday(&tv_now);
    last_time = tv_now;
    tv_speed_lasttime = tv_now;
    tv_reset_info_lasttime = tv_now;
    add_timer (&multi_channel_timer);
}

static int change_ifname_to_index(char  *ifname)
{
    int i = -1;
    if(!memcmp(ifname,MULTI_WAN1,strlen(MULTI_WAN1))){
        i = 0;
    }
    else if(!memcmp(ifname,MULTI_WAN2,strlen(MULTI_WAN2))){
        i = 1;
    }
    else if(!memcmp(ifname,MULTI_WAN3,strlen(MULTI_WAN3))){
        i = 2;
    }
    else if(!memcmp(ifname,MULTI_WAN4,strlen(MULTI_WAN4))){
        i = 3;
    }
    return i;
}

static void init_changed_if_info(struct inface_information *info)
{
    info->max_speed = 0;
    info->alive_speed = 0;
    info->avg_speed = 0;
    info->down_load= 0;
    info->congestion_flag = 0;
    info->rtt = 0;
    info->wifi_auth= WIFI_AUTHED;
    return;
}

static int set_multi_channel_enable(struct nlmsghdr *nlh)
{
    u_int32_t *p = NULL;
    p = (u_int32_t *)NLMSG_DATA(nlh);
    speedtest_uid = *p;
    multi_channel_enable = ENABLE;
    multi_channel_screen_state = SCREEN_ON;
    printk("fucn = %s,screen state = %u,speedtest uid = %u\n",__func__,multi_channel_screen_state,speedtest_uid);
    return 0;
}

static int set_multi_channel_screen_state(struct nlmsghdr *nlh)
{
    u_int32_t *p = NULL;
    p = (u_int32_t *)NLMSG_DATA(nlh);
    multi_channel_screen_state = *p;
    printk("fucn = %s,screen state = %u\n",__func__,multi_channel_screen_state);
    return 0;
}

static int set_multi_channel_ifup(struct nlmsghdr *nlh)
{
    char *p = NULL;
    int i = 0;

    p = NLMSG_DATA(nlh);
    printk("func = %s,ifname = %s\n",__func__,p);

    if((i = change_ifname_to_index(p)) >= 0){
        if_info[i].if_up= IF_UP;
        if(WIFI_INDEX == i){
             if_info[i].net_mode= NET_4G;
        }
    }

    return 0;
}

static int set_multi_channel_ifdown(struct nlmsghdr *nlh)
{
    char *p = NULL;
    int i = 0;

    p = NLMSG_DATA(nlh);
    printk("func = %s,ifname = %s\n",__func__,p);

    if((i = change_ifname_to_index(p)) >= 0){
        init_changed_if_info(&if_info[i]);
        if_info[i].if_up = IF_DOWN;
        if_info[i].wifi_mode= 0;
        if_info[i].net_mode= 0;
        memset(multi_rtt[i],0x0,3*sizeof(unsigned int));
    }

    return 0;
}

static int set_multi_channel_lte_mode(struct nlmsghdr *nlh)
{
    char *p = NULL;
    u_int32_t  *q = NULL;
    int i = 0;

    p = NLMSG_DATA(nlh);
    q = (u_int32_t  *)(p+DEV_NAME_LEA);
    printk("func = %s,ifname = %s,lte mode = %u\n",__func__,p,*q);
    if((i = change_ifname_to_index(p)) >= 0){
        if(if_info[i].net_mode != *q){
            if_info[i].net_mode= *q;
            init_changed_if_info(&if_info[i]);
            memset(multi_rtt[i],0x0,3*sizeof(unsigned int));
        }
    }

    return 0;
}

static int set_multi_channel_wifi_mode(struct nlmsghdr *nlh)
{
    char *p = NULL;
    u_int32_t  *q = NULL;
    int i = 0;

    p = NLMSG_DATA(nlh);
    q = (u_int32_t  *)(p+DEV_NAME_LEA);
    printk("func = %s,ifname = %s,wifi mode = %u\n",__func__,p,*q);
    if((i = change_ifname_to_index(p)) >= 0){
        if(if_info[i].wifi_mode != *q){
            if_info[i].wifi_mode= *q;
            if_info[i].net_mode= NET_4G;
            if(WIFI_AP == if_info[i].wifi_mode){
                init_changed_if_info(&if_info[i]);
                memset(multi_rtt[i],0x0,3*sizeof(unsigned int));
            }
        }
    }

    return 0;
}

static int set_multi_channel_wifi_auth(struct nlmsghdr *nlh)
{
    char *p = NULL;
    u_int32_t  *q = NULL;
    int i = 0;

    p = NLMSG_DATA(nlh);
    q = (u_int32_t  *)(p+DEV_NAME_LEA);
    printk("func = %s,ifname = %s,wifi auth state = %u\n",__func__,p,*q);
    if((i = change_ifname_to_index(p)) >= 0){
        if_info[i].wifi_auth= *q;
    }

    return 0;
}

static int set_multi_channel_uuid(struct nlmsghdr *nlh,int msg_type)
{
    char *p = NULL;
    int *q = NULL;
    int count = 0;
    q = (int *)NLMSG_DATA(nlh);
    p =(char *)NLMSG_DATA(nlh) + sizeof(int);

    count = *q;
    printk("func = %s,msy type = %u,uuid count = %d\n",__func__,msg_type,count);

    multi_write_lock();
    if(SET_MULTI_CHANNEL_WIFI_UUID == msg_type){
        memset(forbid_wifi_uuid.uid,0x0,UUID_NUM*sizeof(u_int32_t));
        forbid_wifi_uuid.count = count;
        if(count <= UUID_NUM){
            memcpy(forbid_wifi_uuid.uid,p,count*sizeof(u_int32_t));
        }
        else{
            memcpy(forbid_wifi_uuid.uid,p,UUID_NUM*sizeof(u_int32_t));
        }
    }
    else if(SET_MULTI_CHANNEL_LTE_UUID == msg_type){
        memset(forbid_lte_uuid.uid,0x0,UUID_NUM*sizeof(u_int32_t));
        forbid_lte_uuid.count = count;
        if(count <= UUID_NUM){
            memcpy(forbid_lte_uuid.uid,p,count*sizeof(u_int32_t));
        }
         else{
           memcpy(forbid_lte_uuid.uid,p,UUID_NUM*sizeof(u_int32_t));
        }
    }
    else if(SET_MULTI_CHANNEL_VALID_UUID == msg_type){
        memset(multi_valid_uuid.uid,0x0,UUID_NUM*sizeof(u_int32_t));
        multi_valid_uuid.count = count;
        if(count <= UUID_NUM){
            memcpy(multi_valid_uuid.uid,p,count*sizeof(u_int32_t));
        }
        else{
            memcpy(multi_valid_uuid.uid,p,UUID_NUM*sizeof(u_int32_t));
        }
    }
    multi_write_unlock();
    return 0;
}


static int __multi_channel_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
    int ret = 0;

    switch(nlh->nlmsg_type)
    {
        case SET_MULTI_CHANNEL_ENABLE:
            ret = set_multi_channel_enable(nlh);
            break;

        case SET_MULTI_CHANNEL_IF_UP:
            ret = set_multi_channel_ifup(nlh);
            break;

        case SET_MULTI_CHANNEL_IF_DOWN:
            ret = set_multi_channel_ifdown(nlh);
            break;

        case SET_MULTI_CHANNEL_LTE_MODE:
            ret = set_multi_channel_lte_mode(nlh);
            break;

        case SET_MULTI_CHANNEL_WIFI_MODE:
            ret = set_multi_channel_wifi_mode(nlh);
            break;

        case SET_MULTI_CHANNEL_WIFI_AUTH:
            ret = set_multi_channel_wifi_auth(nlh);
            break;

        case SET_MULTI_CHANNEL_SCREEN_STATE:
            ret = set_multi_channel_screen_state(nlh);
            break;

        case SET_MULTI_CHANNEL_WIFI_UUID:
        case SET_MULTI_CHANNEL_LTE_UUID:
        case SET_MULTI_CHANNEL_VALID_UUID:
            ret = set_multi_channel_uuid(nlh,nlh->nlmsg_type);
            break;
        default:
            break;
    }

    return ret;

}

static void multi_channel_netlink_rcv(struct sk_buff *skb)
{
    netlink_rcv_skb(skb, &__multi_channel_rcv_msg);
}


static int multi_channel_netlink_init(void)
{
    struct netlink_kernel_cfg cfg = {
        .input = multi_channel_netlink_rcv
    };

    multi_channel_sock = netlink_kernel_create(&init_net, NETLINK_MULTI_CHANNEL,&cfg);

    if (NULL == multi_channel_sock) {
        printk("Create multi_channel_sock sock failed\n");
        return -1;
    }
    return 0;
}

static void  multi_channel_netlink_exit(void)
{
    if (multi_channel_sock) {
        netlink_kernel_release(multi_channel_sock);
    }
    return;
}

static void init_if_info(void)
{
    memset(if_info,0x0,IF_NUM*sizeof(struct inface_information));
    return;
}

static void __exit multi_channel_fini(void)
{
    multi_calc_rtt = NULL;
    del_timer(&multi_channel_timer);
    multi_channel_netlink_exit();
    nf_unregister_hooks(multi_channel_ops, ARRAY_SIZE(multi_channel_ops));
}

static int __init multi_channel_init(void)
{
    memset(&forbid_wifi_uuid,0x0,sizeof(struct special_uid));
    memset(&forbid_lte_uuid,0x0,sizeof(struct special_uid));
    memset(&multi_valid_uuid,0x0,sizeof(struct special_uid));
    memset(if_info,0x0,IF_NUM*sizeof(struct inface_information));
    init_if_info();
    multi_channel_timer_start();
    nf_register_hooks(multi_channel_ops, ARRAY_SIZE(multi_channel_ops));
    multi_channel_netlink_init();
    multi_calc_rtt = calc_tcp_syn_rtt;
    return 0;
}

module_init(multi_channel_init);
module_exit(multi_channel_fini);
