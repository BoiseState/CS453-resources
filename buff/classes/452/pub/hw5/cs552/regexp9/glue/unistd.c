#include <linux/module.h>

extern int write(int fd, const void *buf, int count) {
  printk(KERN_ERR "%s: write() called\n",DEVNAME);
  return 0;
}

