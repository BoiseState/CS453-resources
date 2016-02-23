#include <stdio.h>
/*
 * @author Aza Tulepbergenov
 */
int main(int argc, char **argv)
{
    int c;
    int again = 0; //0 if blank space is not encountered; 1 otherwise.
    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            //if haven't encountered blank space
            if (again == 0) {
                putchar(c);//print single space
                again = 1;//blank space is encountered
            }
        }
        //non-space char is encountered
        else {
            putchar(c);
            again = 0;//blank space is not encountered
        }
    }
    return (0);
}

