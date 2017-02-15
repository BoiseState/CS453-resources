#include <stdio.h>
#include <stdlib.h>

static void fill_array(int *array, const int count);
static void print_array(const int *array, const int count);

/**
 * Skeleton for in class demo.
 */
int main(int argc, char *argv[])
{
	/* Task 1: Dynamically allocate array */
	int n = 10000;
	int *values;
	print_array(values, n);

	return 0;
}

static void fill_array(int *array, const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		array[i] = i;
	}
}

static void print_array(const int *array, const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		printf("[%d]", array[i]);
	}
	printf("\n");
}


