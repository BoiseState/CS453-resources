// g++ -o temp temp.cc && ./temp

class Celsius {
public: Celsius(int c): c(c) {}
private: int c;
};

class Fahrenheit {
public: Fahrenheit(int f): f(f) {}
private: int f;
};

int main() {
  Celsius c(0);
  Fahrenheit f(32);
  f=c;				// illegal: no meltdown
  return 0;
}
