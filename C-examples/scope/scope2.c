
/* C-examples/scope/scope2.c */

#include <stdio.h>
#include <stdlib.h>
#include "ourhdr.h"

/*int total = 203920392;*/

void addToTotal(int x)
{
	printf("\nIn function addToTotal (from scope2.c): total = %d\n", total);
	total += x;
	printf("\ntotal in scope2 after addition = %d\n", total);
}
