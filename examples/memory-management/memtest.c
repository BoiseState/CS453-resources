
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char * array;
	int count;
	int i;

	if (argc <  2)
	{
		fprintf(stderr,"Usage: %s <size(in MB)>\n",argv[0]);
		exit(1);
	}
	count = atoi(argv[1]);

	printf("--------------------------------------------------------------------------\n");
	printf("Memory usage before mallocing the array\n");
	system("free");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");
	printf("--------------------------------------------------------------------------\n");
	array = (char *) malloc (1024*1024*count*sizeof(char));
	/*array = (char *) calloc (1024*1024*count, sizeof(char));*/
	printf("Memory usage after mallocing the array\n");
	system("free");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	for (i=0; i<count*1024*1024; i++)
			array[i] = 0;

	printf("--------------------------------------------------------------------------\n");
	printf("Memory usage after initializing the array\n");
	system("free");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	free(array);
	printf("--------------------------------------------------------------------------\n");
	printf("Memory usage after calling free\n");
	system("free");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	exit(0);
}

