
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int chunksize;
	void *prev_endptr, *new_endptr;
	char *ptr;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <chunk size> \n", argv[0]);
		exit(1);
	}
	chunksize = atoi(argv[1]);

	prev_endptr = sbrk(0); // argument of zero returns end of data segment

	for (i = 0; i <1000; i++)
	{
		ptr = (char *) malloc(sizeof(char)*chunksize);
		memset(ptr, 0, chunksize*sizeof(char));
		new_endptr = sbrk(0); // argument of zero returns end of data segment
		if (new_endptr != prev_endptr)
		{
			printf("iteration %d: end of data segment = %lx \n", i, (unsigned long)new_endptr);
			prev_endptr = new_endptr;
		}
	}
	exit(0);
}
