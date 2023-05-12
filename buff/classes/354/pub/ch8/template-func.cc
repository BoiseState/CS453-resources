// g++ -Wall -o template-func template-func.cc && ./template-func

#include <iostream>
#include <string>

using namespace std;

template <class Item> Item foo(Item item) {
  return item;
}

int main() {
  string s="stuff";
  cout << foo(s) << endl;
  return 0;
}
