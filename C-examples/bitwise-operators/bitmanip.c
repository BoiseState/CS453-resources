/* C-examples/bitwise-operators/bitmanip.c */

#include <stdio.h>
#include <stdlib.h>

unsigned int isBitISet(unsigned int, int);
unsigned int setBit(unsigned int, int);
unsigned int clearBit(unsigned int, int);
void printResult(int, unsigned int, unsigned int);

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <number> <bit index>\n", argv[0]);
        return 0;
    }

    unsigned int number = (unsigned int) atoi(argv[1]);
    int i = atoi(argv[2]);

    printf("Number: %d (0x%x)\n", number, number);
    printf("Modifying bit: %d\n", i);

    // Check if bit i is set
    unsigned int result = isBitISet(number, i);
    printResult(i, number, result);

    // Set it
    number = setBit(number, i);

    // Make sure it was set
    result = isBitISet(number, i);
    printResult(i, number, result);

    // Clear bit
    number = clearBit(number, i);

    // Make sure it was cleared
    result = isBitISet(number, i);
    printResult(i, number, result);

    return 0;
}

/**
 * Kind of a silly function, but its just a helper to keep
 * the main clean.
 *
 * @param i The bit we checked.
 * @param num The number that we are printing the result for.
 * @param isSet The result we got.
 */
void printResult(int i, unsigned int num, unsigned int isSet)
{
    if(isSet == 0) {
        printf("Bit %d is NOT set (0x%x)\n", i, num);
    } else {
        printf("Bit %d is set (0x%x)\n", i, num);
    }
}

/**
 * Check if the ith bit of ch is set (e.g. 1).
 *
 * Returns > 0 if the bit is set, 0 if it is not set.
 */
unsigned int isBitISet(unsigned int ch, int i)
{
    unsigned int mask = 1U << i;
    return mask & ch;
}

/**
 * Sets the ith bit of ch to 1.
 *
 * Returns ch with the ith bit set to 1.
 */
unsigned int setBit(unsigned int ch, int i)
{
    unsigned int mask = 1U << i;
    return mask | ch;
}

/**
 * Un-implemented. Clears the ith bit ch
 * (e.g. sets it to 0).
 *
 * Returns ch with the ith bit set to 0;
 */
unsigned int clearBit(unsigned int ch, int i)
{
    return 0;
}
