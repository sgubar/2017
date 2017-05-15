//
// Created by Oleg on 15.05.2017.
//

#ifndef LW4_DK_CHECKER_H
#define LW4_DK_CHECKER_H

#include <stdio.h>

// Node description
typedef struct __tagCharNode charNode;

struct __tagCharNode
{
    char value;
    charNode *prev;
    charNode *next;
};

// List description
typedef struct __tagChartList
{
    charNode *head;
    charNode *tail;

    int bracesLeft;
    int bracesRight;

    int squareBracketsLeft;
    int squareBracketsRight;

    int bracketLeft;
    int bracketRight;

    int count;
}charList;

// Interface
charList *createCharList();
void destroyCharList(charList *aList);

// -1 if the value was not added to the list
// otherwise 0
int addCharValueToList(charList *aList, char anCharValue);

void printList(charList *aList);

void checkFile(FILE *aFile);

#endif //LW4_DK_CHECKER_H
