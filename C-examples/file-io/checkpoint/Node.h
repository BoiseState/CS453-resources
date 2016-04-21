
#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "Job.h"

struct node {
    struct job * data;
    struct node * next;
    struct node * prev;
};

struct node * createNode (struct job * data);
void freeNode(struct node * node);
struct job * getData(struct node * node);

int getDataSize();
void checkpointNode(struct node * node, FILE *fout);
struct node * restoreNode (FILE *fin);


#endif /* __NODE_H */
