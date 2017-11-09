#include <stdio.h>
/*@author Aza Tulepbergenov.
 */

/* Exercise 1-10 */
int main(int argc, char **argv)
{
    int c;
    while ((c=getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else
            putchar(c);
    }
    return (0);
}

