#include <linux/module.h>
#include <linux/init.h>

#include <linux/fs.h> /* for charactyer driver support */


int char_open(struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t char_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t char_write(struct  file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return length;
}

int char_close(struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

/* to hold file operations performed on this device */




struct file_operations char_file_operations = {
	.owner = THIS_MODULE,
	.open = char_open,
	.read = char_read,
	.write = char_write,
	.release = char_close,
};



/* meta info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("FH AMD");
MODULE_DESCRIPTION("hELLO WORLD FOR KERNEL");

/**
* @BREIF MODULE CALLED WHEN MODULE LOADED INTO KERNEL
*/
static int __init ModuleInit(void)
{
	printk("Hello kernelaefgasfaf!!!\n");

	/* register with the kernel, indicate we are registering a character device driver */
	register_chrdev(260/*mjajor no.*/,
					"simple_char_drv"/* name of driver*/,
					&char_file_operations/* file operations */);
	return 0;
}

/**
* @breif module called when module is removed from the kernel
*/

static void __exit ModuleExit(void)
{
	printk("Bye bye kernel\n");
	unregister_chrdev(260, "simple_char_drv");
}

module_init(ModuleInit);
module_exit(ModuleExit);