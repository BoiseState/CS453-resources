
#include <iostream>
#include <string>
#include "List.h"


template<class myType> List<myType>::List() {
    head = NULL;
}

template<class myType> bool List<myType>::isEmpty() {
    return head == NULL;
}

template<class myType> void List<myType>::print() {
    if (isEmpty())
        cout << "List is empty";
    Node<myType> *current = head;
    while (current != NULL) {
        cout << (*current).toString() << "\n";
        current = (*current).getNext();
    }
}//print

template<class myType> void List<myType>::insertAtFront(myType *obj) {
    Node<myType> *current =  new Node<myType>(obj);
    (*current).setNext(head);
    head = current;
}

template<class myType> void List<myType>::insertAtRear(myType *obj) {
    if (isEmpty())
        head = new Node<myType>(obj);
    else {
        Node<myType> *current = head;          // Start at head of list
        while ((*current).getNext() != NULL) // Find the end of the list
            current = (*current).getNext();
        (*current).setNext(new Node<myType>(obj));  // Insert the newNode
    }
}

template<class myType> Node<myType>  *List<myType>::removeFirst() {
    Node<myType> *first = head;
    head = (*head).getNext();
    return first;
}

template<class myType> Node<myType>  *List<myType>::removeLast() {
    if (isEmpty())  // empty list
        return NULL;

    Node<myType> *current = head;
    if ((*current).getNext() == NULL) {     // Singleton list
        head = NULL;
        return current;
    }

    Node<myType> *previous = NULL;                // All other cases
    while ((*current).getNext() != NULL) {
        previous = current;
        current = (*current).getNext();
    }
    (*previous).setNext(NULL);
    return current;
}//removeLast

// vim: set tabstop=4:
