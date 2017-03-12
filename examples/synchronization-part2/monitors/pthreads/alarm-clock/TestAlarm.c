
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "AlarmClock.h"

void *threadMain(void *);
pthread_t *tids;

AlarmClockPtr alarmClock;

int numThreads;
int count;

pthread_mutex_t mutex;

void signalHandler(int);

int main(int argc, char **argv)
{
	int i;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <numThreads> <iterations>\n", argv[0]);
		exit(1);
	}

	numThreads  = atoi(argv[1]);
	count = atoi(argv[2]);
	if (numThreads > 32) {
		fprintf(stderr, "Usage: %s Too many threads specified. Defaulting to 32.\n", argv[0]);
		numThreads = 32;
	}

	alarmClock = alarmclock_init();
	signal(SIGALRM, signalHandler);
	alarm(1);


	pthread_mutex_init(&mutex, NULL);
    tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
    for (i=0; i<numThreads; i++) {
        pthread_create(&tids[i], NULL, threadMain, (void *) NULL);
	}

    for (i=0; i<numThreads; i++)
        pthread_join(tids[i], NULL);

    pthread_mutex_destroy(&mutex);
    exit(0);
}


static int get_my_index()
{
    int i;
    pthread_mutex_lock(&mutex);
    for (i=0; i<numThreads; i++)
    {
        if (tids[i] == pthread_self())
        {
            pthread_mutex_unlock(&mutex);
            return i;
        }
    }
    pthread_mutex_unlock(&mutex);
    return -1; /* we have a problem if we reach this statement */
}


void *threadMain(void *arg)
{
	int i;
	int period;
	time_t current;
	int id = get_my_index();

	for (i=0; i<count; i++) {
		period = random() % 4 + 1; // 1 to 4 seconds 
		time(&current);
		printf("Thread %d going to set up %d seconds alarm at %s", id, period, ctime(&current));
		(*alarmClock->setAlarm)(alarmClock, period);
		/*alarmClock->setAlarm(alarmClock, period);*/
		time(&current);
		printf("Thread %d waking up from %d seconds alarm at %s", id, period, ctime(&current));
	}

	pthread_exit(NULL);
}


void signalHandler(int signo)
{
	alarmClock->tick(alarmClock);
	alarm(1); //reset alarm
}
