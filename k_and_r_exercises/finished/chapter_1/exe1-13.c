#include <stdio.h>
/*
 * @author Aza Tulepbergenov.
 */

/* When inside the word, add chars to an array. When end of a word reached,
 * simply print out the histogram and add a new line.
*/
#define MAXWORD = 30;
//extern int count;
int main()
{
    int c;
    int count = 0;
    while ((c=getchar()) != EOF) {
        if (c != '\n' && c != '\t'&& c != ' ') {
            putchar(c);
            ++count;
        } else {
            putchar(':');
            printHisto(count);
            count = 0;
        }
    }
    return (0);
}

int printHisto(int num)
{
    int i;
    for (i = 0; i < num; ++i) {
        putchar('*');
    }
    putchar('\n');
    return (0);
}




