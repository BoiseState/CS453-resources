

/* C-examples/intro/wc2.c */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    long nl;

    nl = 0;
    while ((c = getchar()) != EOF ) {
        if (c == '\n') {
            nl++;
        }
    }
    printf("%ld\n", nl);
    return 0;
}
