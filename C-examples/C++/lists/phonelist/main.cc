
using namespace std;

#include <iostream>
#include <string>
#include "List.h"
#include "PhoneRecord.h"


/**
 * main() creates a linked list of different types of objects
 *   and tests this class's methods. This example shows that
 *   a single list can store different types of objects.
 */
int main(int argc, char* argv[]) {
    // Create list and insert heterogeneous nodes
    List list;
    /*List *list = new List();*/

    list.insertAtFront(new PhoneRecord("Bob M", "997-0020"));
    list.insertAtRear(new PhoneRecord("Jane M", "997-2101"));
    list.insertAtRear(new PhoneRecord("Scott K", "997-2517"));

    // Print the list
    cout << "Generic List" << "\n";
    list.print();
    // Remove objects and print resulting list
    Node *node;
    node = list.removeLast();
    cout << " Removed " + node->toString() << endl;
    cout << "The List:" << endl;
    list.print();

    node = list.removeLast();
    cout << " Removed " + node->toString() << endl;
    cout << "The List:" << endl;
    list.print();

    node = list.removeFirst();
    cout << " Removed " + node->toString() << endl;
    cout << "The List:" << endl;
    list.print();
} // main()

