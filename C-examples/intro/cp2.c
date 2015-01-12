
/* C-examples/intro/cp2.c */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;

	/* The parentheses around c = getchar() are required because
	   the operator != has higher precedence than = operator */

	while ((c = getchar()) != EOF ) {
		putchar(c);
                printf("hello");

        }

	return 0;
}
