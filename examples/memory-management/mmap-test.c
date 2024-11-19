
/**
 *  Demonstrate how to use mmap to get a block of memory directly from the operating system. Also
 *  demonstrate how to detroy the block of memory. This example also shows how to work with pointers in
 *  a more complex manner.
 *  @author amit
 */

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

/* memory pool size is 2^22 or 4MB */
#define MAX_MEM_SIZE 4194304


void *alloc(size_t size) {
	void *pool = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (pool == MAP_FAILED) {
        perror("mamp-test: could not allocate memory pool!");
    }
	return pool;
}


void destroy(void *ptr, size_t size) {
	int status = munmap(ptr, size);
	if (status == -1) {
		perror("mmap-test: destroy failed!");
	}
}


int main(int argc, char **argv)
{
	int i;
	int value;
	int *slot;
	char *pool;

	size_t size = UINT64_C(1) << 22;


    pool = alloc(size);
	/* Now pool is an array of MAX_MEM_SIZE  bytes */
	printf("\n");
	printf("mmap-test: starting address for memory pool  = %p\n", pool);
	for (i = 0; i < 1000000; i++) {
		slot = (int *)(pool + sizeof(int) * i);
		*slot = i;
	}

	for (i = 0; i < 10; i++) {
		memcpy(&value, pool + sizeof(int) * i, sizeof(int)); 
		printf("  int stored at slot[%d]=%d\n", i, value);
		/* printf("  int stored at slot[%d]=%d\n", i, *(int *)(pool + sizeof(int) * i)); */
		/* int * array = (int *) pool; */
		/* printf("  int stored at slot[%d]=%d\n", i, array[i])a */;
	}

	destroy(pool, size);

	printf("mmap-test: memory destroy successful\n\n");

	return 0;
}
