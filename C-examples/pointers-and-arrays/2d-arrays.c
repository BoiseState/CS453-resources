
/* C-examples/arrays-and-pointers/2d-arrays.c */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char **argv)
{
	int i,j;
	int n = 10;
	int Z[4][10];
	int **X;
	int **Y;


	// two dimensional arrays
	// initialize the static 2-dimensional array
	for (i=0; i<4; i++)
		for (j=0; j<10; j++)
			Z[i][j] = i;

	X = (int **) malloc(n * sizeof(int *));
	for (i=0; i<n; i++)
		X[i] = (int *) malloc(n * sizeof(int));


	// initialize the 2-dimensional array
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			X[i][j] = i;

	// print out the 2-dimensional array
	for (i=0; i<n; i++)
	{		
		for (j=0; j<n; j++)
			printf(" %d",X[i][j]);
		printf("\n");
	}


	// delete the 2-dimensional array X
	for (i=0; i<n; i++)
			free(X[i]);
	free(X);

	//create triangular shaped 2-dimensional array
	Y = (int **) malloc(sizeof(int *)*n);
	for (i=0; i<n; i++)
		Y[i] = (int *) malloc(sizeof(int)*(i+1));

	/*try row size = random() % 15 + 1;*/

	// initialize the triangular array
	for (i=0; i<n; i++)
		for (j=0; j<=i; j++)
			Y[i][j] = (i)*(i+1)/2 + j + 1;

	// print out the triangular array
	for (i=0; i<n; i++)
	{		
		for (j=0; j<=i; j++) {
			printf("%3d ",Y[i][j]);
		}
		printf("\n");
	}

	// delete the 2-dimensional array Y
	for (i=0; i<n; i++)
			free(Y[i]);
	free(Y);

	return 0;
}

