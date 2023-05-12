// g++ -o default default.cc && ./default

#include <iostream>

using namespace std;

static void f(int a=1, int b=2, int c=3) {
  cout << a << " " << b << " " << c << endl;
}

int main() {
  f();
  f(10);
  f(10,20);
  f(10,20,30);
  return 0;
}
