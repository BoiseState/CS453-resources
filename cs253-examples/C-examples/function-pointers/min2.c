/**
 * A generic min function example.
 * @author Marissa
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
 * @param v A pointer to an array of objects.
 * @param nmemb The number of elements in the array.
 * @param size The size of each element in the array.
 * @param compare A pointer to the compare function we will use.
 * @return The index of the smallest element.
 */
int min(void *v, int nmemb, size_t size, int(*compare)(const void * , const void *))
{
	int i ;
	int min = 0;
	for (i = 1; i < nmemb; i++) {
		if (compare(v+(i*size),v+(min*size)) < 0) {
			min = i ;
		}
	}
	return min ;
}

int main()
{
	int imin;
	
	/* We just need an array of elements */
	int v[] = {123, 12, 123, 1230};
	int n = sizeof(v) / sizeof(int); /* num elements */

	/* Find the index of the smallest value */
	imin = min((void  *)v, n, sizeof(int), compare);
	printf("%d\n", v[imin]);
	
	return 0;
}
