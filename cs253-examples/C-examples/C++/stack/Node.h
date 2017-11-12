
#include <string>
using namespace std;

/*

    A class to represent one node in a linked list of phone records.
*/
class Node
{
private:
    char *data;
    Node *next;

public:
    Node(char *obj);

    void setData(char *obj);

    char *getData();

    string toString();

    void setNext(Node *nextPtr);

    Node *getNext();

};//Node
