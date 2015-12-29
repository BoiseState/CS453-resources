
#include "Utility.h"


Utility::Utility(int width) {
    this->width = width;
}

void Utility::println(int x) {
    cout << setw(width) << x << endl;
}

void Utility::println(float x) {
    cout << setw(width) << x << endl;
}

void Utility::println(double x) {
    cout << setw(width) << x << endl;
}

void Utility::println(char ch) {
    cout << setw(width) << ch << endl;
}

void Utility::println(string s, int w) {
    cout << setw(w) << s << endl;
}

