#include "Fahrenheit.h"

Fahrenheit::Fahrenheit(int f) { this->f=f; }
Fahrenheit::operator Celsius() { return (f-32)*5/9; }
ostream& operator<<(ostream &os, const Fahrenheit& o) { return os << o.f; }
