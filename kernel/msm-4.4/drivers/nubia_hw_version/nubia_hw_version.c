/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/spinlock.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <nubia_hw_version.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/input.h>
#include <linux/pinctrl/consumer.h>
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
#else
#include <linux/qpnp/qpnp-adc.h>
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
#include <linux/qpnp/pin.h>
#endif

#ifdef CONFIG_NUBIA_HW_VERSION_DEBUG
static int debug_value=1;
#else
static int debug_value=0;
#endif
#define nubia_hw_version_debug(fmt, args...) do {if(debug_value==1)printk(KERN_INFO "[nubia_hw_version]"fmt, ##args);} while(0)

#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
int nubia_hw_pcb_mv = 0;
#else
uint8_t	nubia_pcb_gpio1_v = 0;
uint8_t	nubia_pcb_gpio2_v = 0;
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
uint8_t	nubia_pm_gpio1_v = 0;
uint8_t	nubia_pm_gpio2_v = 0;
#define NUBIA_PM_GPIO_PULLDOWN_10 4
#endif
uint8_t	nubia_rf_gpio1_v = 0;
uint8_t	nubia_rf_gpio2_v = 0;
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
uint8_t	nubia_config_gpio1_v = 0;
uint8_t	nubia_config_gpio2_v = 0;
#else
int nubia_hw_config_mv = 0;
static struct {
	struct platform_device *pdev;
	struct qpnp_vadc_chip *vadc_dev;
} *penv = NULL;

#endif

static uint8_t nubia_get_gpio_status(uint32_t gpio)
{
	uint8_t status = 0;

  	gpio_direction_input(gpio);
	msleep(1);
	status = gpio_get_value(gpio);
	nubia_hw_version_debug("read_gpio=%x\n", status);
	return status;
}

int nubia_gpio_ctrl1(struct platform_device *pdev)
{
	struct nubia_gpio_pinctrl_info *gpio_data;
	int rc = 0;
	
	gpio_data = dev_get_drvdata(&pdev->dev);
	if (!gpio_data)
	{
		dev_err(&pdev->dev, "Cannot get hw gpio info\n");
		return -EINVAL;
	}
	if (!gpio_data->pull_down_default) {
		pr_err("nubia hw pinctrl down state is null\n");
		return -EINVAL;
	}
    rc = pinctrl_select_state(gpio_data->pinctrl, gpio_data->pull_down_default);
	return rc;
}


int nubia_gpio_ctrl(struct platform_device *pdev)
{
	int ret = 0;
	struct nubia_gpio_pinctrl_info *gpio_data;
	
	gpio_data = devm_kzalloc(&pdev->dev,
							 sizeof(struct nubia_gpio_pinctrl_info),
							 GFP_KERNEL);
	if (!gpio_data)
			return -ENOMEM;

	gpio_data->pinctrl = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR_OR_NULL(gpio_data->pinctrl)) {
			dev_err(&pdev->dev, "Cannot get hw gpio pinctrl\n");
			ret = PTR_ERR(gpio_data->pinctrl);			
			goto err_pctrl_get;
	}
	gpio_data->pull_up_default = pinctrl_lookup_state(
									   gpio_data->pinctrl, "pull_up_default");
	if (IS_ERR_OR_NULL(gpio_data->pull_up_default)) {
			dev_err(&pdev->dev, "Cannot get hw gpio pullup pinctrl state\n");
			ret = PTR_ERR(gpio_data->pull_up_default);
			goto err_lookup_state;
	}
	
	gpio_data->pull_down_default = pinctrl_lookup_state(
									gpio_data->pinctrl, "pull_down_default");
	if (IS_ERR_OR_NULL(gpio_data->pull_down_default)) {
			dev_err(&pdev->dev, "Cannot get hw gpio pulldown pinctrl state\n");
			ret = PTR_ERR(gpio_data->pull_down_default);
			goto err_lookup_state;
	}
	
	/* Set pinctrl state to aud_sleep by default */
	ret = pinctrl_select_state(gpio_data->pinctrl,
							   gpio_data->pull_up_default);
	if (ret)
	{
			dev_err(&pdev->dev, "set hw gpio pullup state fail:\n");
	}
	
	dev_set_drvdata(&pdev->dev, gpio_data);
    return 0;
	
