#include <stdio.h>
#include <stdlib.h>
//WE can use the < > notation on Node.h and List.h
//because we set the include directory in the Makefile
#include <Node.h>
#include <List.h>
//Object.h is in THIS directory so we will use quotes
#include "Object.h"

const int NUM_TESTS = 7;
/*const int DEBUG = 2;*/
const int DEBUG = 0;

void print_stats(int *tests)
{
    printf(" ========================\n");
    printf(" Function  #invocations\n");
    printf(" ========================\n");
    printf(" addAtFront  %d \n", tests[0]);
    printf(" addAtRear   %d \n", tests[1]);
    printf(" removeFront %d \n", tests[2]);
    printf(" removeRear  %d \n", tests[3]);
    printf(" removeNode  %d \n", tests[4]);
    printf(" reverseList %d \n", tests[5]);
    printf(" search      %d \n", tests[6]);
    printf(" ========================\n");
}

void runRandomTests(int count, unsigned int seed, int n, struct list* list)
{
    int i;
    int test;
    struct node* node;
    struct object* job;
    struct object* searchJob;
    int *tests;

    tests = (int *) malloc(sizeof(int)*NUM_TESTS);
    for (i=0; i<NUM_TESTS; i++)
        tests[i]=0;
    srandom(seed);
    for (i=0; i<count; i++) {
        test = (int) (NUM_TESTS * (double) rand()/RAND_MAX);
        tests[test]++;
        switch (test) {
        case 0:
            if (DEBUG > 1) fprintf(stderr,"addAtFront\n");
            n++;
            job = createObject(n, "some info");
            node = createNode(job);
            addAtFront(list, node);
            break;
        case 1:
            if (DEBUG > 1) fprintf(stderr,"addAtRear\n");
            n++;
            job = createObject(n, "some info");
            node = createNode(job);
            addAtRear(list, node);
            break;
        case 2:
            if (DEBUG > 1) fprintf(stderr,"removeFront\n");
            node = removeFront(list);
            freeNode(node, freeObject);
            break;
        case 3:
            if (DEBUG > 1) fprintf(stderr,"removeRear\n");
            node = removeRear(list);
            freeNode(node, freeObject);
            break;
        case 4:
            if (DEBUG > 1) fprintf(stderr,"removeNode\n");
            searchJob = createObject(i,"foo");
            node = removeNode(list, search(list, searchJob));
            freeNode(node, freeObject);
            freeObject(searchJob);
            break;
        case 5:
            if (DEBUG > 1) fprintf(stderr,"reverseList\n");
            reverseList(list);
            break;
        case 6:
            if (DEBUG > 1) fprintf(stderr,"searchList\n");
            searchJob = createObject(i,"foo");
            node = search(list, searchJob);
            freeObject(searchJob);
            break;
        default:
            break;
        }
    }
    print_stats(tests);
    free(tests);
}

int main(int argc, char **argv)
{
    int i;
    int n;
    int count;
    unsigned int seed=0;

    struct object* job;
    struct node* node;
    struct list* list;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list size> [<test size=list size>] [<seed>] \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    count = n;
    if (argc >=  3) {
        count = atoi(argv[2]);
    }
    if (argc == 4) {
        seed = atoi(argv[3]);
    }

    list = createList(equals, toString, freeObject);
    for (i=0; i<n; i++) {
        job = createObject(i, "args");
        node = createNode(job);
        addAtFront(list, node);
    }

    runRandomTests(count, seed, n, list);

    if (DEBUG > 0)
        printList(list);

    freeList(list);
    exit(0);
}

/* vim: set tabstop=4: */
