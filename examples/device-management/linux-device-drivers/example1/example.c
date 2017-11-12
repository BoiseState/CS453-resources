/*
 * example.c -- the example char module
 *
 *********/

#include <linux/version.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* for file_operations... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/init.h>  /* for module_init and module_exit */
#include "example.h"        /* local definitions */

static int example_major =   EXAMPLE_MAJOR;
module_param(example_major,int, 0);
static int example_nr_devs = EXAMPLE_NR_DEVS;    /* number of bare example devices */
module_param(example_nr_devs, int, 0);

MODULE_AUTHOR("Amit Jain");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Simple Example Module");
MODULE_SUPPORTED_DEVICE("example");



static ssize_t example_read (struct file *, char *, size_t , loff_t *);
static ssize_t example_write (struct file *, const char *, size_t , loff_t *);
static int example_open (struct inode *, struct file *);
static int example_release (struct inode *, struct file *);

/* The different file operations */
/* Note that the tagged initialization of a structure is part ANSI C'99 standard
 * but is not part of ANSI C'89.
 */
static struct file_operations example_fops = {
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

    printk("<1> example device opened\n");

    filp->f_op = &example_fops;

	/* increment module usage count */
	try_module_get(THIS_MODULE);

    return 0;          /* success */
}

static int example_release (struct inode *inode, struct file *filp)
{
	module_put(THIS_MODULE);
    printk("<1> example device closed\n");
    return (0);
}

/*
 * Data management: read and write
 */

static ssize_t example_read (struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    long long counter = 8000000000LL;
    printk("<1>example_read invoked. %lld\n", counter);
    return 0;
}

static ssize_t example_write (struct file *filp, const char *buf, size_t count , loff_t *f_pos)
{
    printk("<1>example_write invoked.\n");
    return count; // pretend that count bytes were written
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


    printk("<1> example device driver version 1: loaded at major number %d\n", example_major);
    return 0;

}

static void __exit example_exit(void)
{
    unregister_chrdev(example_major, "example");
    printk("<1> example device driver version 1:  unloaded\n");

}

module_init(example_init);
module_exit(example_exit);

