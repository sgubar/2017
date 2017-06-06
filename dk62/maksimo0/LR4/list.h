//
//  list.h
//  LR4
//
//  Created by Maxim Salim on 05.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#ifndef list_h
#define list_h
#include<stdio.h>

typedef struct __tagIntNode IntNode;

struct __tagIntNode
{
    int value;
    IntNode *prev;
    IntNode *next;
};

typedef struct __tagIntList
{
    IntNode *head;
    IntNode *tail;
    int count;
}IntList;

IntList *CreateIntList();

void DestroyIntList(IntList *aList);

int AddIntValueToList(IntList *aList, int anIntValue);

IntNode *TheMinNode(IntList *aList);

void PrintList(IntList *aList);

#endif
