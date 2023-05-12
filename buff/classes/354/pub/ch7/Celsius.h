#ifndef CELSIUS_H
#define CELSIUS_H

class Celsius;

#include "Fahrenheit.h"

#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
  int c;
public:
  Celsius(int c);
  operator Fahrenheit();
  friend ostream& operator<<(ostream &os, const Celsius& o);
};

#endif
