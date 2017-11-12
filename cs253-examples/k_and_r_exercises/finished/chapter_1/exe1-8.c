#include <stdio.h>
/*
 * @author Aza Tulepbergenov.
 */

/*Special characters include blank, tabs and newline chars.*/
int main()
{
    int tabs, empty, newlines, c;
    tabs = empty = newlines = 0;
    while ((c=getchar()) != EOF) {
        if (c==' ')
            ++empty;
        if (c=='\t')
            ++tabs;
        if (c =='\n')
            ++newlines;
    }
    printf("There are total: %d empty chars, %d tabs, %d newlines\n", empty, tabs, newlines);
    return (0);
}
