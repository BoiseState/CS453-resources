
/* C-examples/intro/wc1.c */

#include <stdio.h>

int main(int argc, char *argv[])
{
    long nc;

    nc = 0;
    while (getchar() != EOF ) {
        nc++;
    }
    printf("%ld\n", nc);
    return 0;
}


/* An alternate way of writing the above */
/*
 int main()
 {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
 }
*/
