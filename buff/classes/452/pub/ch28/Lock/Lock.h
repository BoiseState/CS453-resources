#ifndef LOCK_H
#define LOCK_H

typedef void *Lock;

extern Lock locknew();
extern void lock(Lock lck);
extern void unlock(Lock lck);

#endif
