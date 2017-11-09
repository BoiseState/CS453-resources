#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main()
{
    int i, sum = 0;
    int *a = malloc(SIZE);
    for(i=0; i<SIZE; ++i) 
		sum += a[i];
    a[26] = 1;
    a = NULL;
    if (sum > 0) printf("Hi!\n");
    return 0;
}

/*
 * Source: http://haifux.org/lectures/239/
 */
