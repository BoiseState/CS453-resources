
#ifndef STACK_H
#define STACK_H

#include "List.h"

class Stack: public List
{
public:
    Stack();
    void push(char * obj);
    Node * pop ();
}; //Stack

#endif //STACK_H
