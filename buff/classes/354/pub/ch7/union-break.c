// gcc -o union-break union-break.c && ./union-break

#include <stdio.h>

typedef union {
  double d;
  struct {
    // IEEE 754 double-precision binary floating-point format: binary64
    unsigned long int fraction:52;
    unsigned int exponent:11;     	// of two, not ten
    unsigned int sign:1;
  } bits; 
} T;

int main() {
  T v;
  printf("sizeof(double)=%d\n",sizeof(v.d));

  v.d=123e45;
  printf("v.d=%g\n",v.d);
  v.bits.exponent++;		/* d=d*2, by incrementing exponent */
  v.bits.sign^=1;		/* d=-d, by xoring sign */
  printf("v.d=%g\n",v.d);
  return 0;
}
