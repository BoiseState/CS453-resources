// C++ sum program

#include <iostream>

using namespace std;

static int sum(int* seq, int n) {
  int s=0;
  while (n--)
    s+=*seq++;
  return s;
}

int main() {
  const int n=6;
  int* seq=new int[n];
  seq[0]=5; seq[1]=6; seq[2]=1; seq[3]=8; seq[4]=3; seq[5]=7;
  cout << sum(seq,n) << endl;
  delete[] seq;
  return 0;
}

