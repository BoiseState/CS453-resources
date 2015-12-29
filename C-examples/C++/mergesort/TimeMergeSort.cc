
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "Utility.h"
#include "MergeSort.h"

int getCurrentTimeMillis() {
    struct timeval current;
    gettimeofday(&current, NULL);

    int millisecs = current.tv_sec * 1000 + current.tv_usec/1000;
    return millisecs;
}

int *randomIntArray(int length, int range) {
    int *tmp = new int[length];

    for (int i=0; i<length; i++)
        tmp[i] = random() % range;

    return tmp;
}

void printArray(int *a, int n) {
    for (int i=0; i<n; i++)
        cout << a[i] << endl;
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        cerr << "Usage: java MergeSortTime <n> \n";
        exit(1);
    }
    int n = atoi(argv[1]);

    // construct random array
    int* a = randomIntArray(n, 100);

    /*printArray(a, n);*/

    long startTime = getCurrentTimeMillis();
    MergeSort::sort(a, n);
    long totalTime = getCurrentTimeMillis() - startTime;

    cout << "Elapsed time: " << totalTime/1000.0 << " seconds" << endl;

    /*printArray(a, n);*/
}//main

// vim: set tabstop=4:
