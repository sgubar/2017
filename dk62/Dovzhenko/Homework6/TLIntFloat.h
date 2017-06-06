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
int TLAddIntValueToList(IntList *aList, float anIntValue);

// -1 if the value was not added to the list
// otherwise 0
int TLInsertIntValueAtIndex(IntList *aList, float anIntValue, int anIndex);

// MaxInteger if value is not found
// otherwise 'int' value
int TLIntValueAtIndex(IntList *aList, int anIndex);

// print list
void TLPrintList(IntList *aList);

#endif /* TLIntList_h */
