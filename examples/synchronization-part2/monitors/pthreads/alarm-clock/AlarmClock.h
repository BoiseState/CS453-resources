
#ifndef __ALARMCLOCK_H
#define  __ALARMCLOCK_H

#include <pthread.h>

typedef struct alarmclock AlarmClock;
typedef struct alarmclock * AlarmClockPtr;

struct alarmclock {
	long int now;
	pthread_mutex_t mutex;
	pthread_cond_t timeToWakeUp;
	void (*setAlarm) (AlarmClockPtr, long int);
	void (*tick) (AlarmClockPtr);
};

AlarmClockPtr alarmclock_init();

#endif /*  __ALARMCLOCK_H */

/* vim: set ts=4: */
