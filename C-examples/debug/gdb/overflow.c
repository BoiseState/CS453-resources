#include <stdio.h>
#include <string.h>

void printValues(char msg[], int n, char values[])
{
	int i;
	printf("Printing %s", msg);
	printf("\n=================================\n");
	for(i = 0; i < n; ++i) {
		printf("%c ", values[i]);
	}
	printf("\n=================================\n");
}


int main(int argc, char *argv[])
{
	int i = 0, m = 100000;
	char message[] = {'h', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e'};
	char values[10];

	printValues("message", strlen(message), message);

	// This writes beoynd the end of the array --- what effect does that have?
	for(i = 0; i < m; ++i) {
		values[i] = 'a' + i;
	}
	printValues("values", 10, values);
	printValues("message", strlen(message), message);

	return 0;
}


