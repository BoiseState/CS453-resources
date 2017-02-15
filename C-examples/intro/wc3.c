
/* C-examples/intro/wc3.c */

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count number of characters, words and lines in the standard input */

int main(int argc, char *argv[])
{
    int c;
    long nc, nw, nl;
    int state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF ) {
        nc++;
        if (c == '\n') {
            nl++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    printf("nl: %ld nw: %ld nc: %ld\n", nl, nw, nc);
    return 0;
}
