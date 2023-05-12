// gcc -o dynarr dynarr.c && ./dynarr

void foo(int size) {
  int a[size];
  a[size/2]=1;
}

int main() {
  foo(1000);
  return 0;
}
