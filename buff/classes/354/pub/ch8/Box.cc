// g++ -Wall -o Box Box.cc && ./Box

#include <iostream>
#include <string>

using namespace std;

#include "Box.h"

template <class Item> void Box<Item>::put(Item item) {
  this->item=item;
}

template <class Item> Item Box<Item>::get() {
  return item;
}

int main() {
  // or: Box<string> box;
  Box<string>* box=new Box<string>();
  string s="stuff";
  box->put(s);
  cout << box->get() << endl;
  return 0;
}
