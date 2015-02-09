#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "common.h"
#include "Job.h"
#include "Node.h"
#include "List.h"

const int NUM_TESTS = 7;
//const int DEBUG = 2;
const int DEBUG = 0;


/**
 * Print out stats for the random test.
 *
 * @param tests array of counters for each test type
 *
 * @return none
 */
void print_stats(int *tests)
{
    printf(" ========================\n");
    printf(" Function  #invocations\n");
    printf(" ========================\n");
    printf(" addAtFront  %d \n", tests[0]);
    printf(" addAtRear   %d \n", tests[1]);
    printf(" removeFront %d \n", tests[2]);
    printf(" removeRear  %d \n", tests[3]);
    printf(" removeNode  %d \n", tests[4]);
    printf(" reverseList %d \n", tests[5]);
    printf(" search      %d \n", tests[6]);
    printf(" ========================\n");
}


/**
 * Run random tests on the given list.
 *
 * @param count number of tests to run
 * @param seed  random seed
 * @param n     size of the list
 * @param list  pointer to the list
 *
 * @return none
 */

void runRandomTests(int count, unsigned int seed, int n, ListPtr list)
{
    int i;
    int test;
    NodePtr node;
    JobPtr job;
    int *tests;

    tests = (int *) malloc(sizeof(int) * NUM_TESTS);
    for (i = 0; i < NUM_TESTS; i++)
		tests[i] = 0;

    srandom(seed);
	for (i = 0; i < count; i++) {
		printf("\rRunning test #%d", i);
		test = (int) (NUM_TESTS * (double) rand() / RAND_MAX);
		tests[test]++;
		switch (test) {
		case 0:
			if (DEBUG > 1)
				fprintf(stderr, "addAtFront\n");
			n++;
			job = createJob(n, "some info");
			node = createNode(job);
			addAtFront(list, node);
			break;
		case 1:
			if (DEBUG > 1)
				fprintf(stderr, "addAtRear\n");
			n++;
			job = createJob(n, "some info");
			node = createNode(job);
			addAtRear(list, node);
			break;
		case 2:
			if (DEBUG > 1)
				fprintf(stderr, "removeFront\n");
			node = removeFront(list);
			freeNode(node);
			break;
		case 3:
			if (DEBUG > 1)
				fprintf(stderr, "removeRear\n");
			node = removeRear(list);
			freeNode(node);
			break;
		case 4:
			if (DEBUG > 1)
				fprintf(stderr, "removeNode\n");
			node = removeNode(list, search(list, i));
			freeNode(node);
			break;
		case 5:
			if (DEBUG > 1)
				fprintf(stderr, "reverseList\n");
			reverseList(list);
			break;
		case 6:
			if (DEBUG > 1)
				fprintf(stderr, "searchList\n");
			node = search(list, i);
			break;
		default:
			break;
		}
	}
	printf("\n");
	print_stats(tests);
	free(tests);
}


int main(int argc, char **argv)
{
	int i;
	int n;
	int count;
	unsigned int seed = 0;

	NodePtr node;
	JobPtr job;
	ListPtr list;

	if (argc < 2) {
		fprintf(stderr,
				"Usage: %s <list size> [<test size=list size>] [<seed>] \n",
				argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);
	count = n;
	if (argc >= 3) {
		count = atoi(argv[2]);
	}
	if (argc == 4) {
		seed = (unsigned int) atoi(argv[3]);
	}

	list = createList();
	for (i = 0; i < n; i++) {
		job = createJob(i, "args");
		node = createNode(job);
		/*printf("job ptr = %p node ptr = %p\n", job, node); */
		addAtFront(list, node);
	}

	runRandomTests(count, seed, n, list);
	if (DEBUG > 0)
		printList(list);

	freeList(list);
	return 0;
}
