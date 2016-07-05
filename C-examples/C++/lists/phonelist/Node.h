
#include <string>
#include "PhoneRecord.h"

/*

    A class to represent one node in a linked list of phone records.
*/
class Node
{
private:
    PhoneRecord *data;
    Node *next;

public:
    Node(PhoneRecord *obj);

    void setData(PhoneRecord *obj);

    PhoneRecord *getData();

    string toString();

    void setNext(Node *nextPtr);

    Node *getNext();

};//Node
