// g++ -o temp2 temp2.cc Celsius.cc Fahrenheit.cc && ./temp2

#include "Celsius.h"
#include "Fahrenheit.h"

#include <iostream>
using namespace std;

int main() {
  Celsius c(0);
  Fahrenheit f(32);
  Celsius c1=f;				// legal: no meltdown
  Fahrenheit f1=c;			// legal: no meltdown
  cout << c1 << "C" << " " << f1 << "F" << endl;
  return 0;
}
