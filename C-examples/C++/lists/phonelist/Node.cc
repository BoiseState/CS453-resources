
#include "Node.h"

/*

	Implementation of the Node class.
*/

Node::Node(PhoneRecord *obj) {
    data = obj;
    next = NULL; // defined to be the value 0
}

void Node::setData(PhoneRecord *obj) {
    data = obj;
}

PhoneRecord *Node::getData() {
    return data;
}

string Node::toString() {
    return  data->toString();
}

void Node::setNext(Node *nextPtr) {
    next = nextPtr;
}

Node *Node::getNext() {
    return next;
}

