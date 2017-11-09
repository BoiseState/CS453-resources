
#include "Node.h"

class List
{
private:
    Node * head;
public:
    List();

    bool isEmpty();

    void print();

    void insertAtFront(PhoneRecord *obj);

    void insertAtRear(PhoneRecord *obj);

    Node *removeFirst();

    Node *removeLast();
};
