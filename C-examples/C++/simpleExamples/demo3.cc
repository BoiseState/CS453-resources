
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    const int BITS = 8;

    cout << "size of short = " << sizeof(short)*BITS <<  " bits. " << endl;
    cout << "size of int = " << sizeof(int)*BITS <<  " bits. " << endl;
    cout << "size of long = " << sizeof(long)*BITS <<  " bits. " << endl;
    cout << "size of char = " << sizeof(char)*BITS <<  " bits. " << endl;
    cout << "size of float = " << sizeof(float)*BITS <<  " bits. " << endl;
    cout << "size of double = " << sizeof(double)*BITS <<  " bits. " << endl;
    cout << "size of long long = " << sizeof(long long)*BITS <<  " bits."
         << endl;
}
