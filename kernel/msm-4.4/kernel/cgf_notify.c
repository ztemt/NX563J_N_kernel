#include <linux/notifier.h>
#include <linux/export.h>

static ATOMIC_NOTIFIER_HEAD(cgf_notifier_list);

int cgf_register_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&cgf_notifier_list, nb);
}
EXPORT_SYMBOL(cgf_register_notifier);


int cgf_unregister_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&cgf_notifier_list, nb);
}
EXPORT_SYMBOL(cgf_unregister_notifier);


int cgf_notifier_call_chain(unsigned long val, void *v)
{
	return atomic_notifier_call_chain(&cgf_notifier_list, val, v);
}
EXPORT_SYMBOL_GPL(cgf_notifier_call_chain);
