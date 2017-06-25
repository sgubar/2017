//
// Created by 28-07-2014 on 20.06.2017.
//

#ifndef UNTITLED_SINGLELINKEDLIST_H
#define UNTITLED_SINGLELINKEDLIST_H

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
    IntNode *head;
    IntNode *tail;
    int count;
}IntList;

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);

//TODO: house work
int SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
int SLRemovedNodeAtIndex(IntList *aList, int anIndex);

#endif //UNTITLED_SINGLELINKEDLIST_H
