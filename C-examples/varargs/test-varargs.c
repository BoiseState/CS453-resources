
/* C-examples/overloading/test-varargs.c */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


void strlist(int n, ...)
{
    va_list ap;
    char *s;

    va_start(ap, n);
    while (1) {
        s = va_arg(ap, char *);
        if (n==0) break;
        printf("%s\n",s);
        n--;
    }
    va_end(ap);
}



int main()
{


    printf("Calling with three arguments\n");
    strlist(3, "string1", "string2", "string3");

    printf("Calling with two arguments\n");
    strlist(2, "string1", "string3");

    printf("Calling with 0 arguments\n");
    strlist(0);

    exit(0);
}

