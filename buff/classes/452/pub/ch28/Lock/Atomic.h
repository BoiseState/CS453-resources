#ifndef ATOMIC_H
#define ATOMIC_H

extern int atomic_lock(int *lck);
extern void atomic_unlock(int *lck);
extern int atomic_test(int *lck);

#endif
