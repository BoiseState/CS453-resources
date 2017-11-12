/* C-examples/arrays-and-pointers/2d-arrays.c */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char **argv)
{
    int i,j;
    int n = 3, m = 5;
    int **table;

    /* Allocate memory for the 2-dimensional array */
    table = (int **) malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++) {
        table[i] = (int *) malloc(sizeof(int) * m);
    }

    /* Initialize the 2-dimensional array */
    for(i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            table[i][j] = i * j;
        }
    }

	/* Print the 2-dimensional array values */
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("[%d]", table[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/* Print the 2-dimensional array memory locations */
	/* printf("table[%p]\n", table); */
	/* printf("     %6c\n", '|'); */
	/* printf("     %6c\n", 'v'); */
	/* for(i = 0; i < n; i++) { */
	/* 	printf("     [%p] -> ", table[i]); */
	/* 	for(j = 0; j < m; j++) { */
	/* 		printf("[%d]", table[i][j]); */
	/* 	} */
	/* 	printf("\n"); */
	/* } */

    /* Free the 2-dimensional array */
    for(i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

