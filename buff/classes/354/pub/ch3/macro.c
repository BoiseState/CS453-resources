// gcc -E -o macro.i macro.c

#define ALLOC(t,v)	            \
  t v=(t)malloc(sizeof(*v));        \
  if (!v) printf("malloc() failed")

typedef struct {
  int i;
  double d;
} *Foo;

typedef struct {
  char c;
  float f;
} *Bar;

int main() {
  ALLOC(Foo,foo);
  ALLOC(Bar,bar);
}
