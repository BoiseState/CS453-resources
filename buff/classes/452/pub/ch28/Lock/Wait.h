#ifndef WAIT_H
#define WAIT_H

#include "../Lock/Lock.h"

extern void wait(Lock lck);
extern void wake(Lock lck);
extern void wakeall(Lock lck);

#endif
