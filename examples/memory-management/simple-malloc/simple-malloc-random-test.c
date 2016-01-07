
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


struct element {
	char *ptr;
	size_t size;
};
struct element x[MAX_ITEMS];

/**
 * Initialize array of elements used in the test.
 */
void init_elements() 
{
	int i;

	for (i =0; i < MAX_ITEMS; i++) {
		x[i].ptr = NULL;
		x[i].size = 0;
	}
}
/** 
 * Run random alloc/free tests.
 */
void run_random_tests(int count) 
{
	int loc, i;
	size_t size;

	init_elements();	
	
	for (i= 0; i < count; i++) {
		loc = random() % MAX_ITEMS; // where to put in our table
		if (x[loc].ptr) {
			free(x[loc].ptr);
			if (verbosity > 0) 
				printf("freed address %p of size %lu  in x[%d]\n", x[loc].ptr, x[loc].size, loc);
			x[loc].ptr = NULL;
			x[loc].size = 0;
		} else {
			size = random() % MAX_REQUEST + 1; // how big a request
			x[loc].ptr = (char *) malloc(size*sizeof(char));
			if (x[loc].ptr == NULL) {
				perror("test-simple-malloc:");
				exit(1);
			}
			x[loc].size = size*sizeof(char);
			memset(x[loc].ptr, '1', x[loc].size);
			if (verbosity > 0)
				printf("malloced %lu bytes and stored address %p at x[%d]\n", size, x[loc].ptr, loc);
		}
		user_interaction();
	}
}


int main(int argc, char *argv[])
{
	int count;
	unsigned long int seed;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <num of tests> <random seed> [silent|terse|verbose|interactive]\n", argv[0]);
		exit(1);
	}
	count = atol(argv[1]);
	if (argc == 3) {
		seed = atol(argv[2]);
		srandom(seed);
	}
	if (argc == 4) {
		if (argv[3][0] == 's') {
			verbosity = SILENT;
		} else if (argv[3][0] == 't') {
			verbosity = TERSE;
		} else if (argv[3][0] == 'v') {
			verbosity = VERBOSE;
		} else if (argv[3][0] == 'i') {
			verbosity = INTERACTIVE;
			setvbuf(stdin, NULL, _IONBF, 0);
		}
	}
	run_random_tests(count);
	exit(0);	
}

