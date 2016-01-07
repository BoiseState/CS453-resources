
/*
 * How to create a vector of pointers for a  2-d array in a 1-d space
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

	int **array;
	int *ptr;
	int i, j, n;

	n=atoi(argv[1]);

	ptr = (int *) malloc(sizeof(int)*n*n);
	array = (int **) malloc(sizeof(int *) *n);
	for (i=0; i<n; i++)
		array[i] = ptr + i * n;
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			array[i][j] = 1;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			printf(" %d ",array[i][j]);
		printf("\n");
	}
	exit(0);
}
