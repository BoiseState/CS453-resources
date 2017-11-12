
#ifndef LIST_H
#define LIST_H

template <class myType> class List
{
private:
    Node<myType> * head;
public:
    List();

    bool isEmpty();

    void print();

    void insertAtFront(myType *obj);

    void insertAtRear(myType *obj);

    Node<myType> *removeFirst();

    Node<myType> *removeLast();
};

#endif //LIST_H
