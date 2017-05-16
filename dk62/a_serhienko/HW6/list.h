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
int AddfloatValueToList(floatList *aList, float floatValue);

// -1 if the value was not added to the list
// otherwise 0
Node* InsertfloatValueAtIndex(const floatList *aList, Node * NewNode, int Index);


Node *floatNodeAtIndex(const floatList *aList, int anIndex);
float floatValueAtIndex(const floatList *aList, int Index);
void dotestList();
// print list
void PrintList(floatList *aList);
int CountList(const floatList *aList);
void DeleteElement(floatList *aList);
Node* DeleteElementAtIndex(floatList *aList, int Index);

#endif /* TLIntList_h */
