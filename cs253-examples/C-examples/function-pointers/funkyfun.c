#include <stdio.h>
#include "funky.h"

int main(int argc, char **argv)
{
	/*
	 * A pointer to a function that takes an int arg and returns an int.
	 * int    (*calc)    (int)
	 *  ^        ^         ^
	 *return  variable    arg types
	 */
	int (*calc)(int);

	/*
	 * A pointer to a function that takes a int and char * args and returns void.
	 * void    (*print)    (int, char *)
	 *  ^        ^         ^
	 *return  variable    arg types
	 */
	void (*print)(int, char *);

	/* square is the name of a function that takes an int arg and returns an int */
	calc = square;

	/* to call the function using the pointer we must dereference it using (*calc)
	 * result =  (*calc)(10);
	 *   ^         ^      ^
	 * return   function  params
	 * */
	int result = (*calc)(10);
	printf("The result of the calculation is %d\n", result);

	/* cube is the name of a function that takes an int arg and returns an int */
	calc = cube;

	result = (*calc)(10);
	printf("The result of the calculation is %d\n", result);

	/* repeat is a function that takes int and char * args and returns void. */
	print = repeat;
	(*print)(3, "Hello");

	/* repeatln is a function that takes int and char * args and returns void. */
	print = repeatln;
	(*print)(3, "Hello");
    /* This is also valid:  print(3, "Hello"); */

	return 0;
}
