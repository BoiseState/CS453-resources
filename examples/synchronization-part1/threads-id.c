 
/* 
 */ 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void *run(void *);
pthread_t *tids;
int numThreads = 32;

  
int main(int argc, char *argv[])
{
	int i;


	if (argc == 2) {
		numThreads = atoi(argv[1]);
	}
	tids = (pthread_t *) malloc (sizeof(pthread_t)*numThreads);

	for (i=0; i<numThreads; i++)
	{
		// why is the malloc needed?
		int *arg = (int *) malloc (sizeof(int));
		*arg = i;
    	pthread_create(&tids[i], NULL, run, (void*) arg);
	}

	for (i=0; i<numThreads; i++)
	{
    	pthread_join(tids[i], NULL);
	}
	exit(0);
}

  
void *run(void *arg) 
{
	int myid = * (int *)arg;
	printf("Thread id = %lX has index = %d\n", pthread_self(), myid);
	pthread_exit(NULL);
}
