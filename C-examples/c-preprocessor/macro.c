/* lab/C-examples/c-preprocessor/macro.c */

#include <stdio.h>

// Determines max value of a and b
#define max(a,b) ((a)>(b) ? (a) : (b))

int main(int argc, char *argv[])
{
    double dSmall = 2, dBig = 100;
    int iSmall = 2, iBig = 100;
    char cSmall = 'a', cBig = 'z';

    printf("max(%.2f,%.2f) = %.2f\n", dSmall, dBig, max(dSmall, dBig));
    printf("max(%d,%d) = %d\n", iSmall, iBig, max(iSmall, iBig));
    printf("max(%c,%c) = %c\n", cSmall, cBig, max(cSmall, cBig));

    return 0;
}
