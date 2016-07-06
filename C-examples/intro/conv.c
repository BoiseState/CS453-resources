#include <stdio.h>

/*
 * Try compiling as
 *  gcc -Wall conversion.c -o conv
 *
 *  and then
 *
 *  gcc -Wall -Wconversion conv.c -o conv
 *
 */

int main()
{
    int m = 0;
    long n = 10000000000;
    float x = 0;
    double y = 2E300;

    printf("Before m = n;\n int m: %d\n long n: %ld\n", m, n);
    m = n;
    printf("After m = n;\n int m: %d\n long n: %ld\n", m, n);

    printf("\n");

    printf("Before x = y;\n float x: %e\n double y: %le\n", x, y);
    x = y;
    printf("After x = y;\n float x: %e\n double y: %le\n", x, y);

    return 0;


}
