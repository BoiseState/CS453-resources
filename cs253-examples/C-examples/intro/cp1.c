#include <stdio.h>

/**
 * C-examples/intro/cp1.c
 *
 * Test using file redirection in the terminal.
 *
 * gcc -Wall -o cp1 cp1.c
 * cp1 < file1 > file1.copy
 */
int main(int argc, char *argv[])
{
    int c;  // why is this int and not char?

    c = getchar();
    while (c != EOF ) {
        putchar(c);
        c = getchar();
    }
    return 0;
}
