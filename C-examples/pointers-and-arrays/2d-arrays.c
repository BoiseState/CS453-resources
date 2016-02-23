/* C-examples/arrays-and-pointers/2d-arrays.c */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char **argv)
{
    int i,j;
    int n = 10;
    int **table;

    /* Allocate memory for the 2-dimensional array */
    table = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
        table[i] = (int *) malloc(n * sizeof(int));
    }

    /* Initialize the 2-dimensional array */
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            table[i][j] = i * j;
        }
    }

    /* Free the 2-dimensional array */
    for(i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

