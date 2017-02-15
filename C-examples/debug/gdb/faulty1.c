

/*
 * Example to illustrate an ndex out of bounds error.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int *B;
    int i;

    B = (int *) malloc(sizeof(int)*100);

    /* This should cause an error */
    for (i = 0; i < 110; i++)
        B[i] = i;

    free(B);
	return 0;
}
