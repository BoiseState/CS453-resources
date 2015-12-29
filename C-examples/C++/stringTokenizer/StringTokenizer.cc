
#include "StringTokenizer.h"


StringTokenizer::StringTokenizer(string inString, string delimiter) {
    this->inputStr = inString;
    this->delimiter = delimiter;

    // create a C-style string from inString
    // A C-style string is an array of char's followed by a
    // null character (which has code 0)
    s = new char[inputStr.length() + 1];
    inputStr.copy(s,string::npos); //npos denotes end of string
    // add terminator null character (reqd. for C-style strings)
    s[inputStr.length()] = 0;

    // get a constant reference to a c-style string for delimiters
    delim = delimiter.c_str();
    // get the first token (s gets modified by strtok()
    token = strtok(s, delim);
}

string *StringTokenizer::nextToken() {
    if (token == (char *) NULL) return NULL;
    tokenLength = strlen(token);
    string *next = new string(token, tokenLength);
    token = strtok(NULL, delim);
    return next;
}

