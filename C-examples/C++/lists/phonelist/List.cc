
#include <iostream>
#include <string>
#include "List.h"


List::List() {
    head = NULL;
}

bool List::isEmpty() {
    return head == NULL;
}

void List::print() {
    if (isEmpty())
        cout << "List is empty" << endl;
    Node *current = head;
    while (current != NULL) {
        cout << current->toString() << "\n";
        current = current->getNext();
    }
}//print

void List::insertAtFront(PhoneRecord *obj) {
    Node *current =  new Node(obj);
    current->setNext(head);
    head = current;
}

void List::insertAtRear(PhoneRecord *obj) {
    if (isEmpty())
        head = new Node(obj);
    else {
        Node *current = head;          // Start at head of list
        while (current->getNext() != NULL) // Find the end of the list
            current = current->getNext();
        current->setNext(new Node(obj));  // Insert the newNode
    }
}

Node  *List::removeFirst() {
    Node *first = head;
    head = head->getNext();
    return first;
}

Node  *List::removeLast() {
    if (isEmpty())  // empty list
        return NULL;

    Node *current = head;
    if (current->getNext() == NULL) {     // Singleton list
        head = NULL;
        return current;
    }

    Node *previous = NULL;                // All other cases
    while (current->getNext() != NULL) {
        previous = current;
        current = (*current).getNext();
    }
    previous->setNext(NULL);
    return current;
}//removeLast

// vim: set tabstop=4:
