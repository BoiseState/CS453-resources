
#include "Stack.h"

/*
	The :List() at the end invokes the constructor from List superclass.
*/
Stack::Stack() : List() {
}

void Stack::push(char *obj) {
    insertAtFront(obj);
}

Node * Stack::pop () {
    return removeFirst();
}

