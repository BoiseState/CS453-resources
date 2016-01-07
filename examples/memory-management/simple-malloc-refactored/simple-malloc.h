
#ifndef __SIMPLE_MALLOC_H
#define __SIMPLE_MALLOC_H

/*
 * Slightly modified version from K&R Section 8.7 
 */

#include <unistd.h>
#include <stdlib.h>

#define MINIMUM_NUMBER_OF_UNITS 1024
#define NO_MEMORY_LEFT NULL

typedef double Align; /* for alignment to long boundary */

union header {
	struct {
		union header *next_free_block;
		unsigned size;
	} metadata;
	Align alignment_value;
};

typedef union header Header;

void *simple_malloc(unsigned number_of_requested_bytes);
void simple_free(void *ap);
void print_free_list();


#endif
