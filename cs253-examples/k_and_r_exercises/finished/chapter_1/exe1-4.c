#include <stdio.h>
/*
 *@author K & R
 *modified by Aza Tulepbergenov.
*/
main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;

    /* for-loop that goes from lower to upper with a step */
    float i;
    for (i = lower; i < upper; i += step) {
        printf("%3.0f %4.1f\n", i, (9.0/5.0)*i+32);
    }
}

