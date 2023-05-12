// not yet...
// g++ -std=c++14 -o template-var template-var.cc && ./template-var

#include <iostream>
#include <string>

using namespace std;

template<typename T>
constexpr T pi = T(3.1415926535897932385);
     
template<typename T>
T circular_area(T radius) {
  return pi<T>*radius*radius;
}

int main() {
  double d=circular_area(2.3);
  int i=circular_area(2);
  cout << "d=" << d << endl;
  cout << "i=" << i << endl;
  return 0;
}
