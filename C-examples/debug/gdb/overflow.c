#include <stdio.h>

void printValues(int n, char values[])
{
	int i;
	printf("Printing chars");
	printf("\n=================================\n");
	for(i = 0; i < n; ++i) {
		printf("%c ", values[i]);
	}
	printf("\n=================================\n");
}

int main(int argc, char *argv[])
{
	int i, n = 10, m = 100000;

	char values[n];

	// does this fail? if it does, use gdb backtrace
	for(i = 0; i < m; ++i) {
		values[i] = 'a' + i;
	}

	char message[] = {'h', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e'};

	printValues(m, values);

	return 0;
}


