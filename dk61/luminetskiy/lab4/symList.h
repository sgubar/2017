#ifndef symList_h
#define symList_h

#include "TestSymmetricNode.h"

typedef struct charListTag charList;


typedef struct charListTag
{
    charNode *left;
    charNode *right;
    int count;
}charList;

charList *CreateCharList(); //create interface

void DestroyCharList(charList *listToBeDeleted); //destroy interface

charNode *InsertNodeTolist(charList *inputList, charNode *TheNewNode);

void printCharList(const charList *inputList);


int NodeCompare_FindSymmetric(charList *inputList);

//do list
void ListWork();

#endif //symList_h
