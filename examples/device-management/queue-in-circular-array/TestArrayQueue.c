
#include <stdio.h>

int main(int argc, char *argv)
{

	if (argc != 3) {
		fprintf(stderr, "Usage: TestArrayQueue <size> <numTests>\n");
		exit(1);
	}

	exit(0);
}
