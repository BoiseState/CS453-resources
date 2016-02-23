#include <stdio.h>
/*@author K & R
 * modified by Aza Tulepbergenov
 */

/* print Fahrentehit - Celcius table
for fahr = 0, 20, ..., 300 */
main()
{
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit Celcius\n");
    while (fahr <= upper) {
        celcius = 5 * (fahr -32)/9;
        printf("%3d%12d\n", fahr, celcius);
        fahr = fahr + step;
    }
}

