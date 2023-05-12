// -*-C++-*-

#ifndef VALUE_H
#define VALUE_H

#include <string>

using namespace std;

#include "Constraint.h"

template <class Item>
class Value : Constraint<Value <Item> > {
  Item item;
 public:
  Value() {}
  Value(Item item) : item(item) {}
  virtual Value foo() {
    return *this;		// do something foo-ish
  }
  friend ostream& operator<<(ostream& os, const Value& v) {
    return os << v.item;
  }
};

#endif
