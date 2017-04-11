//
//  TLIntList.h
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>

// Node description
typedef struct __tagIntNode IntNode;

struct __tagIntNode
{
	int value;
	IntNode *prev;
	IntNode *next;
};

// List description
typedef struct __tagIntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

// Interface
IntList *TLCreateIntList();
void TLDestroyIntList(IntList *aList);

// -1 if the value was not added to the list
// otherwise 0
int TLAddIntValueToList(IntList *aList, int anIntValue);

// -1 if the value was not added to the list
// otherwise 0
int TLInsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);

// MaxInteger if value is not found
// otherwise 'int' value
int TLIntValueAtIndex(IntList *aList, int anIndex);

// print list
void TLPrintList(IntList *aList);

#endif /* TLIntList_h */
