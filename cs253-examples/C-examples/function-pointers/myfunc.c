#include <stdio.h>
#include <stdlib.h>

static const int MAX = 10;


void usage(char** argv)
{
    fprintf(stderr,"%s <a = ascending | b = descending>\n",argv[0]);
    exit(0);
}

void ascend(void *a, void *b)
{
    int *first = (int*) a;
    int *second = (int*) b;
    int tmp =0;
    if(*first > *second) {
        tmp = *first;
        *first = *second;
        *second = tmp;
    }

}

void descend(void *a, void *b)
{
    int *first = (int*) a;
    int *second = (int*) b;
    int tmp =0;
    if(*first < *second) {
        tmp = *first;
        *first = *second;
        *second = tmp;
    }
}

void charAscend(void *a, void *b)
{
    char *first = (char*) a;
    char *second = (char*) b;
    char tmp =0;
    if(*first > *second) {
        tmp = *first;
        *first = *second;
        *second = tmp;
    }

}

void charDescend(void *a, void *b)
{
    char *first = (char*) a;
    char *second = (char*) b;
    char tmp =0;
    if(*first < *second) {
        tmp = *first;
        *first = *second;
        *second = tmp;
    }
}

void sort(void *base ,size_t size, int len, void (*swp)(void*, void*))
{
    int i, j;
    for(i = 0; i< len ; i++) {
        for(j = i + 1; j<len ; j++) {
            swp(base + (i * size) , base + (j*size));

        }
    }

}

int main(int argc, char** argv)
{

    if(argc != 2) {
        usage(argv);
    }

    int foo = 0;

    if(argv[1][0] == 'a') {
        printf("sorting ascending\n");
        foo = 1;
    } else if(argv[1][0] == 'b') {
        printf("sorting descending\n");
        foo = 2;
    } else {
        usage(argv);
    }



    int *a = (int*)malloc(sizeof(int)*MAX);
    char *b = (char*)malloc(sizeof(char)*MAX);
    int i;
    srandom(0);
    for(i=0; i<MAX; i++) {
        a[i]= random() % 20;
    }
    for(i=0; i<MAX; i++) {
        b[i]= 65 + (random() % 26);
    }
    printf("Before sort\n");

    for(i=0; i<MAX; i++) {
        printf("b[%d]= %c\n",i,b[i]);
    }

    if(foo ==1 ) {
        sort(a,sizeof(int), MAX,ascend);
        sort(b,sizeof(char),MAX,charAscend);
    } else if(foo ==2) {
        sort(a,sizeof(int), MAX,descend);
        sort(b,sizeof(char),MAX,charDescend);
    }


    printf("----------------------\n");
    printf("After sort\n");

    for(i=0; i<MAX; i++) {
        printf("b[%d]= %c\n",i,b[i]);
    }


    //1. Create an array with randomly initialized data
    //2. Sort our array with a function 2 function pointers
    //  - first compareTo is <
    //  - second compreTo is >

    return 0;
}
