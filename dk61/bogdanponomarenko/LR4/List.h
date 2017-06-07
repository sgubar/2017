#ifndef List_h
#define List_h
#include <stdio.h>



typedef struct __DoubleNode DoubleNode;

typedef struct __DoubleList
{
	
	DoubleNode *head;
	DoubleNode *tail;
	int count;
	
}DoubleList;

DoubleList *CreateList();
void FreeList(DoubleList *aList);
DoubleNode *AddNode(DoubleList *aList, DoubleNode *aNewNode);
DoubleNode *NodeAtIndex(DoubleList *aList, int anIndex);
int CountList(DoubleList *aList);
void PrintList(DoubleList *aList);
void BackPrintList(DoubleList *aList);



typedef struct __DoubleNode DoubleNode;


struct __DoubleNode

{
	double value;
	DoubleNode *next;
	DoubleNode *prev;
};

DoubleNode *CreateNodeWithValue(double aValue);
void FreeNode(DoubleNode *aNode);

void List();
#endif 
