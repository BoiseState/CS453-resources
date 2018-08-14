
 
/* 
 * A simple example of setting up a checkpoint for a multi-threaded program using semaphores.
 * 
 * Author: Amit Jain
 *
 */ 
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

#define DEBUG  0


#define MAX_THREADS 16

typedef int BOOLEAN;
#define TRUE 1
#define FALSE 0

pthread_t *tids;
int numThreads;
int alarmInterval;
int thread_count;
BOOLEAN saved = FALSE;

sem_t mutex1;
sem_t mutex2;
sem_t mutex3;

void sighandler(int signo);

void *threadMain(void *);

int main(int argc, char **argv)
{
	int i;

    if (argc != 3) {
		fprintf(stderr,"Usage: %s <numThreads> <alarmInterval> \n", argv[0]);
		exit(1);
	}		
	
	numThreads = atoi(argv[1]);
	numThreads++; /* to account for the main thread */
	if (numThreads > MAX_THREADS) {
		fprintf(stderr,"Error: %s: max. number of threads %d\n",argv[0], MAX_THREADS);
		exit(1);
	}	


	alarmInterval = atoi(argv[2]);

	printf("Main thread #%lX\n",pthread_self());
	signal(SIGALRM, sighandler);
	alarm(alarmInterval);

	sem_init(&mutex1, 0, 1);
	sem_init(&mutex2, 0, 1);
	sem_init(&mutex3, 0, 1);


	thread_count = numThreads;

	tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
	tids[0] = pthread_self(); /* the main thread */
	for (i=1; i<numThreads; i++)
	{
		pthread_create(&tids[i], NULL, threadMain, (void *) NULL);
	}

	for (i=1; i<numThreads; i++)
	{
		pthread_join(tids[i], NULL);
	}

	sem_destroy(&mutex1);
	sem_destroy(&mutex2);
	sem_destroy(&mutex3);
	
    exit(0);
}

  
void *threadMain (void *ptr)
{
	printf("Starting thread #%lX\n",pthread_self());
	signal(SIGALRM, sighandler);
	alarm(alarmInterval);
	while (TRUE) { pause();}
	pthread_exit(NULL);
}

void savestate(void)
{
	fprintf(stderr, "Thread #%lX: saving state.\n",pthread_self());
}

void sighandler(int signo)
{
	signal(SIGALRM, sighandler);
	alarm(alarmInterval);
	printf("Received signal %d in thread #%lX\n",signo, pthread_self());


	if (signo == SIGALRM)
	{
		sem_wait(&mutex1);
			if (DEBUG) printf("thread %lX in critical section 1 \n",pthread_self());
			thread_count--;
		sem_post(&mutex1);

		sem_wait(&mutex2);
			if (DEBUG) printf("thread %lX in critical section 2 \n",pthread_self());
			if (!saved)
			{
				while (thread_count != 0) usleep(10);
				savestate();
				saved = TRUE;
			}
			thread_count++;
		sem_post(&mutex2);

		sem_wait(&mutex3);
			if (DEBUG) printf("thread %lX in critical section 3 \n",pthread_self());
			if (saved)
			{
				while (thread_count != numThreads) usleep(10);
				saved = FALSE;
			}
		sem_post(&mutex3);
	}
}

/* vim: set ts=4: */
