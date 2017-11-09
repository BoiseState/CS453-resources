#include <stdio.h>
/*
 * @author Aza Tulepbergenov
 */

#define MAX_CHAR 127 //ASCII total number of characters

int main()
{
    int c; //character
    int character_set [MAX_CHAR];

    /*cleans the array by assigining 0 to each element.*/
    cleanArray(character_set);

    /*Populates character array, that is records the frequency of each char.*/
    while ((c=getchar()) != EOF) {
        ++character_set[c];
    }
    /*Prints frequencies of each character*/
    printOutput(character_set);
    return (0);
}

/*
 *@args int digits[] array that contain digits
 *Cleans array by assigning 0's to each element of array.
 *
 */
void cleanArray(int array[])
{
    int index;
    for (index = 0; index < MAX_CHAR; index ++) {
        array[index] = 0;
    }
    return array;
}

/*
 * @args array
 * Prints the frequencies of each character in the array.
 */
void printOutput(int array[])
{
    int index;
    for (index = 0; index < MAX_CHAR; index ++) {
        if (array[index] != 0) {
            printf("%c: %d\n", index, array[index]);
        }
    }
}




