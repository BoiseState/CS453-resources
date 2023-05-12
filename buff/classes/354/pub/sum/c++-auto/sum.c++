// C++ sum program

#include <iostream>

using namespace std;

static int sum(int seq[], int n) {
  int s=0;
  for (int i=0; i<n; i++)
    s+=seq[i];
  return s;
}

int main() {
  int seq[]={5,6,1,8,3,7};
  const int n=6;
  cout << sum(seq,n) << endl;
  return 0;
}

