
#include <string>
#include "PhoneRecord.h"

#ifndef NODE_H
#define NODE_H

/*

    A class to represent one node in a linked list of phone records.
*/
template<class T> class Node
{
private:
    T *data;
    Node *next;

public:
    Node(T *obj);

    void setData(T *obj);

    T *getData();

    string toString();

    void setNext(Node *nextPtr);

    Node *getNext();

};//Node

#endif //NODE_H
