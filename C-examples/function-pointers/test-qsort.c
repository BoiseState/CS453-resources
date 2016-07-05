
/* C-examples/function-pointers/test-qsort.c */

#include <stdlib.h>
#include <stdio.h>

/*
 * Custom compare function for qsort.
 *
 * Returns an integer less than, equal to, or greater than zero if the first
 * int is considered to be respectively less than, equal to, or greater
 * than the second.
 */
int compareInt(const void *x, const void *y)
{
    return ((*(int *)x) - (*(int *)y));

    /* the statement above produces the same result as the following */
    /*
        int *i = (int *)x;
        int *j = (int *)y;
        if (*i == *j) return 0;
        if (*i < *j) return -1;
        if (*i > *j) return +1;
    */
}

struct student {
    int id;
    char *name;
    char *address;
};

/*
 * Custom compare function for qsort.
 *
 * Returns an integer less than, equal to, or greater than zero if the first
 * id is considered to be respectively less than, equal to, or greater
 * than the second.
 */
int compareId(const void *x, const void *y)
{
    int key1, key2;
    key1 = ((struct student *)x)->id;
    key2 = ((struct student *)y)->id;
    return (key1 - key2);
    /* return (((struct student *)x)->id - ((struct student *)y)->id); */
}

int main(int argc, char **argv)
{
    int n;
    int i;
    int *array;
    struct student *roster;

    if (argc != 2) {
        fprintf(stderr, "Usage:  %s  <n>\n",  argv[0]) ;
        exit(1);
    }

    n = atoi(argv[1]);

    // Show how to use qsort to sort an array of random ints.
    array = (int *) malloc(sizeof(int)*n);

    srandom(0);
    for (i=0; i<n; i++) {
        array[i] = random() % 1000;
    }

    printf("unsorted array\n");
    for (i=0; i<n; i++)
        printf(" %d \n", array[i]);
    printf("\n");

    qsort(array, n, sizeof(int), compareInt);

    printf("sorted array\n");
    for (i=0; i<n; i++)
        printf(" %d \n", array[i]);
    printf("\n");


    // Show how to use same qsort to sort an array of student structs.
    roster = (struct student *) malloc(sizeof(struct student)*n);
    for (i=0; i<n; i++) {
        roster[i].id = n-i;
        roster[i].name = NULL;
        roster[i].address = NULL;
    }

    printf("unsorted array\n");
    for (i=0; i<n; i++)
        printf(" %d %s\n", roster[i].id, roster[i].name);
    printf("\n");

    qsort(roster, n, sizeof(struct student), compareId);

    printf("sorted array\n");
    for (i=0; i<n; i++)
        printf(" %d %s\n", roster[i].id, roster[i].name);
    printf("\n");

    exit(0);
}
