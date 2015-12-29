
#include "Node.h"

/*

	Implementation of the Node class.
*/

template<class T> Node<T>::Node(T *obj) {
    data = obj;
    next = NULL; // defined to be the value 0
}

template<class T> void Node<T>::setData(T *obj) {
    data = obj;
}

template<class T> T *Node<T>::getData() {
    return data;
}

template<class T> string Node<T>::toString() {
    return  (*data).toString();
}

template<class T> void Node<T>::setNext(Node *nextPtr) {
    next = nextPtr;
}

template<class T> Node<T> *Node<T>::getNext() {
    return next;
}

