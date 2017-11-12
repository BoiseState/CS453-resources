/* C-examples/bitwise-operators/getbits.c */

#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(unsigned int, unsigned int, unsigned int);

int main(int argc, char *argv[])
{
    unsigned int x, n, p, result;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <x> <position> <field-width>\n", argv[0]);
        return 1;
    } else {
        x = (unsigned int) atoi(argv[1]);
        p = (unsigned int) atoi(argv[2]);
        n = (unsigned int) atoi(argv[3]);
    }

    result = getbits(x, p, n);
    printf("x = %d 0x%X result: %d 0x%X\n", x, x, result, result);
    return 0;
}

/*
 * Returns the right adjusted n-bit field of x that begins
 * at position p.
 *
 * e.g. x = 45, n = 3, p = 4
 *
 *      x = 00101101
 *                 ^
 *                 0th bit position
 *
 *  Expected result = 00000011 = 3
 *
 */
unsigned int getbits(unsigned int x, unsigned int p, unsigned int n)
{
    return (x >> (p+1-n)) & ~(~0U << n);
}

/*
 * Step 1: Shift the target field all the way to the right.
 *
 *    (x >> (p+1-n)) = (00101101) >> 2
 *                   = 00001011
 *
 * Step 2: Mask off the last n bits of result from step 1.
 *
 *    00001011 & ~(~0 << n)  = 00001011 & ~(11111111 << 3)
 *                           = 00001011 & ~(11111000)
 *                           = 00001011 & 00000111
 *                           = 00000011
 */
