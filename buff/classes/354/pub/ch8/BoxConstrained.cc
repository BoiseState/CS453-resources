// g++ -Wall -o BoxConstrained BoxConstrained.cc && ./BoxConstrained

#include <string>
#include <iostream>

using namespace std;

#include "Constraint.h"
#include "Value.h"

template <class Item>
class BoxConstrained {
  Item item;
 public:
  void put(Item item) {
    this->item=item;
  }
  Item get() {
    return item.foo();		// Item is required to provide foo()
  }
};

int main() {
  string s="stuff";
  Value<string> v(s);
  BoxConstrained< Value<string> >* box=
    new BoxConstrained< Value<string> >();
  box->put(v);
  cout << box->get() << endl;
  return 0;
}
