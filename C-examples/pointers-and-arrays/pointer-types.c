/* lab/C-examples/pointers-and-arrays/pointer_types.c */

#include <stdio.h>
#include <stdlib.h>

/*
 * Demonstrates address arithmetic for different pointer types.
 */
int main(int argc, char *argv[])
{
    int a = 10;
    void *ptr = &a;

    printf("(void*) ptr: %p\n", ptr);
    printf("((void*) ptr) + 1: %p\n\n", ptr + 1);
    /* printf("value: %d\n", *(ptr + 1)); */

    printf("(char*) ptr: %p\n", (char *) ptr);
    printf("((char*) ptr) + 1: %p\n\n", ((char *) ptr) + 1);
    /* printf("value: %d\n", *((char *)(ptr + 1))); */

    printf("(int*) ptr: %p\n", (int *) ptr);
    printf("((int*) ptr) + 1: %p\n\n", ((int *) ptr) + 1);
    /* printf("value: %d\n", *((int *)(ptr + 1))); */

    printf("(long*) ptr: %p\n", (long *) ptr);
    printf("((long*) ptr) + 1: %p\n\n", ((long *) ptr) + 1);
    /* printf("value: %d\n", *((long *)(ptr + 1))); */

    return 0;
}

