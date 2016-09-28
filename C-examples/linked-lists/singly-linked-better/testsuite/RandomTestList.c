#include <stdio.h>
#include <stdlib.h>
/* We can use the < > notation on Node.h and List.h
 * because we set the include directory in the Makefile */
#include <Node.h>
#include <List.h>

/*const int DEBUG = 2;*/
const int DEBUG = 0;

enum Tests {
	ADD_AT_FRONT,
	REMOVE_FRONT,
	REMOVE_NODE,
	SEARCH,
	NUM_TESTS /* if last, will give correct num */
};

void printStats(int *tests)
{
	printf(" ========================\n");
	printf(" Function #invocations\n");
	printf(" ========================\n");
	printf(" addAtFront  %d \n", tests[ADD_AT_FRONT]);
	printf(" removeFront %d \n", tests[REMOVE_FRONT]);
	printf(" removeNode  %d \n", tests[REMOVE_NODE]);
	printf(" search      %d \n", tests[SEARCH]);
	printf(" ========================\n");
}


/**
 * @brief Runs random series of tests.
 *
 * @param count The number of tests to execute.
 * @param seed The random see to use when generating tests.
 * @param size The initial size of the list we are testing.
 * @param list A pointer to the list we want to run tests on.
 */
void runRandomTests(int count, unsigned int seed, int size, struct list* list)
{
	int i, test;
	int stats[NUM_TESTS];
	struct node *node;

	/* initialize stats array */
	for(i = 0; i < NUM_TESTS; i++) {
		stats[i] = 0;
	}

	/* seed the random number generator */
	srandom(seed);

	for(i = 0; i < count; i++) {
		/* choose a random test and increment the num times we run it */
		test = (int) (NUM_TESTS * (double) rand()/RAND_MAX);
		stats[test]++;
 
		switch (test)
		{
			case ADD_AT_FRONT:
				if (DEBUG > 1) fprintf(stderr,"addAtFront\n");
				node = createNode(size++);
				addAtFront(list, node);
				break;
			case REMOVE_FRONT:
				if (DEBUG > 1) fprintf(stderr,"removeFront\n");
				node = removeFront(list);
				freeNode(node);
				break;
			case REMOVE_NODE:
				if (DEBUG > 1) fprintf(stderr,"removeNode\n");
				node = removeNode(list, search(list, i));
				freeNode(node);
				break;
			case SEARCH:
				if (DEBUG > 1) fprintf(stderr,"searchList\n");
				node = search(list, i);
				break;
			default:
				break;
		}
	}
	printStats(stats);

	if (DEBUG > 0) {
		printList(list);
	}
}

int main(int argc, char **argv)
{
	int i, size, count;
	unsigned int seed = 0;

	struct node* node;
	struct list* list;

	/* validate arguments */
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <list size> [<num tests>] [<seed>] \n",argv[0]);
		exit(1);
	}

	/* initialize list size and num tests to arg 1 */
	count = size = atoi(argv[1]);

	/* if they pass in optional num tests, use it */
	if (argc >=  3) {
		count = atoi(argv[2]);
	}

	/* if they pass in a seed for random number, use it */
	if (argc == 4) {
		seed = atoi(argv[3]);
	}

	/* initialize list with correct number of nodes */
	list = createList();
	for (i = 0; i < size; i++) {
		node = createNode(i);
		addAtFront(list, node);
	}

	/* execute tests on list */
	runRandomTests(count, seed, size, list);

	/* clean up after ourselves */
	freeList(list);

	exit(0);
}

/* vim: set tabstop=4: */
