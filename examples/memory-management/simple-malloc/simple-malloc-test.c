
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple-malloc.h"

#define malloc simple_malloc
#define free simple_free

#define MAX_REQUEST 2048
#define MAX_ITEMS 100

#define SILENT 0
#define TERSE  1
#define VERBOSE  2
#define INTERACTIVE 3
#define STATS

int verbosity = VERBOSE;

/**
 * Print malloc free list and query user to continue or not.
 */
void user_interaction() {
    if (verbosity > 1) print_free_list();
    if (verbosity == INTERACTIVE) {
        char ch = getchar();
        system("clear");
        if (ch == 'q')
            exit(0); 
    }   
}


/**
 * Do a series of allocs/frees to see behavior of malloc.
 */
void simpleTest() {
	const int NUM_ALLOCS = 6;
	int *x[NUM_ALLOCS];
	unsigned int size[] = {1, 10, 100, 1000, 2000, 2000};
	int i;

	for (i = 0; i < NUM_ALLOCS; i++) {
		user_interaction();
		x[i] = (int *) malloc(sizeof(int)*size[i]);
		printf("requested %lu bytes for %u int\n", sizeof(int)*size[i], size[i]);
		if (x[i] == NULL) {
			perror("test-simple-malloc:");
			exit(1);
		}
		user_interaction();
	}

	/* try reversing the order of frees! */
	/*for (i = NUM_ALLOCS-1; i > 0; i--) {*/
	for (i = 0; i < NUM_ALLOCS; i++) {
		printf("freeing %lu bytes\n", sizeof(int)*size[i]);
		free(x[i]);
		user_interaction();
	}

}

/**
 * Allocate a 10x20 array dynamically and then free it to watch
 * how malloc data structures behave.
 */
void arrayTest()
{
	int i;
	int **x;
	
	/* allocate a 10x20 array dynamically */
	user_interaction();
	x = (int **) malloc(sizeof(int *) * 10);
	for (i=0; i<10; i++) {
		x[i] = (int *) malloc(sizeof(int) * 20);
		user_interaction();
	}
	user_interaction();

	for (i=0; i<10; i++) {
		free(x[i]);
		user_interaction();
	}
	free(x);
	user_interaction();
}


int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [silent|terse|verbose|interactive]\n", argv[0]);
		exit(1);
	}
	if (argc == 2) {
		if (argv[1][0] == 's') {
			verbosity = SILENT;
		} else if (argv[1][0] == 't') {
			verbosity = TERSE;
		} else if (argv[1][0] == 'v') {
			verbosity = VERBOSE;
		} else if (argv[1][0] == 'i') {
			verbosity = INTERACTIVE;
			setvbuf(stdin, NULL, _IONBF, 0);
		}
	}
	
	simpleTest();

	user_interaction();

	/*arrayTest();*/
	exit(0);	
}

