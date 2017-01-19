/*
   synchronization-part1/bad-bank-balance.c
   A multi-threaded program where a shared global variable is updated by
   multiple threads, causing a race condition.

   @author amit
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



typedef struct account account;
struct account {
	double balance;
};
account *myacct;

void *threadMain(void *);
pthread_t *tids;
int numThreads;
int count;

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
		fprintf(stderr, "Usage: %s Too many threads  specified. Defaulting to 32.\n", argv[0]);
		numThreads = 32;
	}

	myacct = (account *) malloc(sizeof(account));
	myacct->balance = 0.0;
	printf("initial balance = %lf\n", myacct->balance);


    tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
    for (i=0; i<numThreads; i++)
        pthread_create(&tids[i], NULL, threadMain, (void *) NULL);

    for (i=0; i<numThreads; i++)
        pthread_join(tids[i], NULL);

    printf("final balance = %lf\n", myacct->balance);
    exit(0);
}

void *threadMain(void *arg)
{
	int i;
	int amount;

	for (i=0; i<count; i++) {
		amount = 1;
		myacct->balance += amount;
	}
	pthread_exit(NULL);
}
