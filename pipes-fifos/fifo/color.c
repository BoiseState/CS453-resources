#include <stdio.h>
#include <stdlib.h>

#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define green "\033[4;32m"        /* 4 -> underline ;  32 -> green */
#define blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */

#define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"

#define none   "\033[0m"        /* to flush the previous property */

int main(void)
{
    printf("\n");
    printf("%sHello, %sworld!%s\n", red, blue, none);
    printf("%sHello%s, %sworld!\n", green, none, cyan);
    printf("%s", none);
    printf("Vanilla hello\n");
    printf("\n");

    exit(EXIT_SUCCESS);
}