err_lookup_state:
	devm_pinctrl_put(gpio_data->pinctrl);
err_pctrl_get:
	devm_kfree(&pdev->dev, gpio_data);
	return ret;
}

//开始进入第一大部分-读取pcb版本部分
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
const struct hw_pcb_adc_map_str* nubia_get_pcb_table_item_by_adc(const struct hw_pcb_adc_map_str *pts, 
	   uint32_t tablesize, int input)
{
    uint32_t i = 0;
	
	if ( NULL == pts )
	{
	  return -EINVAL;
	}

	while (i < tablesize) 
	{
		if ( (pts[i].low_mv <= input) && (input <= pts[i].high_mv) ) 
			break;
		else 
			i++;
	}

	if ( i < tablesize ) 
		return &pts[i];
    else 
		return NULL;
}
#else
const struct hw_pcb_gpio_map_str* nubia_get_pcb_table_item_by_gpio(const struct hw_pcb_gpio_map_str *pts,
		uint32_t tablesize)
{
	uint32_t i = 0;
	int gpio_value_A = nubia_pcb_gpio1_v;
	int gpio_value_B = nubia_pcb_gpio2_v;

	if ( NULL == pts  )
	{
	  return NULL;
	}

	while (i < tablesize) 
	{
  	  if ( (pts[i].gpio_A == gpio_value_A) && (pts[i].gpio_B == gpio_value_B)) 
  		break;
  	  else
  		i++;
	}

	if ( i < tablesize ) 
		return &pts[i];
    else 
		return NULL;
}
#endif
//读取pcb type，给其他驱动模块使用
int nubia_get_hw_id(void)
{
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
    const struct hw_pcb_adc_map_str *pts_item;
    pts_item = nubia_get_pcb_table_item_by_adc(hw_pcb_adc_map,
					ARRAY_SIZE(hw_pcb_adc_map),
					nubia_hw_pcb_mv);
#else
	const struct hw_pcb_gpio_map_str *pts_item;
	pts_item = nubia_get_pcb_table_item_by_gpio(hw_pcb_gpio_map,
                        ARRAY_SIZE(hw_pcb_gpio_map));
#endif
    if ( NULL != pts_item){
		nubia_hw_version_debug("pcb_type=%x\n", pts_item->pcb_type);
		return pts_item->pcb_type;
	}
	else
		return HW_UNKNOW;
}
EXPORT_SYMBOL_GPL(nubia_get_hw_id);

//读取pcb版本，给其他驱动模块使用
void nubia_get_hw_pcb_version(char* result)
{
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
	const struct hw_pcb_adc_map_str *pts_item;
	pts_item = nubia_get_pcb_table_item_by_adc(hw_pcb_adc_map,
						ARRAY_SIZE(hw_pcb_adc_map),
						nubia_hw_pcb_mv);
#else
	const struct hw_pcb_gpio_map_str *pts_item;
	pts_item = nubia_get_pcb_table_item_by_gpio(hw_pcb_gpio_map,
							ARRAY_SIZE(hw_pcb_gpio_map));
#endif
	if(!result)
		return;

	if(NULL != pts_item){
	    strcpy(result,pts_item->pcb_ver); 
	 }else
	    sprintf(result, "%s","unknow");
}
EXPORT_SYMBOL_GPL(nubia_get_hw_pcb_version);

//读取pcb版本，给上层同事使用
static ssize_t nubia_hw_pcb_version_show(struct kobject *kobj,
		struct kobj_attribute *attr, char *buf)
{
    if ( NULL == buf )
	{
	  return 0;
    }
    nubia_get_hw_pcb_version(buf);
    nubia_hw_version_debug("pcb_ver=%s\n",buf);
    return sprintf(buf,"%s",buf);
}
static struct kobj_attribute pcb_version_attr=
    __ATTR(pcb_version, 0664, nubia_hw_pcb_version_show, NULL);

//读取Pcb部分结束

