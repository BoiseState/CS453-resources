/* C-examples/intro/width.c */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("size of char = %ld \n", sizeof(char));
    printf("size of short = %ld  \n", sizeof(short));
    printf("size of unsigned short  = %ld  \n", sizeof(unsigned short));
    printf("size of int = %ld  \n", sizeof(int));
    printf("size of unsigned int = %ld  \n", sizeof(unsigned int));
    printf("size of long = %ld  \n", sizeof(long));
    printf("size of unsigned long = %ld  \n", sizeof(unsigned long));
    printf("size of float = %ld  \n", sizeof(float));
    printf("size of double = %ld  \n", sizeof(double));
    printf("size of long double = %ld  \n", sizeof(long double));
    return 0;
}
