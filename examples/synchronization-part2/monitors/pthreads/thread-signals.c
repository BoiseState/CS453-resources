
 
/* 
 * Illustrate thread behaviors with signal handlers installed.
 * 
 * author: Amit Jain
 *
 */ 
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>

/*#define DEBUG 1*/


#define MAX_THREADS 16

typedef int BOOL;
#define TRUE 1
#define FALSE 0

pthread_t *tids;
int numThreads;
int alarmInterval;
int thread_count;
BOOL saved = FALSE;
BOOL AlarmSent = FALSE;


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

	printf("Main thread #%X\n",(unsigned int ) pthread_self());

	alarmInterval = atoi(argv[2]);
	// set for main thread
	signal(SIGALRM, sighandler);
	alarm(alarmInterval);

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

    exit(0);
}

  
void *threadMain (void *ptr)
{
	printf("Starting thread %X\n", (unsigned int) pthread_self());
	signal(SIGALRM, sighandler);
	alarm(alarmInterval);

	while (TRUE) { 
		sleep(1);
		printf("Still running thread %X\n", (unsigned int) pthread_self());
	}


	pthread_exit(NULL);
}

void savestate()
{
	fprintf(stderr, "Thread #%X: saving state.\n",(unsigned int) pthread_self());
}

void sighandler(int signo)
{
	switch (signo)
	{
		case (SIGALRM):
			signal(SIGALRM, sighandler);
			alarm(alarmInterval);
			printf("Received signal SIGALRM in thread #%X\n", (unsigned int) pthread_self());
			break;
		default:
			break;
	}

}

/* vim: set ts=4: */
