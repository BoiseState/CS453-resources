/*
 * example.c -- a example example with a memory leak!
 *
 */
#include <linux/module.h> /* all drivers need this */
#include <linux/version.h> /* all drivers need this */
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* for kmalloc() and kfree() */
#include <linux/fs.h>     /* most drivers need this... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/init.h>  /* for module_init and module_exit */
#include <linux/uaccess.h>  /* for __copy_to_user and __copy_from_user */
#include "example.h"        /* local definitions */

static int example_major =   EXAMPLE_MAJOR;
module_param(example_major, int, 0);
static int example_nr_devs = EXAMPLE_NR_DEVS;    /* number of bare example devices */
module_param(example_nr_devs, int, 0);

MODULE_AUTHOR("Amit Jain");
MODULE_LICENSE("GPL v2");

static struct Example_Device *example_device;

static ssize_t example_read (struct file *, char *, size_t , loff_t *);
static ssize_t example_write (struct file *, const char *, size_t , loff_t *);
static int example_open (struct inode *, struct file *);
static int example_release (struct inode *, struct file *);

/* The different file operations */
/* Note that the tagged initialization of a structure is part ANSI C'99 standard
 * but is not part of ANSI C'89.
 */
static struct file_operations example_fops = {
    .llseek =     NULL,
    .read =       example_read,
    .write =      example_write,
    .unlocked_ioctl =      NULL,
    .open =       example_open,
    .release =    example_release,
};


/*
 * Open and close
 */
static int example_open (struct inode *inode, struct file *filp)
{
    int num = NUM(inode->i_rdev);

    if (num >= example_nr_devs) return -ENODEV;
	example_device->minor = num;
	printk("<1> /dev/example%d opened\n", num);

    filp->f_op = &example_fops;

	try_module_get(THIS_MODULE);
    return 0;          /* success */
}

static int example_release (struct inode *inode, struct file *filp)
{
	printk("<1> /dev/example%d released\n", example_device->minor);
	module_put(THIS_MODULE);
    return (0);
}

/*
 * example_read: 
 */
static ssize_t example_read (struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	int result;
	int i;
	int status;

	printk("<1>example_read invoked.\n");
	example_device->data = (char *) kmalloc(sizeof(char)*count, GFP_KERNEL);
	if (!example_device->data) {
        result = -ENOMEM;
        goto fail_malloc;
    }
	printk("<1>example_read malloced a data buffer of size %ld.\n", count);

	for (i=0; i<count; i++)
		example_device->data[i] = '1';
	
	/* This copies the data to the user space buffer buf. Don't ever use
	   memcpy or assign values to user space buffers...always use the
	   functions: __copy_to_user, __copy_from_user, put_user, get_user.
	   These functions check if the user space address is swapped out or not
	   and take the appropriate actions. If you assign something to user space
	   and the user space program is swapped out, the kernel will suffer horribly. 
	*/

	status = __copy_to_user(buf, example_device->data, count);
	if (status > 0) {
		printk("example: Could not copy %d bytes\n", status);
	}

	/* memory leak in kernel space causes memory to be lost until reboot! */
	/* memory leak if we comment the following kfree */
	if (example_device->data)
		kfree(example_device->data);

    return count;
fail_malloc:
	return result;
}

static ssize_t example_write (struct file *filp, const char *buf, size_t count , loff_t *f_pos)
{
	printk("<1>example_write invoked.\n");
	return count; // pretend that count bytes were written, similar to /dev/null
}



static int __init example_init(void)
{
    int result;

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_chrdev(example_major, "example", &example_fops);
    if (result < 0) {
        printk(KERN_WARNING "example: can't get major %d\n",example_major);
        return result;
    }
    if (example_major == 0) example_major = result; /* dynamic */
	printk("<1> example device driver version 2:  loaded at major number %d\n", example_major);

	example_device = (struct Example_Device *) kmalloc(sizeof(struct Example_Device), GFP_KERNEL); 
	if (!example_device) {
        result = -ENOMEM;
        goto fail_malloc;
    }
	return 0;

fail_malloc:
    unregister_chrdev(example_major, "example");
	return result;
		
}

static void __exit example_exit(void)
{
    unregister_chrdev(example_major, "example");
	kfree(example_device);
	printk("<1> example device driver version 2: unloaded\n");
}

module_init(example_init);
module_exit(example_exit);


/* vim: set ts=4: */
