#include <iostream>
#include <string>
#include"Node.cc"
#include "List.cc"
#include "PhoneRecord.h"


/**
 * main() creates a linked list of different types of objects
 *   and tests this class's methods. This example shows that
 *   a single list can store different types of objects.
 */
int main(int argc, char* argv[]) {
    typedef List<PhoneRecord> PhoneList;
    // Create list and insert heterogeneous nodes
    PhoneList list;
    list.insertAtFront(new PhoneRecord("Bob M", "997-0020"));
    list.insertAtRear(new PhoneRecord("Jane M", "997-2101"));
    list.insertAtRear(new PhoneRecord("Scott K", "997-2517"));

    // Print the list
    cout << "Generic List" << "\n";
    list.print();
    // Remove objects and print resulting list
    /*
    Object o;
    o = list.removeLast();
    System.out.println(" Removed " + o.toString());
    System.out.println("Generic List:");
    list.print();
    o = list.removeLast();
    System.out.println(" Removed " + o.toString());
    System.out.println("Generic List:");
    list.print();
    o = list.removeFirst();
    System.out.println(" Removed " +o.toString());
    System.out.println("Generic List:");
    list.print();
    */
} // main()

