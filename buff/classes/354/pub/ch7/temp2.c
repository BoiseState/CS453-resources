// gcc -o temp2 temp2.c && ./temp2

int main() {
  typedef struct { int c; } Celsius;
  typedef struct { int f; } Fahrenheit;
  Celsius c={0};
  Fahrenheit f={32};
  f=c;				// illegal: no meltdown
  return 0;
}
