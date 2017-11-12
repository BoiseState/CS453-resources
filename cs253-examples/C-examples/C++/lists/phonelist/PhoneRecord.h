
#ifndef PHONE_RECORD_H
#define PHONE_RECORD_H

#include <string>
using namespace std;

class PhoneRecord
{
private:
    string name;
    string phone;

public:
    PhoneRecord(string s1, string s2)
    {
        name = s1;
        phone = s2;
    }

    string toString()
    {
        return name + " " + phone;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }
};

#endif //PHONE_RECORD_H
