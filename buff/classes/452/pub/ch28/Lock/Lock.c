#include "../Lock/Lock.h"
#include "../Lock/Atomic.h"
#include "../Lock/Error.h"

typedef struct { int val; } *LockRep;

extern Lock locknew() {			   
  LockRep r=(LockRep)malloc(sizeof *r); 
  if (!r) ERROR("malloc() failed");	   
  r->val=0;				   
  return r;				   
}

#ifdef Spin
extern void lock(Lock lck) { while (atomic_lock(lck)); }
extern void unlock(Lock lck) { atomic_unlock(lck); }
#endif

#ifdef Yield
#include <sched.h>
extern void lock(Lock lck) { while (atomic_lock(lck)) sched_yield(); }
extern void unlock(Lock lck) { atomic_unlock(lck); }
#endif

#ifdef Wait
#include "../Lock/Wait.h"
extern void lock(Lock lck) { while (atomic_lock(lck)) wait(lck); }
extern void unlock(Lock lck) { atomic_unlock(lck); wake(lck); }
#endif
