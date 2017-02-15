#include <stdio.h>
#include <stdlib.h>

static int count =0;

static void print_it(int size, int *b)
{
    int i;
    for(i = 0; i < size; b++, i++) {
        printf("%p %d\n",b,*b);
    }

}

static void populate(int size, int *b)
{
    int i;
    count++;
    for(i = 0; i < size; b++, i++) {
        *b = i;
    }
}

void not_buggy(int size, int *b)
{
    int z = rand()%10;
    if(z == 5) {
        free(b);
        b = NULL;
    }
    populate(20,b);
    print_it(20,b);
}


int main(void)
{
    int *array = (int*)malloc(sizeof(int)*20);
    for(;;) not_buggy(20,array);
}



