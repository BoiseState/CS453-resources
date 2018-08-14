
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* memory pool size is 2^22 or 4MB */
#define MAX_MEM_SIZE 4194304

int main(int argc, char **argv)
{
	int i;
	int value;
	int *slot;

	/*void *pool = sbrk(1LL << 34);*/
	char *pool = sbrk(1ll << 22);
	if (pool < 0 || errno == ENOMEM) {
		perror("Could not allocate memory pool!");
		exit(1);
	}
	/* Now pool is an array of MAX_MEM_SIZE  bytes */

	printf("starting address for memory pool  = %p\n", pool);
	for (i =0; i < 1000000; i++) {
		slot = (int *)(pool + sizeof(int) * i);
		*slot = i;
	}

	for (i = 0; i < 10; i++) {
		memcpy(&value, pool + sizeof(int) * i, sizeof(int)); 
		printf("int stored at slot[%d]=%d\n", i, value);
		/*printf("int stored at slot[%d]=%d\n", i, *(int *)(pool+sizeof(int)*i));*/
		/*int * array = (int *) pool; array[i]*/
	}
	/*int *x = (int *) malloc(sizeof(int));*/
	char *pool2 = sbrk(1 << 22);
	if (pool2 < 0 || errno == ENOMEM) {
		perror("Could not allocate memory pool!");
		exit(1);
	}
	printf("starting address for memory pool  = %p\n", pool2);
	for (i = 0; i < 1000000; i++) {
		slot = (int *)(pool2 + sizeof(int) * i);
		*slot = i;
	}
	for (i = 0; i < 10; i++) {
		memcpy(&value, pool2 + sizeof(int) * i, sizeof(int)); 
		printf("int stored at slot[%d]=%d\n", i, value);
	}

	exit(0);
}