//开始进入第二部分-读取rf部分
const char* nubia_get_rf_band_by_gpio(const struct hw_rf_band_gpio_map_str *pts,
		uint32_t tablesize)
{
	uint32_t i = 0;
	int gpio_value_A = nubia_rf_gpio1_v;
	int gpio_value_B = nubia_rf_gpio2_v;


	if ( NULL == pts)
	{
	  return "unknow";
	}
		
	while (i < tablesize) 
	{
  	  if ( (pts[i].gpio_A == gpio_value_A) && (pts[i].gpio_B == gpio_value_B)) 
  		break;
  	  else
  		i++;
	}

	if ( i < tablesize )
		return pts[i].rf_band;
	else
		return "unknow";

}
EXPORT_SYMBOL_GPL(nubia_get_rf_band_by_gpio);

//读取射频类型给上层使用
static ssize_t nubia_hw_rf_band_show(struct kobject *kobj,
		struct kobj_attribute *attr, char *buf)
{
	const char* rf_buf;

	if ( NULL == buf )
	{
	  return 0;
    }

	rf_buf = nubia_get_rf_band_by_gpio(hw_rf_band_gpio_map,
                        ARRAY_SIZE(hw_rf_band_gpio_map));

	nubia_hw_version_debug("hw_rf_band=%s\n", rf_buf);

	return sprintf(buf,"%s",rf_buf);
}

static struct kobj_attribute hw_rf_band_attr=
    __ATTR(rf_version, 0664, nubia_hw_rf_band_show, NULL);

//读取射频频段完成

//开始读取第三大部分-软件相关的一些配置
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
const struct hw_config_gpio_map_st* nubia_get_config_table_item_by_gpio(const struct hw_config_gpio_map_st *pts,
		uint32_t tablesize)
{
	uint32_t i = 0;
	int gpio_value_A = nubia_config_gpio1_v;
	int gpio_value_B = nubia_config_gpio2_v;


	if ( NULL == pts)
	{
	  return NULL;
	}
		
	while (i < tablesize) 
	{
  	  if ( (pts[i].gpio_A == gpio_value_A) && (pts[i].gpio_B == gpio_value_B)) 
  		break;
  	  else
  		i++;
	}

	if ( i < tablesize ) 
		return &pts[i];
    else 
		return NULL;


}
#else
const struct hw_config_adc_map_st* nubia_get_config_table_item_by_adc(const struct hw_config_adc_map_st *pts, 
	   uint32_t tablesize, int input)
{
    uint32_t i = 0;
	
	if ( NULL == pts )
	{
	  return NULL;
	}

	while (i < tablesize) 
	{
		if ( (pts[i].low_mv <= input) && (input <= pts[i].high_mv) ) 
			break;
		else 
			i++;
	}
	
	if ( i < tablesize ) 
		return &pts[i];
    else 
		return NULL;

}
#endif
//读取wifi 类型
const char* nubia_get_hw_wifi(void)
{
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
	const struct hw_config_gpio_map_st *pts_item;
	pts_item = nubia_get_config_table_item_by_gpio(hw_config_gpio_map,
                        ARRAY_SIZE(hw_config_gpio_map));
#else
    const struct hw_config_adc_map_st *pts_item;
	pts_item = nubia_get_config_table_item_by_adc(hw_config_adc_map,
						ARRAY_SIZE(hw_config_adc_map),
						nubia_hw_config_mv);
#endif

	if ( NULL != pts_item){
		nubia_hw_version_debug("wifi_type=%s\n", pts_item->wifi_type);
		return pts_item->wifi_type;
	}
	else
		return "unknown";
}
EXPORT_SYMBOL_GPL(nubia_get_hw_wifi);


//读取配置标准，如高配，低配等
void nubia_get_config_standard(char* result)
{
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
	const struct hw_config_gpio_map_st *pts_item;
	pts_item = nubia_get_config_table_item_by_gpio(hw_config_gpio_map,
							ARRAY_SIZE(hw_config_gpio_map));
#else
	const struct hw_config_adc_map_st *pts_item;
	pts_item = nubia_get_config_table_item_by_adc(hw_config_adc_map,
							ARRAY_SIZE(hw_config_adc_map),
							nubia_hw_config_mv);
#endif
	
    if(!result)
		return;
	
    if(pts_item != NULL){
        strcpy(result,pts_item->config_type); 
     }else
	    sprintf(result, "%s","unknow");
}
EXPORT_SYMBOL_GPL(nubia_get_config_standard);

