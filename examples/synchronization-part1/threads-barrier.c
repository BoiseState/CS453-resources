
 
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
#include <signal.h>

#define DEBUG 1


#define MAX_THREADS 16

pthread_t *tids;
pthread_barrier_t barrier;
int numThreads;

void *threadMain (void *);

int main(int argc, char **argv)
{
	int i;

    if (argc != 2) {
		fprintf(stderr,"Usage: %s <numThreads> \n", argv[0]);
		exit(1);
	}		
	
	numThreads = atoi(argv[1]);
	if (numThreads > MAX_THREADS) {
		fprintf(stderr,"Error: %s: max. number of threads %d\n",argv[0], MAX_THREADS);
		exit(1);
	}	

	pthread_barrier_init(&barrier, NULL, numThreads);
	tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
	for (i = 0; i < numThreads; i++)
	{
		pthread_create(&tids[i], NULL, threadMain, (void *) NULL);
	}

	for (i=1; i<numThreads; i++)
	{
		pthread_join(tids[i], NULL);
	}
	pthread_barrier_destroy(&barrier);
	
    exit(0);
}

  
void *threadMain (void *ptr)
{
	int result;

	printf("Starting thread #%lX\n",pthread_self());

	result = pthread_barrier_wait(&barrier);
	if (result == PTHREAD_BARRIER_SERIAL_THREAD) {
			printf("Thread %lX gets to save state after the barrier\n", pthread_self());
	} else {
			printf("Thread %lX does nothing after the barrier\n", pthread_self());
	}
	pthread_exit(NULL);
}



/* vim: set ts=4: */
