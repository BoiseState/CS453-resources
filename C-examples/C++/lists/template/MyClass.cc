
#include "MyClass.h"


template<class T> MyClass<T>::MyClass(void) {
}


template<class T> void MyClass<T>::print(T obj) {
    cout << obj << endl;
}
