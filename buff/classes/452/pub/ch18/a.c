// gcc -o a.asm -S a.c
// gcc -o a a.c ; objdump -dS a > a.od ; nm a > a.nm
// gcc -c a.c -Wa,-adhlns=a.l -fverbose-asm

int i,a[10];

int main() {
  for (i=0; i<10; i++)
    a[i]=0;
}
