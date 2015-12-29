
#include <string>
#include "MyClass.h"

int main() {
    MyClass<int> x1;

    x1.print(10);

    MyClass<string> x2;

    x2.print("abracadabra");
}
