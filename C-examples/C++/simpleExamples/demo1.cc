
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // endl is a constant defined to be the newline character
        cerr << "Usage: " << argv[0] << "<arg1> <arg2> ..." << endl;
        exit(1);
    }

    cout << "The command line arguments are: " << "\n";
    for (int i=0; i<argc; i++)
        cout << argv[i] << "\n";

    short b = 32767;
    int i = 10;
    long j = 76764736;
    float x = (float) sqrt(2.0);
    double z = sqrt(2.0);
    bool flag = true;

    cout << b << " " << i << " " << j << endl;
    cout << setprecision(16) <<  x << " " << z << " " << flag << endl;
}
