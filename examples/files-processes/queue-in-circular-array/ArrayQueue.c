
#ifndef __ARRAYQUEUE
#define __ARRAYQUEUE

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct ArrayQueue ArrayQueue;
struct ArrayQueue {
    void **A;
    int length;
    int head;
    int tail;
    int count;
};

ArrayQueue *InitArrayQueue(ArrayQueue *Q, int size)
{
    Q = (ArrayQueue *) malloc(sizeof(ArrayQueue));
    Q->A = (void **) malloc(sizeof(void *)*size);
    Q->length = size; Q->head = 0; Q->tail = 0; Q->count = 0;
    return Q;
}

int enqueue(ArrayQueue *Q, void *x)
{
    if (Q->count == Q->length){ return FALSE; //overflow }
    Q->A[Q->tail] = x;
    Q->count++;
    Q->tail = (Q->tail + 1) % Q->length;
    return TRUE;
}

void *dequeue(ArrayQueue *Q)
{
    void *x;
    if(Q->count <= 0) { return NULL; //underflow }
    x = Q->A[Q->head];
    Q->count--;
    Q->head = (Q->head + 1) % Q->length;
    return x;
}
#endif /* __ARRAYQUEUE */

