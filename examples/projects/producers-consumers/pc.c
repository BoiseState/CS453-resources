

/**
   Simulation of producers and consumers using POSIX threads.
   Operating Systems
*/
  
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include "Item.h"
#include <List.h>
#include <Node.h>

#define TRUE 1
#define FALSE 0

#define DEBUG 0


// prototypes for the producer and consumer thread's main functions.
void *producer(void *ptr);
void *consumer(void *ptr);

int poolsize;
ListPtr pool;

int num_producers; // number of producer threads
int num_consumers; // number of consumer threads

pthread_mutex_t mutex1, mutex2;
int counter1, counter2;
pthread_t *ptids; // threads ids of the producer threads
pthread_t *ctids; // threads ids of the consumer threads

int numConsumed;
int numProduced;
pthread_mutex_t numConsumed_mutex; //keeps track of number producers that are done

int maxcount; // number of items each producer creates
int sleep_interval; // in microseconds

void print_usage(int argc, char *argv[])
{
	fprintf(stderr, "Usage: %s <poolsize> <#items/producer> <#producers> <#consumers> <sleep interval(microsecs)>\n", argv[0]);
}

int main(int argc, char **argv)
{
	int i;
	int status = 0;

	if (argc != 6) {
		print_usage(argc, argv);
		exit(1);
	}
	
	poolsize = atoi(argv[1]);
	maxcount = atoi(argv[2]);
	num_producers = atoi(argv[3]);
	num_consumers = atoi(argv[4]);
	sleep_interval = atoi(argv[5]); // in microseconds
	if (sleep_interval < 1) sleep_interval = 1;

	fprintf(stderr, "%d producers %d consumers %d items %d pool size\n",
			num_producers, num_consumers, maxcount*num_producers, poolsize);
	pool = createList(compareToItem, toStringItem, freeItem, poolsize);

	
	ptids = (pthread_t *)  malloc(sizeof(pthread_t)*num_producers);
	ctids = (pthread_t *)  malloc(sizeof(pthread_t)*num_consumers);

	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);

	// start the  producers 
	counter1 = num_producers;
	for (i=0; i < num_producers; i++) {
	    status = pthread_create(&ptids[i], NULL, producer, NULL);
		if (status != 0) {
			perror("pc: producer thread create failed!");
			exit(1);
		}
	}

		
	// start the  consumers 
	numConsumed = 0;
	pthread_mutex_init(&numConsumed_mutex, NULL);
	counter2 = num_consumers;
	for (i=0; i < num_consumers; i++) {
	    status = pthread_create(&ctids[i], NULL, consumer, NULL);
		if (status != 0) {
			perror("pc: consumer thread create failed!");
			exit(1);
		}
	}
		
	
	// wait for the producers and consumers to finish
	// collect statistics
	for (i=0; i < num_producers; i++) {
	    pthread_join(ptids[i], NULL);
		if (DEBUG) printf("producer %d finished\n", i);
		if (status != 0) {
			perror("pc: thread join failed!");
			exit(1);
		}
	}
	finishUp(pool);

		
	for (i=0; i < num_consumers; i++) {
	    int status = pthread_join(ctids[i], NULL);
		if (DEBUG) printf("consumer %d finished\n", i);
		if (status != 0) {
			perror("pc: thread join failed!");
			exit(1);
		}
	}
	
	// combine and print statistics
	numProduced = maxcount * num_producers;

	fprintf(stderr, " #items produced = %d   #items consumed = %d \n", 
 									 numProduced, numConsumed);
	if (numConsumed != numProduced) {
		fprintf(stderr, " Simulation FAILED!!!\n");
	}

	freeList(pool);
	free(ptids);
	free(ctids);

	exit(0);
}




/**
   The main  function for a producer thread.
   
   @param ptr  Argument the main function for producer thread. Not used currently. 
*/

void *producer(void *ptr) 
{
	ItemPtr item;
	NodePtr node;
	int i=0;
	int choice;
	int thread_number;
	pthread_t mytid = pthread_self();

	pthread_mutex_lock(&mutex1);
		counter1--;
		thread_number = counter1;
	pthread_mutex_unlock(&mutex1);

	if (DEBUG) printf("I am producer thread %d (with thread id = %lX)\n", thread_number, mytid);

	/* now produce the items and add them to the pool */
	i = 0;
	while (i < maxcount) {
		/*simulate time taken to produce item*/
		if (sleep_interval) usleep(sleep_interval); 
		/* produce an item */
		item = createItem(i, thread_number);
		node = createNode(item);

		/* add item to the pool */
		choice = random() % 2;
		if (choice) {
			addAtFront(pool, node);
		} else {
			addAtRear(pool, node);
		}
		i++;
	}
	pthread_exit(0);
}



/**
   The main  function for a consumer thread.
   
   @param ptr  Argument the main function for producer thread. Not used currently. 
*/
void *consumer(void *ptr) 
{
	NodePtr node;
	pthread_t mytid = pthread_self();
	int thread_number;
	int choice;
	char *itemString;

	pthread_mutex_lock(&mutex2);
		counter2--;
		thread_number = counter2;
	pthread_mutex_unlock(&mutex2);

	if (DEBUG) printf("I am consumer thread %d (with thread id = %lX)\n", thread_number, mytid);

	/* now consume the items by removing them from the end of the pool and
	   displaying them */

	while (TRUE) {
	    /* remove item from the queue */
		choice = random() % 2;
		if (choice) {
			node = removeFront(pool);
		} else {
			node = removeRear(pool);
		}
		/* print item using toString method */
		if (node) {
			itemString = pool->toString(node->obj);
			/*printf("Consumer %d consumed item %s\n", thread_number, itemString);*/
			fflush(NULL);
			free(itemString);
			freeNode(node, freeItem);
			node = NULL;
			pthread_mutex_lock(&numConsumed_mutex);
			numConsumed++;
			pthread_mutex_unlock(&numConsumed_mutex);
		} else {
			if (numConsumed == num_producers*maxcount) {
					break;
			}
		}
		/*simulate time taken to consume item*/
		if (sleep_interval) usleep(sleep_interval); 
	}

	pthread_exit(0);
}
