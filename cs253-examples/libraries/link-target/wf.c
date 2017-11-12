#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <Node.h>
#include <List.h>

#include "WordObj.h"


const char * delimiters = " 0123456789\t;{}()[].#<>\n\r+-/%*\"^~&=!|:\\?,";
const int MAX_LINE_LENGTH = 2048;

const char *FLAG_ORGANIZED = "--self-organized-list";
const char *FLAG_STD = "--std-list";

void processWord(struct list *, char*);
void printDebug(struct list *, WordObjPtr);
void printWordObj(WordObjPtr);
void parseCommandArgs(char**);
void printUsage(char*, char*, char*);
char *toLower(char *);

boolean isOrganized;
char *filepath;

/* #define DEBUG 1 */

int main(int argc, char **argv)
{
    if(argc != 3) {
        printUsage(argv[0], NULL, NULL);
    } else {
        parseCommandArgs(argv);
    }

    FILE *fin = fopen(filepath, "r");
    if(!fin) {
        perror(filepath);
        exit(errno);
    }

    struct list *list = createList(equals, toString, freeWordObj);
    char buffer[MAX_LINE_LENGTH];
    char *nextWord;
    while(fgets(buffer, sizeof(buffer), fin)) {
        nextWord = strtok(buffer, delimiters);
        while(nextWord != NULL) {
#ifdef DEBUG
            printf("nextWord: %s\n", nextWord);
#endif
            processWord(list, nextWord);
            nextWord = strtok(NULL, delimiters);
        }
    }
    printList(list);
    freeList(list);
    fclose(fin);
	exit(EXIT_SUCCESS);
}

/**
 * If the word is already in the list, increment the frequency
 * of the existing word object. Else, add it to the list.
 *
 * For self-organizing, move the word to the front of the list when
 * it is found. This will improve performance as frequantly occuring
 * words will accumulate in the front of the list.
 */
void processWord(struct list *list, char *word)
{
    word = toLower(word);
#ifdef DEBUG
    printf("processWord: %s\n", word);
#endif

    WordObjPtr wordObj = createWordObj(word, 1);
    struct node *found = search(list, wordObj);
    if(found) {
        ((WordObjPtr)(found->obj))->frequency++;
        freeWordObj(wordObj);
        if(isOrganized) {
            removeNode(list, found);
            addAtFront(list, found);
        }
#ifdef DEBUG
        printDebug(list, (WordObjPtr)(found->obj));
#endif
    } else {
        struct node *node = createNode(wordObj);
        addAtFront(list, node);
#ifdef DEBUG
        printDebug(list, wordObj);
#endif
    }
}

char *toLower(char *word)
{
    int i;
    for(i=0; i < strlen(word) + 1; i++)
        word[i] = tolower(word[i]);
    return word;
}

void printDebug(struct list *list, WordObjPtr wordObj)
{
    printf("================\n");
    printWordObj(wordObj);
    printf("----------------\n");
    printList(list);
}

void printWordObj(WordObjPtr wordObj)
{
    char *toPrint = toString(wordObj);
    printf("%s\n", toPrint);
    free(toPrint);
}

void printUsage(char *progname, char *invalid, char *info)
{
    printf("%s {%s|%s} <textfile>", progname, FLAG_ORGANIZED, FLAG_STD);
    if(invalid) {
        printf("\n\tInvalid argument: %s", invalid);
    }
    if(info) {
        printf(" [%s]", info);
    }
    printf("\n");
    exit(EXIT_FAILURE);
}

void parseCommandArgs(char **argv)
{
    if(strncmp(FLAG_ORGANIZED, argv[1], strlen(FLAG_ORGANIZED)+1) == 0) {
        isOrganized = true;
#ifdef DEBUG
        printf("Using self-organized list...\n");
#endif
    } else if(strncmp(FLAG_STD, argv[1], strlen(FLAG_STD)+1) == 0) {
        isOrganized = false;
#ifdef DEBUG
        printf("Using standard list...\n");
#endif
    } else {
        printUsage(argv[0], argv[1], NULL);
    }
    filepath = argv[2];
}
