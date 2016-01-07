
#include <stdio.h>
#include <stdlib.h>
#include "buddy.h"


#define MAX_REQUEST 4096
#define MAX_ITEMS 100

#define SILENT 0
#define TERSE  1
#define VERBOSE  2
#define INTERACTIVE 3

int verbosity = TERSE;


static void printAndClear()
{
	printBuddyLists();
	char ch = getchar();
	system("clear");
	if (ch == 'q')
		exit(0);
}


void simpleFreeTest()
{
	char *x;
	
	// buddy_malloc one byte to make buddy system
	// split all the way down
	x = (char *) buddy_malloc(sizeof(char));
	if (x == NULL) {
		fprintf(stderr,"ERROR! Buddy system failed to allocate 1 byte.\n");
		exit(1);
	}
	if (verbosity > 0) {
		printf("Buddy system succeeding in allocating 1 byte. \n");
	}
	if (verbosity > 1) {
		printf("Buddy system lists after malloc'ing 1 byte.\n");
		printAndClear();
	}

	// buddy_free should make all the blocks merge back into one block
	buddy_free(x);
	if (verbosity > 0) {
		printf("Buddy system succeeding in free'ing 1 byte. \n");
	}
	if (verbosity > 1) {
		printf("Buddy system lists after free'ing the block .\n");
		printAndClear();
	}
}


void maxAllocationTest()
{
	void *ptr;
	size_t count;
	
	//buddy_malloc larger and larger blocks until memory is exhausted
	count = 1;
	for (;;) {
		ptr = buddy_malloc(count);
		if (ptr == NULL) {
			perror("TestBuddy");
			if (verbosity > 0) 
				printf("ERROR! buddy_malloc'd failed to allocate a block of size %lu\n", count);
			if (verbosity > 1) printAndClear();
			return;
		} else {
			if (verbosity > 0) 
				printf("buddy_malloc'd a block of size %lu\n", count);
			if (verbosity > 1) printAndClear();
		}
		count = count * 10;
	}	
}



int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s {silent|terse|verbose|interactive}\n", argv[0]);
		exit(1);
	}
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
	 
	system("clear");

	buddy_init(0);	
	if (verbosity > 0) {
		printf("Buddy system initialized.\n");
	}
	if (verbosity > 1) {
		printf("Buddy system lists after initialization.\n");
		printAndClear();
	}
	
	simpleFreeTest();
	
	maxAllocationTest();
	
	exit(0);	
}

