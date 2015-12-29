
#include <stdlib.h>
#include <iostream>

using namespace std;

int compare(const void *x, const void *y) {
    return ((*(int *)x) - (*(int *)y));
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n> " << endl;
        exit(1);
    }

    int n = atoi(argv[1]);
    int *array = new int[n];
    srandom(0);
    for (int i=0; i<n; i++) {
        array[i] = random() % n;
    }

    cout << "unsorted array" << endl;
    for (int i=0; i<n; i++)
        cout << array[i] << endl;
    cout << endl;

    qsort(array, n, sizeof(int), compare);


    cout << "sorted array" << endl;
    for (int i=0; i<n; i++)
        cout << array[i] << endl;
    cout << endl;
}
