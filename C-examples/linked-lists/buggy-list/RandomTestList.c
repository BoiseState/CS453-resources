
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "Job.h"
#include "Node.h"
#include "List.h"


const int NUM_TESTS = 6;
/*const int DEBUG = 2;*/
const int DEBUG = 0;


void runRandomTests(int count, unsigned int seed, int n, struct list* list)
{
    int i;
    int test;
    struct node* node;
    struct job* job;

    srandom(seed);
    for (i=0; i<count; i++) {
        test = random() % NUM_TESTS;
        switch (test) {
        case 0:
            if (DEBUG > 1) fprintf(stderr,"addAtFront\n");
            n++;
            job = createJob(n, "some info");
            node = createNode(job);
            addAtFront(list, node);
            break;
        case 1:
            if (DEBUG > 1) fprintf(stderr,"addAtRear\n");
            n++;
            job = createJob(n, "some info");
            node = createNode(job);
            addAtRear(list, node);
            break;
        case 2:
            if (DEBUG > 1) fprintf(stderr,"removeFront\n");
            node = removeFront(list);
            break;
        case 3:
            if (DEBUG > 1) fprintf(stderr,"removeRear\n");
            node = removeRear(list);
            break;
        case 4:
            if (DEBUG > 1) fprintf(stderr,"removeNode\n");
            node = removeNode(list, search(list, i));
            break;
        case 5:
            if (DEBUG > 1) fprintf(stderr,"reverseList\n");
            reverseList(list);

        default:
            break;
        }
    }
}

int main(int argc, char **argv)
{
    int i;
    int n;
    int count;
    unsigned int seed;

    struct node* node;
    struct job* job;
    struct list* list;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list size> [<test size=list size>] [<seed>] \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    count = n;
    if (argc >= 3) {
        count = atoi(argv[2]);
    }
    if (argc == 4) {
        seed = atoi(argv[3]);
    }

    list = createList();
    for (i=0; i<n; i++) {
        job = createJob(i, "args");
        node = createNode(job);
        addAtFront(list, node);
    }

    runRandomTests(count, seed, n, list);

    if (DEBUG > 0)
        printList(list);
    exit(0);
}

/* vim: set tabstop=4: */
