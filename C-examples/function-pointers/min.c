/**
 * A generic min function example.
 * @author Marissa, Amit
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *n1, const void *n2)
{
	return (*(int *)n1) - (*(int *)n2);
}


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
	int i;
	const int SIZE = 3;
	int **v;
	v = (int **) malloc(sizeof(int *) * SIZE);
	for (i = 0; i < SIZE; i++)
		v[i] = (int *) malloc(sizeof(int));

	*v[0] = 12;
	*v[1] = 1230;
	*v[2] = 123;

	int index = min((void  **)v, SIZE, compare);
	printf("%d\n", *v[index]);
	return 0;
}
