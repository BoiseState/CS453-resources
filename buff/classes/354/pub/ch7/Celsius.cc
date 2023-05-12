#include "Celsius.h"

Celsius::Celsius(int c) { this->c=c; }
Celsius::operator Fahrenheit() { return c*9/5+32; }
ostream& operator<<(ostream &os, const Celsius& o) { return os << o.c; }
