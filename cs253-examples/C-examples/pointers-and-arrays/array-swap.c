/* C-examples/arrays-and-pointers/array-swap.c */
#include <stdio.h>
#include <stdlib.h>

static void print_array(int *values, int size);
static void swap_arrays(int **a, int **b);

int main(int argc, char **argv)
{
	int i;
	int n = 10;

	/* Allocate memory */
	int *a = (int *) malloc(sizeof(int) * n);
	int *b = (int *) malloc(sizeof(int) * n); 

	/* Initialize values */
	for (i = 0; i < n; i++) {
		a[i] = i;
		b[i] = 0;
	}

	printf("a"); print_array(a, n);
	printf("b"); print_array(b, n);

	/* Swap */
	printf("\nSwapping....\n\n");
	swap_arrays(&a, &b);

	printf("a"); print_array(a, n);
	printf("b"); print_array(b, n);

	/* Delete the arrays that a and b point to */
	printf("\nFreeing....\n\n");
	free(a);
	free(b);

	printf("a"); print_array(a, n);
	printf("b"); print_array(b, n);

	/* Always set your pointers to NULL when you are done. */
	printf("\nFixing \"dangling pointers\"....\n\n");
	a = b = NULL;

	/* printf("a"); print_array(a, n); */
	/* printf("b"); print_array(b, n); */
	printf("a (%p)\n", a);
	printf("b (%p)\n", b);

	return 0;
}

static void print_array(int *values, int size)
{
	int i = 0;
	printf("\tPointer: %p\n\t", values);
	for(i = 0; i < size; i++) {
		printf("[%d]", values[i]);
	}
	printf("\n");
}

static void swap_arrays(int **a, int **b)
{
	int *tmp = *a;
	*a = *b;
	*b = tmp;
}
