/*
 * array-bounds.c
 *
 *  Created on: Feb 19, 2014
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a[10], i;
    int *pa = &a[0];

    for(i = 0; i < 10; i++)
        pa[i] = i;

    for(i = 0; i < 10; i++)
        printf("%d ", pa[i]);
    printf("\n");

    // What happens when we run the following code?
    pa += 1;

    for(i = 0; i < 10; i++)
        printf("%d ", pa[i]);
    printf("\n");

    // What happens when we run this?
    pa = a;
    pa--;
    for(i = 0; i < 10; i++)
        printf("%d ", pa[i]);
    printf("\n");

    return 0;
}
