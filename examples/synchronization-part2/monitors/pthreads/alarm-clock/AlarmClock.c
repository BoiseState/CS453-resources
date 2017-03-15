

#include <stdlib.h>
#include "AlarmClock.h"

static void setAlarm(AlarmClockPtr, long int);
static void tick(AlarmClockPtr);


AlarmClockPtr alarmclock_init()
{
	AlarmClockPtr alarm = (AlarmClockPtr) malloc(sizeof(AlarmClock));
	alarm->now = 0;
	alarm->setAlarm = setAlarm;
	alarm->tick = tick;
	pthread_mutex_init(&(alarm->mutex), NULL);
	pthread_cond_init(&(alarm->timeToWakeUp), NULL);
	return alarm;
}


void setAlarm(AlarmClockPtr alarm, long int period)
{
	pthread_mutex_lock(&(alarm->mutex));

	period = period + alarm->now;
	while (alarm->now < period) {
		pthread_cond_wait(&(alarm->timeToWakeUp), &(alarm->mutex));
	}
	pthread_mutex_unlock(&(alarm->mutex));
}


void tick(AlarmClockPtr alarm)
{
	pthread_mutex_lock(&(alarm->mutex));
	alarm->now++;
	pthread_cond_broadcast(&(alarm->timeToWakeUp));
	pthread_mutex_unlock(&(alarm->mutex));
}


