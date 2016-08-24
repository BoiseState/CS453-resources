#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDMAX 101

int compchar(const void *x, const void *y) { return ((*(const char *)x) - (*(const char *)y));}

int main(void)
{
	char thisword[WORDMAX], sign[WORDMAX];

	while (scanf("%s", thisword) != EOF) {
		strcpy(sign, thisword);
		qsort(sign, strlen(sign), 1, compchar);
		printf("%s %s\n", sign, thisword);
	}
	exit(0);
}
