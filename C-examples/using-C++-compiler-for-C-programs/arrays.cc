

/*
 * Example to illustrate pointers/arrays magic  in C/C++
 *
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
    // one dimensional arrays
    int A[100];
    for (int i=0; i<100; i++)
        A[i] = i;

    // B points to an array of 100 int's
    int *B = new int[100];
    int n = 10;
    int *C = new int[n]; // C points to an array of n int's

    int *tmp = B;
    B = C;
    C = tmp; // swap B and C

    // delete the arrays that B and C point to
    delete [] B;
    delete [] C;


    // two dimensional arrays
    int **X = new int*[n];
    for (int i=0; i<n; i++)
        X[i] = new int[n];


    // initialize the 2-dimensional array
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            X[i][j] = i;

    // print out the 2-dimensional array
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout <<  " " << X[i][j];
        cout << "\n";
    }


    // delete the 2-dimensional array X
    for (int i=0; i<n; i++)
        delete [] X[i];
    delete [] X;

    //create  triangular shaped 2-dimensional array
    int **Y = new int*[n];
    for (int i=0; i<n; i++)
        Y[i] = new int[i+1];


    // initialize the triangular array
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            Y[i][j] = (i)*(i+1)/2 + j + 1;

    // print out the triangular array
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cout << setw(3) << Y[i][j];
        }
        cout << "\n";
    }

    // delete the 2-dimensional array Y
    for (int i=0; i<n; i++)
        delete [] Y[i];
    delete [] Y;

    exit(0); // normal termination
}
