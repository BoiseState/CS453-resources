#ifndef __NODE_H
#define __NODE_H

#include "common.h"
#include "Job.h"

typedef struct node Node;
typedef struct node *NodePtr;

struct node {
    JobPtr data;
    NodePtr next;
    NodePtr prev;
};

NodePtr createNode(const JobPtr data);
void freeNode(const NodePtr node);


#endif /* __NODE_H */
