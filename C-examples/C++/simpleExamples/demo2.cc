
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	A simple program illustrating some basic C++ features.
*/

// typedef allows us to give new names to a type
// Here the typedef allows us to use String to mean string
typedef string String;

int main(int argc, char *argv[]) {

    String s1 = "hello";
    String s2 = "world";
    cout << s1+ " " + s2 << "\n"; // string concatenation works like Java

    // A character can be appended to a string but not more than one
    // character at a time (other types are not promoted to string type)
    s1 += 'a';
    s1 += ' ';
    s1 += 'b';

    cout << s1+ " " + s2 << endl;
    cout << "Length of the string is " << s1.length() << endl;

    const int COUNT = 10;
    // A fixed declared array
    int B[COUNT];
    for (int i=0; i<COUNT; i++)
        B[i] = i;

    // An asterisk before a variable makes it a reference type
    // A dynamically allocated array
    int *A = new int[COUNT];
    for (int i=0; i<COUNT; i++)
        A[i] = i;

    delete [] A; //free up the space used by the array

    A = new int[2*COUNT];
    for (int i=0; i<2*COUNT; i++)
        A[i] = i;

    delete [] A; //free up the space used by the array

    // while loops, do-while loops, if statements, for loops are
    // the same as Java
    int i=0;
    while (i < COUNT) {
        cout << B[i] << " ";
        i++;
    }
    cout << endl; //endl is a constant equal to \n

    int *ptrToInt = new int[1];
    *ptrToInt = 10; // use an asterisk to dereference a pointer

    delete ptrToInt; // free up the sapce pointed to by ptrToInt

    // read in a bunch of strings until end of input
    vector<String> *temp = new vector<String>();

    String nextWord;

    cout << "Type in strings and end with Control-d" << endl;
    cin >> nextWord;
    while (!cin.eof()) {
        (*temp).insert((*temp).end(), nextWord);
        // The -> operator is a convenient shorthand for (*temp).
        // temp->insert(temp->end(), nextWord);
        cin >> nextWord;
        // use getline(cin, nextWord) to read one line at a time
    }
    int vectorSize = temp->size();
    cout << "Read in " << vectorSize << " words " << endl;

    // print out the vector
    // Note the use of [] to access the elements of the vector
    // is defined (unlike in Java)
    cout << "printing the vector " << endl;
    for (int i=0; i<vectorSize; i++)
        cout << (*temp)[i] << endl;

    // convert vector to an array of strings
    String * data = new String[vectorSize];
    for (int i=0; i<vectorSize; i++)
        data[i] = (*temp)[i];

    // print out the string
    cout << "printing the string array" << endl;
    for (int i=0; i<vectorSize; i++)
        cout << data[i] << endl;
}//main
