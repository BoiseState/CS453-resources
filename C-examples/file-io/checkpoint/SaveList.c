
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "Job.h"
#include "Node.h"
#include "List.h"


int main(int argc, char **argv)
{
    int i;
    int n;
    struct node * node;
    struct job * job;
    struct list * list;
    char *saveFile;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list size> [<checkpoint file>] \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    saveFile = NULL;
    if (argc == 3) {
        saveFile = argv[2];
    }

    list = createList();
    for (i=0; i<n; i++) {
        job = createJob(i, "cmd args");
        node = createNode(job);
        addAtFront(list, node);
    }

    /* if (!saveFile) printList(list); */
    printList(list);

    if (saveFile) {
        printf("checkpointing to file %s\n", saveFile);
        checkpointList(list, saveFile);
    }

    exit(0);
}