static ssize_t nubia_config_standard_show(struct kobject *kobj,
		struct kobj_attribute *attr, char *buf)
{
	if (NULL == buf)
	{
	  return 0;
	}
	
    nubia_get_config_standard(buf);

	nubia_hw_version_debug("config_type=%s\n", buf);

	return sprintf(buf,"%s",buf);
}

static struct kobj_attribute config_standard_attr=
    __ATTR(config_version, 0664, nubia_config_standard_show, NULL);


//调试值的读取和写入
static ssize_t debug_value_store(struct kobject *kobj,
	    struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &debug_value);
    return count;
}

static ssize_t debug_value_show(struct kobject *kobj,
	   struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d", debug_value);	
}

static struct kobj_attribute debug_value_attr=
    __ATTR(debug_value, 0664, debug_value_show, debug_value_store);


#ifdef CONFIG_NUBIA_HW_CPU_SERIAL_NUM
static uint32_t g_cpu_serial_num;

static void nubia_cpu_serial_num_init(void)
{
	/*Check the spec to get cpu serial number address on the plateform you use */
	//MSM8952  0x00058008
	//MSM8976  0x000A60A8
	//MSM8953  0x000A4128
	//MSM8998  0x00784138
#define QFPROM_CPU_SERIAL_NUM_LSB  0x00784138
#define QFPROM_CPU_SERIAL_NUM_MSB  0

	void __iomem *serial_num_addr;

	if (!request_mem_region(QFPROM_CPU_SERIAL_NUM_LSB, 4, "cpu_serial_num")) {
		printk(KERN_ERR "nubia could not request_mem_region\n");
		g_cpu_serial_num = 0;
		return;
	}

	serial_num_addr = ioremap(QFPROM_CPU_SERIAL_NUM_LSB, 4);
	if (!serial_num_addr) {
		printk(KERN_ERR
		       "nubia could not map QFPROM_CPU_SERIAL_NUM_LSB address\n");
		g_cpu_serial_num = 0;
	} else {
		g_cpu_serial_num = readl_relaxed(serial_num_addr);
		printk(KERN_ERR "nubia cpu_serial_num=0x%08X\n",
		       g_cpu_serial_num);
		iounmap(serial_num_addr);
	}
	return;
}

static uint32_t nubia_get_cpu_serial_num(void)
{
	if (g_cpu_serial_num == 0)
		nubia_cpu_serial_num_init();
	return g_cpu_serial_num;
}

static ssize_t nubia_cpu_serial_num_show(struct kobject *kobj,
					 struct kobj_attribute *attr, char *buf)
{
	uint32_t chip_num = nubia_get_cpu_serial_num();
	return sprintf(buf, "0x%08X", chip_num);
}

static struct kobj_attribute cpu_serial_num_attr =
__ATTR(chip_serial, 0664, nubia_cpu_serial_num_show, NULL);

static struct kobj_attribute cpu_serial_num_attr2 =
__ATTR(cpu_serial_num, 0664, nubia_cpu_serial_num_show, NULL);

#endif

static ssize_t nubia_wifi_config_type_show(struct kobject *kobj,
		struct kobj_attribute *attr, char *buf)
{
	const char *wifi_type;

	if (NULL == buf)
	{
	  return 0;
	}

	wifi_type = nubia_get_hw_wifi();
	nubia_hw_version_debug("wifi_type=%s\n", wifi_type);

	return sprintf(buf,"%s",wifi_type);
}


static struct kobj_attribute wifi_config_type_attr =
__ATTR(wifi_config_type, 0664, nubia_wifi_config_type_show, NULL);


static struct attribute *nubia_hw_version_attrs[] = {
    &debug_value_attr.attr,
    &pcb_version_attr.attr,
    &hw_rf_band_attr.attr,
    &config_standard_attr.attr,
#ifdef CONFIG_NUBIA_HW_CPU_SERIAL_NUM
    &cpu_serial_num_attr.attr,
    &cpu_serial_num_attr2.attr,
#endif
    &wifi_config_type_attr.attr,
    NULL,
};

static struct attribute_group nubia_hw_version_attr_group = {
    .attrs = nubia_hw_version_attrs,
};

