#include <stdio.h>

/**
 * Debug this using GDB. Make sure to compile with -g flag.
 *
 * Use the following GDB command to print the value of z in binary form.
 *
 *   (gdb) print /t z
 *
 * (the 't' stands for two).
 */
int main(int argc, char *argv[])
{
    unsigned int x = 0x0000FFFF; //00000000 00000000 111111111 1111111
    unsigned int y = 0xFF00FF00; //11111111 00000000 11111111 00000000

    unsigned int z = 0;

    z = ~x;
    z = x & y;
    z = x | y;
    z = x ^ y;

    return 0;
}
