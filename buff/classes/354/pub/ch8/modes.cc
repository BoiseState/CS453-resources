// g++ -Wall -o modes modes.cc && ./modes

#include <iostream>

using namespace std;

static void p(int a, int& b, int* c) {
  a=11;
  b=12;
  *c=13;
}

int main() {
  int x=1;
  int y=2;
  int *z=new(int);
  *z=3;
  p(x,y,z);
  cout << "x=" << x << " y=" << y << " z=" << *z << endl;
  return 0;
}