struct kobject *hw_version_kobj;

static const struct of_device_id of_match[] = {
        { .compatible = "qcom,nubia_hw-gpio-ctrl" },
        { }
};
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
#else
static int  nubia_parse_hw_ver_gpio_dt(struct device_node *node,int* pcb_gpio1_v, int* pcb_gpio2_v)
{
	int pcb_gpio1 = 0;
	int pcb_gpio2 = 0;
	int rc = 0;	

	pcb_gpio1 = of_get_named_gpio(node, "qcom,pcb-gpio1", 0);
	if (!gpio_is_valid(pcb_gpio1)) 
	{
		nubia_hw_version_debug("TLMM pcb gpio1 not found\n");
		return -EPROBE_DEFER;
	}
	rc = gpio_request(pcb_gpio1, "NUBIA_HW_PCB_GPIO1");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d", (s32)pcb_gpio1, rc);
		rc = -ENODEV;
	}

	*pcb_gpio1_v = pcb_gpio1;

	pcb_gpio2 = of_get_named_gpio(node, "qcom,pcb-gpio2", 0);
	if (!gpio_is_valid(pcb_gpio2)) 
	{
		nubia_hw_version_debug("TLMM pcb gpio2 not found\n");
		//return -EPROBE_DEFER;
		return 0;
	}

	rc = gpio_request(pcb_gpio2, "NUBIA_HW_PCB_GPIO2");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d\n", (s32)pcb_gpio2, rc);
		rc = -ENODEV;
	}	
	*pcb_gpio2_v = pcb_gpio2;
	
	return 0;
}
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
static int  nubia_parse_hw_ver_pm_gpio_dt(struct device_node *node,int* pm_gpio1_v, int* pm_gpio2_v)
{
	int pm_gpio1 = 0;
	int pm_gpio2 = 0;
	int rc = 0;	

	pm_gpio1 = of_get_named_gpio(node, "qcom,pm-gpio1", 0);
	nubia_hw_version_debug("nubia pm gpio1=%x\n",pm_gpio1);

	if (!gpio_is_valid(pm_gpio1)) 
	{
		nubia_hw_version_debug("pm gpio1 not found\n");
		return -EPROBE_DEFER;
	} 

	rc = gpio_request(pm_gpio1, "NUBIA_HW_PM_GPIO1");
	if (rc < 0) 
	{
		printk("Failed to request PM GPIO1:%d, ERRNO:%d\n", (s32)pm_gpio1, rc);
		rc = -ENODEV;
	}
	*pm_gpio1_v = pm_gpio1;
	
	pm_gpio2 = of_get_named_gpio(node, "qcom,pm-gpio2", 0);
	nubia_hw_version_debug("nubia pm gpio2=%x\n",pm_gpio2);

	if (!gpio_is_valid(pm_gpio2)) 
	{
		nubia_hw_version_debug("pm gpio2 not found\n");
		//return -EPROBE_DEFER;
		return 0;
	} 

	rc = gpio_request(pm_gpio2, "NUBIA_HW_PM_GPIO2");
	if (rc < 0) 
	{
		printk("Failed to request PM GPIO2:%d, ERRNO:%d\n", (s32)pm_gpio2, rc);
		rc = -ENODEV;
	}
	*pm_gpio2_v = pm_gpio2;
	return 0;
}
#endif
static int  nubia_parse_hw_ver_rf_gpio_dt(struct device_node *node,int* rf_gpio1_v, int* rf_gpio2_v)
{
	int rf_gpio1 = 0;
	int rf_gpio2 = 0;
	int rc = 0;	

	rf_gpio1 = of_get_named_gpio(node, "qcom,rf-gpio1", 0);
	if (!gpio_is_valid(rf_gpio1)) 
	{
		nubia_hw_version_debug("TLMM rf gpio1 not found\n");
		return -EPROBE_DEFER;
	} 
	rf_gpio2 = of_get_named_gpio(node, "qcom,rf-gpio2", 0);
	if (!gpio_is_valid(rf_gpio2)) 
	{
		nubia_hw_version_debug("TLMM rf gpio2 not found\n");
		return -EPROBE_DEFER;
	}

	rc = gpio_request(rf_gpio1, "NUBIA_RF_PCB_GPIO1");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d", (s32)rf_gpio1, rc);
		rc = -ENODEV;
	}
	rc = gpio_request(rf_gpio2, "NUBIA_HW_RF_GPIO2");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d\n", (s32)rf_gpio2, rc);
		rc = -ENODEV;
	}
	*rf_gpio1_v = rf_gpio1;
	*rf_gpio2_v = rf_gpio2;
	return 0;
}
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
static int  nubia_parse_hw_ver_config_gpio_dt(struct device_node *node,int* config_gpio1_v, int* config_gpio2_v)
{
	int config_gpio1 = 0;
	int config_gpio2 = 0;
	int rc = 0;

	config_gpio1 = of_get_named_gpio(node, "qcom,config-gpio1", 0);
	if (!gpio_is_valid(config_gpio1)) 
	{
		nubia_hw_version_debug("TLMM config gpio1 not found\n");
		return -EPROBE_DEFER;
	}
	rc = gpio_request(config_gpio1, "NUBIA_HW_CONFIG_GPIO1");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d", (s32)config_gpio1, rc);
		rc = -ENODEV;
	}
	*config_gpio1_v = config_gpio1;
	
	config_gpio2 = of_get_named_gpio(node, "qcom,config-gpio2", 0);
	if (!gpio_is_valid(config_gpio2)) 
	{
		nubia_hw_version_debug("TLMM config gpio2 not found\n");
		//return -EPROBE_DEFER;
		return 0;
	}
	rc = gpio_request(config_gpio2, "NUBIA_HW_CONFIG_GPIO2");
	if (rc < 0) 
	{
		printk("Failed to request GPIO:%d, ERRNO:%d", (s32)config_gpio2, rc);
		rc = -ENODEV;
	}	
	*config_gpio2_v = config_gpio2;
	return 0;
}
#endif

