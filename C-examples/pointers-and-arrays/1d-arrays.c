/* C-examples/arrays-and-pointers/1d-arrays.c */
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

/* A macro for printing array debug statements. To compile with debugging,
 * gcc -Wall -g -DDEBUG 1d-arrays.c -o 1d-arrays */
#ifdef DEBUG
#define debug(a, n, m) printf("\n\t[DEBUG] " m "\n"); print_array((a), (n))
#else
#define debug(a, n, m)
#endif

#define SIZE 5

static void print_array(int *values, int size);

int main(int argc, char **argv)
{
    int i;
    
	int digits[SIZE]; /* static allocation */
    int *pdigits = digits; /* pointer to digits array */

	int n = rand() % 100; /* random array size */
    int *zeros; /* dynamically allocated below */

	printf("\nStatically declared array of %d elements...\n", SIZE);
    debug(digits, SIZE, "digits before init'ing elements (expect a valgrind read error)");
    debug(pdigits, SIZE, "pdigits before init'ing digits (expect a valgrind read error)");

	/* Initialize values of digits */
	printf("\nInitializing digits...\n");
    for (i = 0; i < SIZE; i++) {
        digits[i] = i;
    }
    debug(digits, SIZE, "digits after init'ing elements");
    debug(pdigits, SIZE, "pdigits after init'ing digits");

	/* Allocate memory for zeros array */
	printf("\nDynamically allocating %d elements...\n", n);
    //debug(zeros, n, "zeros before malloc'ing memory"); /* this may cause seg fault (if we are lucky) */
    zeros = (int *) malloc(sizeof(int) * n);
    debug(zeros, n, "zeros after malloc'ing memory (expect a valgrind read error)"); 

	/* Initialize zeros array */
    for (i = 0; i < n; i++) {
        zeros[i] = 0; /* equivalent to *(C+i) */
    }
    debug(zeros, n, "zeros after init'ing elements");

	/* Could also just use calloc if we know we want all zeros */	
    /* zeros = (int *) calloc(sizeof(int) * n, sizeof(int)); */

	/* Doubling the size of zeros */
	printf("\nDoubling size of zeros...\n");
    zeros = (int *) realloc(zeros, sizeof(int) * (n * 2));
    for(i = n; i < (n * 2); i++) {
        zeros[i] = 0;
    }
    debug(zeros, n*2, "zeros after realloc");
    
	/* Free memory (for every malloc there is a free) */
	printf("\nFreeing zeros...\n");
	free(zeros);
    //debug(zeros, n*2, "zeros after free (expect a valgrind read error)");

	/* pdigits is also a pointer. Should I free it? Why or why not? */

    /* Always set your pointers to NULL when you are done */
	printf("\nPreventing \"dangling pointers\"...\n");
    zeros = NULL;
	printf("zeros (%p)\n", zeros);

    return 0;
}

static void print_array(int *values, int size)
{
    int i = 0;
    printf("\tPointer: %p\n\t", values);
    for(i = 0; i < size; i++) {
        printf("[%d]", values[i]);
    }
    printf("\n");
}
