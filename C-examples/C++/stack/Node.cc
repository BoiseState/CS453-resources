
#include "Node.h"

/*

	Implementation of the Node class.
*/

Node::Node(char *obj) {
    data = obj;
    next = NULL; // defined to be the value 0
}

void Node::setData(char *obj) {
    data = obj;
}

char *Node::getData() {
    return data;
}

string Node::toString() {
    string *s = new string(data,1);
    return  *s;
}

void Node::setNext(Node *nextPtr) {
    next = nextPtr;
}

Node *Node::getNext() {
    return next;
}

