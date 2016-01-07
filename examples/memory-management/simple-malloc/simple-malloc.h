
#ifndef __SIMPLE_MALLOC_H
#define __SIMPLE_MALLOC_H

/*
 * Slightly modified version from K&R Section 8.7 
 */

#include <unistd.h>
#include <stdlib.h>

typedef double Align; /* for alignment to double boundary */

union header {	/* block header */
	struct {
		union header *ptr; /* next block if on free list */
		unsigned size;/* size of this block */
	} s;
	Align x;
};

typedef union header Header;

void *simple_malloc(unsigned nbytes);
void simple_free(void *ap);
void print_free_list();

#endif
