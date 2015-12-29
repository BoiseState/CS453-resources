
/* C-examples/arrays-and-pointers/2d-arrays.c */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char **argv) {
    int i,j;
    int n = 10;
    int ***X;


    X = (int ***) malloc(n * sizeof(int **));
    for (i=0; i<n; i++) {
        X[i] = (int **) malloc(n * sizeof(int *));
        for(j = 0; j <n; j++) {
            X[i][j] = (int *) malloc(n *sizeof(int));
        }
    }

    // initialize the 2-dimensional array
    int k;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            for(k =0; k < n; k++)
                X[i][j][k] = i;


    // delete the 2-dimensional array X
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            free(X[i][j]);
        }
        free(X[i]);
    }
    free(X);

    return 0;
}

