
/*
   synchronization-part1/safe-bank-balance.c
   Uses Pthread Mutexes (binary semaphores) to protect the bank balance
   variable. This isn't very good coding style. For a better way to code
   this see ch9/monitors/account folder.

   @author amit
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


typedef struct account account;
struct account {
	double balance;
	pthread_mutex_t mutex;
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
	pthread_mutex_init(&(myacct->mutex), NULL);
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
		pthread_mutex_lock(&(myacct->mutex));
		myacct->balance += amount;
		pthread_mutex_unlock(&(myacct->mutex));
	}
	pthread_exit(NULL);
}
