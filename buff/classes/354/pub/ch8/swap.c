// gcc -E -o swap.i swap.c

#define SWAP(t, x, y) {t temp=x; x=y; y=temp;}

int main() {
  int i=1;
  int a[]={10,20,30};
  SWAP(int,i,a[i]);
  return 0;
}
