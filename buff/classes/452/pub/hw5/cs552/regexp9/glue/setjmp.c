#include <linux/module.h>

typedef int jmp_buf;

extern int setjmp(jmp_buf env) {
  printk(KERN_ERR "%s: setjmp() called\n",DEVNAME);
  return 0;
}

extern void longjmp(jmp_buf env, int val) {
  printk(KERN_ERR "%s: longjmp() called\n",DEVNAME);
}
