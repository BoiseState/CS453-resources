#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * Demonstrates integer overflow.
 */
int main ()
{
	unsigned int my_uint = UINT_MAX;
	int my_int = INT_MAX;

    printf("%25s %25s %25s\n", "type", "max", "max+1");
    printf("%25s %25u %25u\n", "unsigned", my_uint, my_uint+1);
    printf("%25s %25d %25d\n", "signed", my_int, my_int+1);

	my_uint = 0U;
	my_int = INT_MIN;

    printf("%25s %25s %25s\n", "type", "min", "min-1");
    printf("%25s %25u %25u\n", "unsigned", my_uint, my_uint-1);
    printf("%25s %25d %25d\n", "signed", my_int, my_int-1);

    return 0;
}

