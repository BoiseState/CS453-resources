#include <stdio.h>
#include <stdlib.h>

#define NBITS_BYTE 8
#define NBITS_CHAR sizeof(unsigned char) * NBITS_BYTE

/* function prototypes */
void visualize(unsigned char);
unsigned char isBitISet(unsigned char ch, int i);
void toString(unsigned char x, unsigned char mask, unsigned char result);

int main()
{
	unsigned char x = 181;
	unsigned char mask = (1U << 2) - 1;
	unsigned char result = 0;
	toString(x, mask, result);

	result = x & mask;
	toString(x, mask, result);

	// Note: I said this is similar to what you are doing
	// in your project (and it is), but you won't be hard-coding
	// numbers because you can't assume anything about
	// the size of an int. Make sure you read the project
	// carefully.

	mask = mask << 2;
	result = result << 2;
	result = result | ((x & mask) >> 2);
	toString(x, mask, result);

	mask <<= 2;
	result <<= 2;
	result = result | ((x & mask) >> 4);
	toString(x, mask, result);

 	mask <<= 2;
	result <<= 2;
	result = result | ((x & mask) >> 6);
	toString(x, mask, result);

	printf("x: %u\n", x);
	printf("result: %u\n", result);
}

/**
 * Just a helpful function for printing all values
 */
void toString(unsigned char x, unsigned char mask, unsigned char result) {
	printf("x: "); visualize(x);
	printf("mask: "); visualize(mask);
	printf("result: "); visualize(result);
	printf("\n");
}

/**
 * Prints the bits of x. Does not build and return a string.
 * Doing so is little more involved in C (compared to Java).
 */
void visualize(unsigned char x)
{
	int i;
	for(;;) { /* FINISH ME */
		if() { /* FINISH ME*/
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

/**
 * Check if the ith bit of ch is set (e.g. 1).
 * Returns > 0 if the bit is set, 0 if it is not set.
 */
unsigned char isBitISet(unsigned char ch, int i)
{
    unsigned char mask = 1U << i;
    return mask & ch;
}
