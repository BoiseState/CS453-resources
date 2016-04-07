
#include "Node.h"


struct node * createNode(struct job * data)
{
    struct node * newNode = (struct node *) malloc (sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

void freeNode(struct node * node)
{
}

struct job * getData(struct node * node)
{
    return node->data;
}

int getDataSize(struct node * node)
{
    return getJobSize(node->data);
}

/*
Function name: checkpointNode
Description: WARNING! Writes a checkpoint for a Node structure to  an output
            stream without any checks. The idea is that some higher level
            class (like List) would call this function after having
            checked for the file output stream to be set properly. We also
            don't check for no space left to write the file...
    Input: node  ---> a pointer to a Node structure that needs to be checkpointed
           fout ---> output file stream

    Output: none
    Side Effects: writes to  a specified output stream

*/

void checkpointNode(struct node *node, FILE *fout)
{
    checkpointJob(node->data, fout);
}



/*
Function name: restoreNode
Description: WARNING! Reads from a binary input stream to rsrtore a Node
            structure. The idea is that some higher level class (like List)
            would call this function after having checked for the file input
            stream to be set properly. We don't check for EOF or other errors
            at this level.

    Input: fin ---> binary input stream

    Output:   ---> a pointer to the restored Node structure
    Side Effects: None outside of the Node structure
*/
struct node * restoreNode(FILE *fin)
{
    struct node * node;
    struct job * data;

    data = restoreJob(fin);
    node = createNode(data);
    return node;
}
