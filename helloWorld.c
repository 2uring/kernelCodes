#include <linux/module.h>
#include <linux/init.h>

/* meta info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("FH AMD");
MODULE_DESCRIPTION("hELLO WORLD FOR KERNEL");

/**
* @BREIF MODULE CALLED WHEN MODULE LOADED INTO KERNEL
*/
static int __init ModuleInit(void)
{
	printk("Hello kernel!!!\n");
	return 0;
}

/**
* @breif module called when module is removed from the kernel
*/

static void __exit ModuleExit(void)
{
	printk("Bye bye kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);