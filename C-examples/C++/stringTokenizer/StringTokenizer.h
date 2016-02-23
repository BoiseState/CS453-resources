#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include <string>
#include <string.h> //for strtok
using namespace std;

class StringTokenizer
{
private:
    string inputStr;
    string delimiter;
    char *s;
    const char* delim;
    char * token;
    int tokenLength;
public:
    StringTokenizer(string inString, string delimiter);
    string *nextToken();
};

#endif //STRING_TOKENIZER_H
