#include "WordObj.h"

WordObjPtr createWordObj(const char *word, const unsigned long int frequency)
{
    WordObjPtr wordObj = (WordObjPtr) malloc(sizeof(WordObj));
    wordObj->frequency = frequency;
    wordObj->word = (char *) malloc(sizeof(char) * (strlen(word) + 1));
    strncpy(wordObj->word, word, strlen(word) + 1);
    return wordObj;
}

char *toString(const void *obj)
{
    WordObjPtr wordObj = (WordObjPtr) obj;

    int maxLength = strlen(wordObj->word) + 2 + MAX_FREQ_DIGITS;
    char *returnString = (char *) malloc(sizeof(char) * maxLength);

    snprintf(returnString, maxLength, "%s %lu", wordObj->word, wordObj->frequency);

    return returnString;
}

void freeWordObj(void *obj)
{
    WordObjPtr wordObj = (WordObjPtr) obj;
    free(wordObj->word);
    free(wordObj);
}

boolean equals(const void *obj1, const void *obj2)
{
    WordObjPtr wordObj1 = (WordObjPtr) obj1;
    WordObjPtr wordObj2 = (WordObjPtr) obj2;

    if (strcmp(wordObj1->word, wordObj2->word) == 0)
        return true;
    else
        return false;
}
