/* C-examples/c-preprocessor/ex2.c */

#include <stdio.h>
#include <stdlib.h>

/*
 * Full list of identifying strings for various operating systems can be found at
 * http://sourceforge.net/p/predef/wiki/OperatingSystems/
 */
int main(int argc, char *argv[])
{
#ifdef _WIN32
    printf("Welcome to MS Windows ( I rule!).\n");
#elif __linux__
    printf("I am the Happy Penguin!\n");
#elif __APPLE__&&__MACH__
    printf("Welcome to I am cool!\n");
#else
    printf("Uh! who am i?\n");
#endif
    exit(0);
}
