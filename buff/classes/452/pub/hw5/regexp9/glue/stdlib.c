#include <linux/module.h>

extern void *malloc(int size) {
  return kmalloc(size,GFP_KERNEL);
}

extern void free(void *ptr) {
  kfree(ptr);
}

extern void *realloc(void *ptr, int size) {
  void *p=malloc(size);
  if (!p)
    return 0;
  memcpy(p,ptr,size);
  free(ptr);
  return p;
}

extern void exit(int status) {
  printk(KERN_ERR "%s: exit() called\n",DEVNAME);
}
