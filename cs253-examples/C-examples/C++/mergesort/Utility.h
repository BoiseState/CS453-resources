
#ifndef UTILITY_H
#define UTILITY_H


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Utility
{
public:

    static string itos(int value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

    static string itos(long long value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

    static string itos(long value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

    static string itos(short value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

    static string itos(float value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

    static string itos(double value)
    {
        ostringstream out; // output string stream
        out << value;
        return out.str();
    }

};

#endif // UTILITY_H
