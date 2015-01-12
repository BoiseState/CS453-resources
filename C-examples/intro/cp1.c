
/* C-examples/intro/cp1.c */


#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;

	c = getchar();
	while (c != EOF ) {
		putchar(c);
		c = getchar();
	}
	return 0;
}
