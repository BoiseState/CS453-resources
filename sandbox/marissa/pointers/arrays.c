#include <stdio.h>

static void print_letters(const char letters[], const int count);
static void fill_letters(char letters[], const int count);
/**
 * Skeleton for in-class demo.
 */
int main(int argc, char *argv[])
{
	/* Task 1: Static declaration */
	char letters[26];

	/* Task 2: Print addresses */
	printf("&letters: %p\n", &letters);

	/* Task 2.5: Show same thing for int array */
	int digits[10];

	/* Task 3: Print addresses using pointer arithmetic (letters + i) syntax */

	/* Task 4: Show how to access values using letters[i] syntax */

	/* Task 5: Show how to access values using pointer arithmetic *(letters + i) syntax */

	/* Task 6: Fill array with letters. Pass to function. */

	/* Task 7: Print array. Pass to function. */

	/* Task 8: How can we setup a pointer to an array? */
	/* char *pletters = letters; */
	/* char *pletters = &letters[0]; */

	/* Task 9: Increment pointer by one (pletters++) then print array. */
	/* pletters++; */
	/* print_letters(pletters, 26); */

	/* Task 9.5: Can we inspect values of other variables this way? (char hello[6] = "hello")*/

	return 0;
}

static void print_letters(const char letters[], const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		printf("[%c]", letters[i]);
	}
	printf("\n");
}

static void fill_letters(char letters[], const int count)
{
	int i;
	for(i = 0; i < count; i++) {
		letters[i] = 'a' + i;
	}
}
