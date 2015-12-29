
#include <iostream>
#include <string>
#include "StringTokenizer.h"

int main(int argc, char * argv[]) {
    string inputLine;
    getline(cin, inputLine);
    StringTokenizer *tokenizer = new StringTokenizer(inputLine, " ,.:;");
    while (cin) {
        string *token = tokenizer->nextToken();
        while (token != NULL) {
            cout << "next token = " << *token << endl;
            token = tokenizer->nextToken();
        }
        getline(cin, inputLine);
        tokenizer = new StringTokenizer(inputLine, " ,.:;");
    }
}
