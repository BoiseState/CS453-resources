
#include "Node.h"

class List
{
private:
    Node * head;
public:
    List();

    bool isEmpty();

    void print();

    void insertAtFront(char *obj);

    void insertAtRear(char *obj);

    Node *removeFirst();

    Node *removeLast();
};
