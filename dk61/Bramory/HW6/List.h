//	List.h

#ifndef List_h
#define List_h

#include <stdio.h>

// Node description
typedef struct tagNode IntNode;

struct tagNode
{
	IntNode *prev;
	IntNode *next;
	int value;
};

// List description
typedef struct tagList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

// Interface
IntList *CreateIntList(void);
void DestroyIntList(IntList *aList);

// -1 if the value was not added to the list
// otherwise 0
int AddIntValueToList(IntList *aList, int anIntValue);

// -1 if the value was not added to the list
// otherwise 0
int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);

// MaxInteger if value is not found
// otherwise 'int' value
int IntValueAtIndex(IntList *aList, int anIndex);

// print list
void PrintList(IntList *aList);

//
int DeleteIntValueAtIndex(IntList *aList, int anIndex);

//
IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex);

int random(int N);
#endif /* IntList_h */
