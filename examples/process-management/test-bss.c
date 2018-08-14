#include <unistd.h>
#include <stdlib.h>

/**
 * This program shows that a global array with all zeroes in stored
 * in a block started by symbol (bss) section, which only stores the
 * name of the block and number of zeroes. This reduces the size of
 * the executable and makes it faster to load. The block is filled 
 * with zeroes on loading.
 */

int a[100000000];

int main(void)
{
	int i;

	system("free");
	for (i=0; i<100000000; i++)
		a[i] = i*i;

	system("free");
	sleep(100);
	exit(0);
}
