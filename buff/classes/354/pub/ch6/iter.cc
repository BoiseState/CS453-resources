// g++ -g -Wall -o iter iter.cc && ./iter

#include <iostream>

using namespace std;

class Foo {
  int i;
  int n;
public:
  void init(int max) { i=1; n=max; }
  bool done()        { return i>n; }
  void next()        { i++; }
  int item()         { return i; }
};

int main() {
  Foo foo;
  for (foo.init(10); !foo.done(); foo.next())
    cout << foo.item() << endl;
}
