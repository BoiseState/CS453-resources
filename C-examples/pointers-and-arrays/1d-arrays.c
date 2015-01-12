
/* C-examples/arrays-and-pointers/1d-arrays.c */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char **argv)
{
	// one dimensional arrays
	int A[SIZE];
	int *B;
	int *C;
	int *tmp;
	int n=10;
	int i;


	for (i=0; i<SIZE; i++)
		A[i] = i;

	/* Use %p to print pointer */
	printf("A: %p\n", A);

	/*in Java: int B[] = new int[SIZE];*/

	B = (int *) malloc(sizeof(int)*SIZE);  // B points to an array of SIZE int's
	for (i =0; i<SIZE; i++)
		B[i] = i;

	C = (int *) malloc(sizeof(int)*n); // C points to an array of n int's
	for (i =0; i<n; i++)
		C[i] = 1;  /* equivalent to *(C+i) */
	
	// swap B and C
	tmp = B;
	B = C;
	C = tmp;

	C = (int *) realloc(C, sizeof(int) * (SIZE * 2));
	for(i = SIZE; i < (SIZE * 2); i++)
		C[i] = i;

	// delete the arrays that B and C point to
	free(B);
	free(C);

	B = C = tmp = NULL;

	return 0;
}

