/*
 * strings-ex0.c
 *
 *  Created on: Feb 19, 2014
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main(int argc, char* argv[])
{
    char s0[] = "magma";
    char *s1 = "volcano";
    char s2[MAXLEN];
    char *s3;

    printf("s0: %s\n", s0);
    printf("s1: %s\n\n", s1);

    s1 = s0; // only changes pointer, not copied into memory

    printf("s0: %s\n", s0);
    printf("s1: %s\n\n", s1);

    //s0 = "mango"; /* INVALID */

    s0[2] = 'n';
    s0[3] = 'g';
    s0[4] = 'o';

    printf("s0: %s\n", s0);
    printf("s1: %s\n\n", s1);

    strncpy(s2, s1, 3);

    printf("s1: %s\n", s1);
    printf("s2: %s\n\n", s2);

    s3 = (char*) malloc(sizeof(char) * (strlen(s1) + 1));
    strcpy(s3, s0);  // copies into memory location

    s0[0] = 't';

    printf("s0: %s\n", s0);
    printf("s3: %s\n\n", s3);

    return 0;
}
