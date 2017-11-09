#include <stdio.h>

/*@author Aza Tulepbergenov
 */

int main()
{
    int c; //character
    while ((c=getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c =='\t') {
            putchar('\n');
        } else
            putchar(c);
    }
    return 0;
}
