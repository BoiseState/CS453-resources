
/* C-examples/pointers-and-arrays/pointers2.c */

/*
 * Example to illustrate pointers in  C
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int z1 = 15;
    int *p1;
    int **p2;
    int ***p3;

    p1 = &z1;
    p2 = &p1;
    p3 = &p2;
    printf("*p1 = %d\n",*p1);
    printf("**p2 = %d\n",**p2);
    printf("***p3 = %d\n",***p3);

    return 0;
}