#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
static int  nubia_parse_hw_ver_adc_dt(struct device_node *node, int* pcb_adc_channel_v)
{
	int pm_adc_channel = 0;
	int rc = 0;

	rc = of_property_read_u32(node, "qcom,pcb-pm-adc_channel", &pm_adc_channel);
	nubia_hw_version_debug("nubia pm channel=%x\n",pm_adc_channel);

	if (rc) 
	{
		nubia_hw_version_debug("invalid nubia pcb channel=%x\n",pm_adc_channel);
		return -EPROBE_DEFER;
	}
	*pcb_adc_channel_v =pm_adc_channel;
	return 0;
}
#endif
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
#else
static int  nubia_parse_hw_ver_config_adc_dt(struct device_node *node,int* config_pm_adc_channel_v)
{
	int pm_adc_channel = 0;
	int rc = 0;

	rc = of_property_read_u32(node, "qcom,config-pm-adc_channel", &pm_adc_channel);
	nubia_hw_version_debug("nubia pm channel1=%x\n",pm_adc_channel);

	if (rc) 
	{
		nubia_hw_version_debug("invalid nubia config channel1=%x\n",pm_adc_channel);
		return -EPROBE_DEFER;
	}
	*config_pm_adc_channel_v =pm_adc_channel;
	return 0;
}
#endif
#if !defined(CONFIG_NUBIA_HW_CONFIG_BY_GPIO) || defined(CONFIG_NUBIA_HW_VER_BY_ADC)
static int	nubia_parse_hw_ver_read_adc(int pm_adc_channel_v,int *result)
{
    struct qpnp_vadc_result adc_result;
	int rc = 0;

	if (penv->vadc_dev != NULL)
	{
		rc = qpnp_vadc_read(penv->vadc_dev, pm_adc_channel_v, &adc_result);
		if (rc) 
		{
			pr_err("VADC read error with %d\n", rc);
			return -EPROBE_DEFER;
		}
		nubia_hw_version_debug("nubia_adc_phy=%d\n",(int)adc_result.physical/1000);
	}
	else
	{
		nubia_hw_version_debug("not setting up nubia hw vadc\n");
		return -EPROBE_DEFER;
	}
	*result = (int)adc_result.physical/1000;
	return 0;
}
#endif
static int  nubia_hw_ver_probe(struct platform_device *pdev)
{
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
	int pcb_adc_channel = 0;
#else
	int pcb_gpio1 = 0;
	int pcb_gpio2 = 0;
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
	int pm_gpio1 = 0;
	int pm_gpio2 = 0;
#endif
	int rf_gpio1 = 0;
	int rf_gpio2 = 0;
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO	
	int config_gpio1 = 0;
	int config_gpio2 = 0;
#else
	int config_adc_channel = 0;
#endif
	int rc = 0;
	struct device_node *node = pdev->dev.of_node;
#if !defined(CONFIG_NUBIA_HW_CONFIG_BY_GPIO) || defined(CONFIG_NUBIA_HW_VER_BY_ADC)
    int adc_result;
#endif

	nubia_hw_version_debug("nubia_hw_ver_probe\n");
	if (!pdev)
	{
		printk("pdev is null\n");
		return -EPROBE_DEFER;
	}

#if !defined(CONFIG_NUBIA_HW_CONFIG_BY_GPIO) || defined(CONFIG_NUBIA_HW_VER_BY_ADC)
    penv = devm_kzalloc(&pdev->dev, sizeof(*penv), GFP_KERNEL);
	if (!penv) {
		dev_err(&pdev->dev, "cannot allocate device memory.\n");
		return -ENOMEM;
	}
	penv->pdev = pdev;
	if (!&penv->pdev->dev)
	{
		printk("pdev dev is null\n");
		return -EPROBE_DEFER;
	}
	penv->vadc_dev = qpnp_get_vadc(&penv->pdev->dev, "nubia_hw");
	if (IS_ERR(penv->vadc_dev))
	{
	  return -EPROBE_DEFER;
	}
#endif

#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
	rc = nubia_parse_hw_ver_adc_dt(node,&pcb_adc_channel);
	if (rc < 0) 
	{
		return rc;
	}
	rc = nubia_parse_hw_ver_read_adc(pcb_adc_channel,&adc_result);
	if (rc < 0) 
	{
		return rc;
	}
    nubia_hw_pcb_mv = adc_result;
#else
	rc = nubia_parse_hw_ver_gpio_dt(node,&pcb_gpio1,&pcb_gpio2);
    if (rc < 0) 
    {
		return rc;
    }
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
	rc = nubia_parse_hw_ver_pm_gpio_dt(node,&pm_gpio1,&pm_gpio2);
	if (rc < 0) 
	{
		return rc;
	}
#endif
	rc = nubia_parse_hw_ver_rf_gpio_dt(node,&rf_gpio1,&rf_gpio2);
	if (rc < 0) 
	{
		return rc;
	}
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
	rc = nubia_parse_hw_ver_config_gpio_dt(node,&config_gpio1,&config_gpio2);
	if (rc < 0) 
	{
		return rc;
	}
#else
	rc = nubia_parse_hw_ver_config_adc_dt(node,&config_adc_channel);
	if (rc < 0) 
	{
		return rc;
	}
	rc = nubia_parse_hw_ver_read_adc(config_adc_channel,&adc_result);
	if (rc < 0) 
	{
		return rc;
	}
	nubia_hw_config_mv = adc_result;
#endif

    if (nubia_gpio_ctrl(pdev))
		return -ENODEV;
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
#else
	nubia_pcb_gpio1_v = nubia_get_gpio_status(pcb_gpio1);
	nubia_pcb_gpio2_v = nubia_get_gpio_status(pcb_gpio2);
#endif
//if use pm gpio
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
    nubia_pm_gpio1_v = nubia_get_gpio_status(pm_gpio1);
	if (0 != pm_gpio2)
		nubia_pm_gpio2_v = nubia_get_gpio_status(pm_gpio2);
#endif
	nubia_rf_gpio1_v = nubia_get_gpio_status(rf_gpio1);
	nubia_rf_gpio2_v = nubia_get_gpio_status(rf_gpio2);
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
	nubia_config_gpio1_v = nubia_get_gpio_status(config_gpio1);
	nubia_config_gpio2_v = nubia_get_gpio_status(config_gpio2);
#else
#endif

    msleep(20);
    if (nubia_gpio_ctrl1(pdev))
		return -ENODEV;
#ifdef CONFIG_NUBIA_HW_VER_BY_ADC
#else
	nubia_pcb_gpio1_v += nubia_get_gpio_status(pcb_gpio1);
	nubia_pcb_gpio2_v += nubia_get_gpio_status(pcb_gpio2);		
	nubia_hw_version_debug("nubia_pcb_gpio1_v=%x,nubia_pcb_gpio2_v=%x\n",nubia_pcb_gpio1_v,nubia_pcb_gpio2_v);
#endif
#ifdef CONFIG_NUBIA_HW_GPIO_BY_PM
    rc = nubia_qpnp_pin_config(pm_gpio1,NUBIA_PM_GPIO_PULLDOWN_10);
    if (rc)
		return -ENODEV;
	nubia_pm_gpio1_v += gpio_get_value(pm_gpio1);
	
	if (0 != pm_gpio2)
	{
	    rc = nubia_qpnp_pin_config(pm_gpio2,NUBIA_PM_GPIO_PULLDOWN_10);
    	if (rc)
			return -ENODEV;
		nubia_pm_gpio2_v += gpio_get_value(pm_gpio2);	
	}
	nubia_hw_version_debug("nubia_pm_gpio1_v=%x,pm_gpio2=%x\n",nubia_pm_gpio1_v,nubia_pm_gpio2_v);
#endif
	nubia_rf_gpio1_v += nubia_get_gpio_status(rf_gpio1);
	nubia_rf_gpio2_v += nubia_get_gpio_status(rf_gpio2);
	nubia_hw_version_debug("nubia_rf_gpio1_v=%x,nubia_rf_gpio2_v=%x\n",nubia_rf_gpio1_v,nubia_rf_gpio2_v);
#ifdef CONFIG_NUBIA_HW_CONFIG_BY_GPIO
	nubia_config_gpio1_v += nubia_get_gpio_status(config_gpio1);
	nubia_config_gpio2_v += nubia_get_gpio_status(config_gpio2);
	nubia_hw_version_debug("nubia_config_gpio1_v=%x,nubia_config_gpio2_v=%x\n",nubia_config_gpio1_v,nubia_config_gpio2_v);		
#else
#endif
	return 0;
}


