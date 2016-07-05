/* C-examples/arrays-and-pointers/1d-arrays.c */
#include <stdio.h>
#include <stdlib.h>

/* A macro for printing array debug statements. To compile with debugging,
 * gcc -Wall -g -DDEBUG 1d-arrays.c -o 1d-arrays */
#ifdef DEBUG
#define debug(a, n, m) printf("\n" m "\n"); printArray((a), (n))
#else
#define debug(a, n, m)
#endif

#define SIZE 5

void printArray(int *values, int size);
void swapArrays(int **a, int **b);

int main(int argc, char **argv)
{
    int A[SIZE]; /* static allocation */
    int *B = (int *) malloc(sizeof(int) * SIZE); /* dynamic allocation */
    int *C; /* C will point to an array of n int's */
    int n = 10;
    int i;

    debug(A, SIZE, "A before init'ing elements");
    for (i = 0; i < SIZE; i++) {
        A[i] = i;
    }
    debug(A, SIZE, "A after init'ing elements");
    C = A;
    debug(C, SIZE, "C after assigning A");

    debug(B, SIZE, "B before init'ing elements");
    for (i = 0; i < SIZE; i++) {
        B[i] = i;
    }
    debug(B, SIZE, "B after init'ing elements");

    debug(C, n, "C before malloc'ing memory"); /* this may cause seg fault (if we are lucky) */
    C = (int *) malloc(sizeof(int) * n);
    debug(C, n, "C before init'ing elements");
    for (i = 0; i < n; i++) {
        C[i] = 1;  /* equivalent to *(C+i) */
    }
    debug(C, n, "C after init'ing elements");

    swapArrays(&B, &C);
    debug(B, n, "B after swap");
    debug(C, SIZE, "C after swap");

    C = (int *) realloc(C, sizeof(int) * (SIZE * 2));
    for(i = SIZE; i < (SIZE * 2); i++) {
        C[i] = i;
    }
    debug(C, SIZE*2, "C after realloc");

    /* Delete the arrays that B and C point to */
    free(B);
    free(C);

    debug(B, n, "B after free");
    debug(C, SIZE*2, "C after free");

    /* Always set your pointers to NULL when you are done. */
    B = C = NULL;

    return 0;
}

void printArray(int *values, int size)
{
    int i = 0;
    printf("\tPointer: %p\n\t", values);
    for(i = 0; i < size; i++) {
        printf("[%d]", values[i]);
    }
    printf("\n");
}

void swapArrays(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
