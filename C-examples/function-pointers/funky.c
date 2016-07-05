#include <stdio.h>
#include "funky.h"

int square(int x)
{
	return x*x;
}

int cube(int x)
{
	return x*x*x;
}

void repeat(int x, char *string)
{
	while(x > 0) {
		printf(string);
		x--;
	}
	printf("\n");
}

void repeatln(int x, char *string)
{
	while(x > 0) {
		printf("%s\n", string);
		x--;
	}
}
