#ifndef list
#define list
#include "node.h"
#include <stdio.h>

// Node description
typedef struct __floatNode Node;

// List description
typedef struct __floatList 
{
	Node *begin;
	Node *end;
	int count;
}floatList;

// Interface
floatList *CreatefloatList();
void DestroyfloatList(floatList *aList);

// -1 if the value was not added to the list
// otherwise 0
Node* AddfloatValueToList(floatList *aList, Node *aNewNode);

// -1 if the value was not added to the list
// otherwise 0
Node* InsertfloatValueAtIndex(const floatList *aList, Node * NewNode, int Index);

// MaxInteger if value is not found
// otherwise 'int' value
Node* floatValueAtIndex(const floatList *aList, int Index);

// print list
void PrintList(floatList *aList);
int CountList(const floatList *aList);

void DeleteElementAtIndex(floatList *aList, int Index);

#endif /* TLIntList_h */