static int nubia_hw_ver_remove(struct platform_device *pdev)
{
        struct nubia_gpio_pinctrl_info *gpio_data;

        gpio_data = dev_get_drvdata(&pdev->dev);

        if (gpio_data && gpio_data->pinctrl)
                devm_pinctrl_put(gpio_data->pinctrl);

        devm_kfree(&pdev->dev, gpio_data);

        return 0;
}

static struct platform_driver hardware_ver_driver = {
        .probe = nubia_hw_ver_probe,
        .remove = nubia_hw_ver_remove,
        .driver = {
                .name = "nubia_hw_ver_gpio",
                .owner = THIS_MODULE,
                .of_match_table = of_match_ptr(of_match),
        },
};
int __init nubia_hw_version_init(void)
{
    int rc = 0;
    nubia_hw_version_debug("nubia_hw_version creat attributes start \n");
    platform_driver_register(&hardware_ver_driver);
	
    hw_version_kobj = kobject_create_and_add("nubia_hw_version", NULL);
    if (!hw_version_kobj)
	{
	  printk(KERN_ERR "%s: nubia_hw_version kobj create error\n", __func__);
	  return -ENOMEM;
    }

    rc = sysfs_create_group(hw_version_kobj,&nubia_hw_version_attr_group);
    if(rc)
    {
      printk(KERN_ERR "%s: failed to create nubia_hw_version group attributes\n", __func__);
    }
    nubia_hw_version_debug("nubia_hw_version creat attributes end \n");

#ifdef CONFIG_NUBIA_HW_CPU_SERIAL_NUM
    nubia_cpu_serial_num_init();
#endif

    return rc;
}

static void __exit nubia_hw_version_exit(void)
{
    sysfs_remove_group(hw_version_kobj,&nubia_hw_version_attr_group);
    kobject_put(hw_version_kobj);	
}

module_init(nubia_hw_version_init);
module_exit(nubia_hw_version_exit);

MODULE_DESCRIPTION("nubia_hw_version driver");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:nubia_hw_version" );
