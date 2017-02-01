/**
 * A generic min function example.
 * @author Marissa, Amit
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Compares the given values. Returns negative if n1 < n2, positive if
 * n1 > n2, 0 if they are equal.
 *
 * @param n1 The first value.
 * @param n2 The second value.
 */
int compare(const void *n1, const void *n2)
{
	return (*(int *)n1) - (*(int *)n2);
}

/**
 * Returns the index of the smallest element in the array.
 *
 * @param v A pointer to the first element of an array of pointers.
 * @param size The number of elements in the array.
 * @param compare A pointer to the compare function we will use.
 * @return The index of the smallest element.
 */
int min(void *v[], int size, int(*compare)(const void * , const void *))
{
	int i ;
	int min = 0;
	for (i = 1; i < size; i ++) {
		if (compare(v[i],v[min]) < 0) {
			min = i ;
		}
	}
	return min ;
}

int main()
{
	const int SIZE = 3;
	int i;
	int **v;
	int imin;

	/* We need a pointer to an array of pointers */
	v = (int **) malloc(sizeof(int *) * SIZE);
	for (i = 0; i < SIZE; i++) {
		v[i] = (int *) malloc(sizeof(int));
	}

	*v[0] = 12;
	*v[1] = 1230;
	*v[2] = 123;

	/* Find the index of the smallest value */
	imin = min((void  **)v, SIZE, compare);
	printf("%d\n", *v[imin]);
	
	/* make sure to free array */
	for(i = 0; i < SIZE; i++) {
		free(v[i]);
	}
	free(v);

	return 0;
}
