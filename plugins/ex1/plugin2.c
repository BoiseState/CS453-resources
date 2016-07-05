/* Author: Dan Crow
 * Email:  dcrow@onyx.boisestate.edu
 *
 * File:     plugin2.c
 * Others:   runplug.c plugin1.c
 * Puropose: Tries to be a plug-in.
 * Compile:
 * gcc -Wall -c plugin2.c
 * gcc -shared -lc -o plugin2.so plugin2.o
 */

#include <stdio.h>

void plugin(void)
{
    printf("This is the second plug-in\n");
}

