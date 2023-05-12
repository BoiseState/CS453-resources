// gcc -o temp temp.c && ./temp

int main() {
  typedef int Celsius;
  typedef int Fahrenheit;
  Celsius c=0;
  Fahrenheit f=32;
  f=c;
  // meltdown...
  return 0;
}
