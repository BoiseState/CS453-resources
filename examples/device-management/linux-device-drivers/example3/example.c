/* 
   This example shows how to create an example /proc entry. This
   can be useful in debugging as well as giving feedback to users 
   of your driver.
*/

/*
 * example.c -- the bare example char module
 *
 *********/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h> /* printk() */
#include <linux/init.h>  /*  for module_init and module_cleanup */
#include <linux/slab.h>  /*  for kmalloc/kfree */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/proc_fs.h>	/* for the proc filesystem */
#include <linux/seq_file.h>
#include "example.h"        /* local definitions */

static int example_major =   EXAMPLE_MAJOR;
static int example_nr_devs = EXAMPLE_NR_DEVS;    /* number of bare example devices */
module_param(example_major, int, 0);
module_param(example_nr_devs, int, 0);
MODULE_AUTHOR("Amit Jain");
MODULE_LICENSE("GPL v2");

static example_stats *example_device_stats;

static ssize_t example_read (struct file *, char *, size_t , loff_t *);
static ssize_t example_write (struct file *, const char *, size_t , loff_t *);
static int example_open (struct inode *, struct file *);
static int example_release (struct inode *, struct file *);


/* The different file operations */
/* Note that the tagged initialization of a structure is not ANSI C but an
 * extension provided by the GNU C compiler gcc. 
 */
static struct file_operations example_fops = {
    .llseek =     NULL,
    .read =       example_read,
    .write =      example_write,
    .unlocked_ioctl =      NULL,
    .open =       example_open,
    .release =    example_release,
};

static struct proc_dir_entry* example_proc_file;



/*
 * Open and close
 */
static int example_open (struct inode *inode, struct file *filp)
{
    int num = NUM(inode->i_rdev);

    if (num >= example_nr_devs) return -ENODEV;

    filp->f_op = &example_fops;

	/* need to protect this with a semaphore if multiple processes
	   will invoke this driver to prevent a race condition */
    example_device_stats->num_open++; 

	try_module_get(THIS_MODULE);
    return 0;          /* success */
}

static int example_release (struct inode *inode, struct file *filp)
{
	/* need to protect this with a semaphore if multiple processes
	   will invoke this driver to prevent a race condition */
	example_device_stats->num_close++; 
	module_put(THIS_MODULE);
    return (0);
}

/*
 * Data management: read and write
 */

static ssize_t example_read (struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	printk("<1>example_read invoked.\n");
	/* need to protect this with a semaphore if multiple processes
	   will invoke this driver to prevent a race condition */
	example_device_stats->num_read++; 
    return 0;
}

static ssize_t example_write (struct file *filp, const char *buf, size_t count , loff_t *f_pos)
{
	printk("<1>example_write invoked.\n");
	/* need to protect this with a semaphore if multiple processes
	   will invoke this driver to prevent a race condition */
	example_device_stats->num_write++; 
	return count; // pretend that count bytes were written
}

static void init_example_device_stats(void)
{
	example_device_stats->num_read=0;
	example_device_stats->num_write=0;
	example_device_stats->num_open=0;
	example_device_stats->num_close=0;
}

static int example_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "open = %ld times\n", example_device_stats->num_open);
	seq_printf(m, "close = %ld times\n", example_device_stats->num_close);
	seq_printf(m, "read = %ld times\n", example_device_stats->num_read);
	seq_printf(m, "write = %ld times\n", example_device_stats->num_write);
    return 0;
}


static int example_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, example_proc_show, NULL);
}

static const struct file_operations example_proc_fops = {
     .owner	= THIS_MODULE,
     .open	= example_proc_open,
     .read	= seq_read,
     .llseek	= seq_lseek,
     .release	= single_release,
};

static __init int example_init(void)
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
	printk("<1> example device driver version 3: loaded at major number %d\n", example_major);


	example_device_stats = (example_stats *) kmalloc(sizeof(example_stats),GFP_KERNEL);
	if (!example_device_stats) {
          result = -ENOMEM;
          goto fail_malloc;
	}
	init_example_device_stats();

	/* We assume that the /proc/driver exists. Otherwise we need to use proc_mkdir to
	 * create it as follows: proc_mkdir("driver", NULL);
	 */
	example_proc_file = proc_create("driver/example", 0, NULL, &example_proc_fops); 
	if (!example_proc_file)  {
          result = -ENOMEM;
          goto fail_malloc;
	}
							
	return 0;
	
	fail_malloc:
    	unregister_chrdev(example_major, "example");
		remove_proc_entry("driver/example", NULL /* parent dir */);
		return  result;
}


static __exit  void example_cleanup(void)
{
	remove_proc_entry("driver/example", NULL /* parent dir */);
	kfree(example_device_stats);
    unregister_chrdev(example_major, "example");
	printk("<1> example device driver version 3:  unloaded\n");
}


module_init(example_init);
module_exit(example_cleanup);

