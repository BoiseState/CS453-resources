

/*
 * Example to illustrate pointers/arrays in C
 *
 * Index out of bounds error.
 */

#include <stdio.h>
#include <stdlib.h>

int *B;
int *C;

int main(int argc, char **argv) {
    // one dimensional arrays
    int A[100];
    int *B;
    int *C;
    int *tmp;
    int i;

    for (i=0; i<100; i++)
        A[i] = i;

    B = (int *) malloc(sizeof(int)*100);

    /* This is legal, but not good! */
    for (i =0; i<110; i++)
        B[i] = i;

    /* This should cause an error! */
    for (i =0; i<100; i++)
        C[i] = 1;

    tmp = B;
    B = C;
    C = tmp; // swap B and C

    // delete the arrays that B and C point to
    free(B);
    free(C);

    exit(0);
}
