
/* C-examples/function-pointers/fun-with-fns.c */
#include <stdio.h>
#include <stdlib.h>

int f0(int x)
{
    printf("f0: I have been invoked!!!! x=%d\n",x);
    return x;
}

int f1(int x)
{
    printf("f1: I have been invoked!!!! x=%d\n",x*2);
    return x;
}

int f2(int x)
{
    printf("f2: I have been invoked!!!! x=%d\n",x*3);
    return x;
}

void fun(int (*fn)(int))
{
    int result;

    result = (*fn) (5);
}


int main(int argc, char **argv)
{
    int i;
    int count=0;
    int seed;
    int (*names[3])(int);

    names[0] = f0;
    names[1] = f1;
    names[2] = f2;

    if (argc != 3) {
        fprintf(stderr,"Usage %s: <count> <seed> \n",argv[0]);
        exit(1);
    }
    count = atoi(argv[1]);
    seed = atoi(argv[2]);

    int (*functionPtr)(int) = f2;

    fun(functionPtr);

    srandom(seed);
    for (i=0; i<count; i++) {
        fun(names[random()%3]);
    }

    exit(0);
}

