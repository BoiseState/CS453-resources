/* Run
 *   gcc -M range.c
 * to locate limits.h and float.h headers
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main ()
{
    printf("%25s %25s %25s\n", "Type", "Min", "Max");

    printf("%25s %25d %25d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%25s %25u %25u\n", "unsigned char", 0U, UCHAR_MAX);

    printf("%25s %25d %25d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%25s %25u %25u\n", "unsigned short", 0U, USHRT_MAX);

    printf("%25s %25d %25d\n", "int", INT_MIN, INT_MAX);
    printf("%25s %25u %25u\n", "unsigned int", 0U, UINT_MAX);

    printf("%25s %25ld %25ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%25s %25lu %25lu\n", "unsigned long", 0UL, ULONG_MAX);
    /* 0UL makes 0 unsigned long int type, otherwise 0 would be a signed int by default */

    printf("%25s %25e %25e\n", "float", FLT_MIN, FLT_MAX);
    printf("%25s %25e %25e\n", "double", DBL_MIN, DBL_MAX);
    printf("%25s %25Le %25Le\n", "long double", LDBL_MIN, LDBL_MAX);

    return 0;
}

