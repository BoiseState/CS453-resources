

/* C-examples/pointers-and-arrays/pointers1.c */

/*
 * Example to illustrate pointers in  C
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 1, y = 2 ;
    int *ip;  /* ip is a pointer to an int */
    int *iq;  /* iq is another pointer to an int */

    ip = &x;  /* ip now points to x */
    printf("ip = %p \n", ip);
    y = *ip;  /* y is now 1 */
    *ip = 10;  /*x is now 10 */
    printf("x = %d\n", x);

    *ip = *ip + 1; /* x is now 11 */
    printf("x = %d\n", x);

    *ip += 1; /* x is now 12 */
    printf("x = %d\n", x);

    ++*ip;   /* x is now 13 */
    printf("x = %d\n", x);

    (*ip)++; /* x is now 14, parentheses is required as *, ++ associate left to right */
    printf("x = %d\n", x);

    iq = ip;
    printf("iq = %p ip = %p *iq = %d\n", iq, ip, *iq);

    return 0;
}
