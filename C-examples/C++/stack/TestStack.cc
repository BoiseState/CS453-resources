#include <iostream>
#include <string>
#include "Stack.h"


/**
 * main() creates a linked list of different types of objects
 *   and tests this class's methods. This example shows that
 *   a single list can store different types of objects.
 */
int main(int argc, char* argv[]) {
    Stack *stack = new Stack();
    string s = "Hello this is a test string";

    cout << "String: " + s << endl;
    for (unsigned int k = 0; k < s.length(); k++) {
        char *ch = new char[1];
        *ch = s.at(k);
        stack->push(ch); // take the address of the variable ch
    }
    /*cout << "the stack has:" << endl;*/
    /*stack->print();*/

    Node * node;
    string reversed = "";
    while (!stack->isEmpty()) {
        node  = stack->pop();
        reversed = reversed + node->toString();
    }
    cout << "Reversed String: " + reversed << endl;
} // main()

