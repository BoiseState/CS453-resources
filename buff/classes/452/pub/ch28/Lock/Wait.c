#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <linux/futex.h>
#include <sys/time.h>
#include <sys/syscall.h>

#include "../Lock/Wait.h"
#include "../Lock/Error.h"

static int futex(int *f, int op, int val) {
  return syscall(SYS_futex,f,op,val,0,0,0);
}

extern void wait(Lock lck) {
  if (futex((int *)lck,FUTEX_WAIT,1)==-1 && errno!=EAGAIN)
    ERROR(strerror(errno));
}

static void wake_n(Lock lck, int n) {
  if (futex((int *)lck,FUTEX_WAKE,n)==-1)
    ERROR(strerror(errno));
}

extern void    wake(Lock lck) { wake_n(lck,1); }
extern void wakeall(Lock lck) { wake_n(lck,INT_MAX); }

