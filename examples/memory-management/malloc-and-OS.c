
#include <stdlib.h>
#include <stdio.h>

/**
 * Try testing the memory allocation fron the OS by
 *
 * strace -e memory malloc-and-OS <count>
 *
 * and change count to 1, 2, 10, 100, 500, 1000, ...
 */

int main(int argc, char **argv) 
{
	int i;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s  <count>\n", argv[0]);
		exit(1);
	}
	int count = atoi(argv[1]);

	for (i= 0; i < count; i++) {
		int *x = (int *) malloc(sizeof(int));
		*x = i;
	}
	return 0;
}
