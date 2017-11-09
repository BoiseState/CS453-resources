

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "Job.h"
#include "Node.h"
#include "List.h"


int main(int argc, char **argv)
{
    struct list * list;
    char *saveFile;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <checkpoint file> \n",argv[0]);
        exit(1);
    }
    saveFile = argv[1];

    list = restoreList(saveFile);
    if (list) {
        printList(list);
    }
    exit(0);
}

