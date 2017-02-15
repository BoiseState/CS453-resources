

/*
 * Example to illustrate pointers/arrays in C
 * Array out of bounds
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // one dimensional arrays
    int A[100]; //static declaration
    int *B;
    int *C;
    int *tmp;
    int n=10;
    int i,j;

    int **X; // dynamically allocated two-dimensional array
    int **Y;

    for (i=0; i<100; i++)
        A[i] = i;

    B = (int *) malloc(sizeof(int)*100);  // B points to an array of 100 int's
    for (i =0; i<100; i++)
        B[i] = i;

    C = (int *) malloc(sizeof(int)*100); // C points to an array of n int's
    for (i =0; i<100; i++)
        C[i] = 1;

    tmp = B;
    B = C;
    C = tmp; // swap B and C

    // free the space that arrays B and C point to
    free(B);
    free(C);

    // two dimensional arrays
    X = (int **) malloc(sizeof(int *)*n);
    for (i=0; i<n; i++)
        X[i] = (int *) malloc(sizeof(int)*n);


    // initialize the 2-dimensional array
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            X[i][j] = i;

    // print out the 2-dimensional array
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf(" %d",X[i][j]);
        printf("\n");
    }


    // delete the 2-dimensional array X
    for (i=0; i<n; i++)
        free(X[i]);
    free(X);

    //create  triangular shaped 2-dimensional array
    Y = (int **) malloc(sizeof(int *)*n);
    for (i=0; i<n; i++)
        Y[i] = (int *) malloc(sizeof(int)*(i+1));

    // initialize the triangular array
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
            Y[i][j] = (i)*(i+1)/2 + j + 1;

    // print out the triangular array
    for (i=0; i<n; i++) {
        for (j=0; j<=i; j++) {
            printf("%3d ",Y[i][j]);
        }
        printf("\n");
    }

    // free the 2-dimensional array Y
    for (i=0; i<n; i++)
        free(Y[i]);
    free(Y);

	return 0;
}
