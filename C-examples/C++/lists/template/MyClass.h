
#include <iostream>
using namespace std;

/*

    Include the file MyClass.cc wherever you invoke the template
    for this class.
*/

template<class T> class MyClass
{
public:
    MyClass();
    void print(T obj);
};


template<class T> MyClass<T>::MyClass(void)
{}


template<class T> void MyClass<T>::print(T obj)
{
    cout << obj << endl;
}
