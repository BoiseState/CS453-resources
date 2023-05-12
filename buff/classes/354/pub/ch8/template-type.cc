// g++ -Wall -o template-type template-type.cc && ./template-type

#include <iostream>
#include <string>

using namespace std;

template <class Item> struct Record {
  typedef struct { Item item; } Rec;
};

int main() {
  Record<string>::Rec record;
  string s="stuff";
  record.item=s;
  cout << record.item << endl;
  return 0;
}
