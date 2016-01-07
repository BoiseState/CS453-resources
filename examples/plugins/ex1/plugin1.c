/* Author: Dan Crow
 * Email:  dcrow@onyx.boisestate.edu
 *
 * File:     plugin1.c
 * Others:   runplug.c plugin2.c
 * Purpose: Tries to be a plug-in.
 * Compile:
 * gcc -Wall -c plugin1.c
 * gcc -shared  -o plugin1.so plugin1.o
 */

#include <stdio.h>

void plugin(void)
{
  printf("This is super cool super secret plug-in 1\n");
}
