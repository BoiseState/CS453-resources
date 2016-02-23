#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Utility
{
private:
    int width;
public:
    Utility(int width);
    void println(int x);
    void println(float x);
    void println(double x);
    void println(char ch);
    void println(string s, int w);
};

#endif //UTILITY_H
