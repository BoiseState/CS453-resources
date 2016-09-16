#include <stdio.h>

static void print_array(const char values[], const int count);
static void fill_array(char values[], const int count);

/**
 * Skeleton for in-class demo.
 */
int main(int argc, char *argv[])
{
	int i, n = 5;

	/* Static declaration and fill values */
	char letters[n];

	/* Print address of letters */
	printf("letters: %p\n", letters);

	/* Print addresses */
	printf("\nAddresses using array indexing syntax\n");
	printf("&letters[i]: ");
	for(i = 0; i < n; i++) {
		printf("[%p]", &letters[i]);
	}
	printf("\n");

	/* Print addresses using pointer arithmetic (letters + i) syntax */
	/* letters is an address, so if we add to the address, we can get a new
	 * address */
	printf("\nAddresses using pointer arithmetic\n");
	printf("letters + i: ");
	for(i = 0; i < n; i++) {
		printf("[%p]", letters + i);
	}
	printf("\n");

	/* Fill array with values (use array indexing and pointer arithmetic) */
	letters[0] = 'a';
	*(letters + 0) = 'a';

	/* Show same thing for int array */
	/* int digits[n]; */
    /*  */
	/* printf("digits: %p\n", digits); */
    /*  */
	/* printf("\nAddresses using array indexing syntax\n"); */
	/* printf("&digits[i]: "); */
	/* for(i = 0; i < n; i++) { */
	/* 	printf("[%p]", &digits[i]); */
	/* } */
	/* printf("\n"); */
    /*  */
	/* printf("\nAddresses using pointer arithmetic\n"); */
	/* printf("digits + i: "); */
	/* for(i = 0; i < n; i++) { */
	/* 	printf("[%p]", digits + i); */
	/* } */
	/* printf("\n"); */
    /*  */

	/* How can we setup a pointer to an array? */
	/* char *pletters = letters; */
	/* char *pletters = &letters[0]; */

	/* Increment pointer by one (pletters++) then print array. */
	/* pletters++; */
	/* print_letters(pletters, 26); */

	/* Can we inspect values of other variables this way? (char hello[6] = "hello")*/

	return 0;
}

static void print_array(const char values[], const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		printf("[%c]", values[i]);
	}
	printf("\n");
}

static void fill_array(char values[], const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		values[i] = 'a' + i;
	}
}
