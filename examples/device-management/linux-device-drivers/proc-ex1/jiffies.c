
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>		// for basic filesystem
#include <linux/proc_fs.h>	// for the proc filesystem
#include <linux/seq_file.h>	// for sequence files
#include <linux/jiffies.h>	// for jiffies

static struct proc_dir_entry* jif_file;

static int jif_show(struct seq_file *m, void *v)
{
     seq_printf(m, "%llu\n",
         (unsigned long long) get_jiffies_64());
     return 0;
}

static int jif_open(struct inode *inode, struct file *file)
{
    return single_open(file, jif_show, NULL);
}

static const struct file_operations jif_fops = {
     .owner	= THIS_MODULE,
     .open	= jif_open,
     .read	= seq_read,
     .llseek	= seq_lseek,
     .release	= single_release,
};

static int __init jif_init(void)
{
     jif_file = proc_create("jif", 0, NULL, &jif_fops);

     if (!jif_file) {
         return -ENOMEM;
     }

     return 0;
}

static void __exit jif_exit(void)
{
     remove_proc_entry("jif", NULL);
}

module_init(jif_init);
module_exit(jif_exit);

MODULE_LICENSE("GPL");
