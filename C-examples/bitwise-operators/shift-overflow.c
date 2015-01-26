/* C-examples/bitwise-operators/shift-overflow.c */

#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char maxc = 255;

    unsigned char c = maxc << 1;
    printf("%u << %u : unsigned char c = %u\n", maxc, 1, c);

    unsigned int i = maxc << 1;
    printf("%u << %u : unsigned int i = %u\n", maxc, 1, i);

    return 0;
}
