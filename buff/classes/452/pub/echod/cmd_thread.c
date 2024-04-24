#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cmd_single.h"
#include "cmd_thread.h"
#include "error.h"

static void *thread_func(void *a) {
  cmd_single((FPP *)a);
  return 0;
}

extern void cmd_thread(FPP *fpp) {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  pthread_t thread;
  sigset_t set;
  sigset_t old;
  sigfillset(&set);
  pthread_sigmask(SIG_BLOCK,&set,&old);
  if (pthread_create(&thread,&attr,thread_func,fpp))
    ERROR("cmd_thread(): pthread_create() failed: %s",strerror(errno));
  pthread_sigmask(SIG_SETMASK,&old,0);
  pthread_attr_destroy(&attr);
}
