
/*  C-examples/intro/cmdline.c */

#include <stdio.h>
#include <stdlib.h>
/*
   We are expecting 4 command line arguments:
   the first one a string, the next an integer, the next a double.
   Recall that the name of the executable is always passed in as the first
   command line argument, so we have a total of 4 command line arguments.

*/

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <string> <int> <float>\n", argv[0]);
        return 1;
    }

    printf("argument count = %d\n", argc);

    printf("argument %d = %s\n", 0, argv[0]);
    printf("argument %d = %s\n", 1, argv[1]);
    printf("argument %d = %d\n", 2, atoi(argv[2]));
    printf("argument %d = %lf\n", 3, atof(argv[3]));

    return 0;
}
