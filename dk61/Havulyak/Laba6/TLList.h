#ifndef TLList_h
#define TLList_h

#include <stdio.h>

typedef struct __DoubleNode DoubleNode; //Describe in TLNode.h

typedef struct __DoubleList
{
	DoubleNode *head;
	DoubleNode *tail;
	int count;
}DoubleList;

DoubleList *TLCreateList();
void TLFreeList(DoubleList *aList);
DoubleNode *TLAddNode(DoubleList *aList, DoubleNode *aNewNode);
int TLCountList(const DoubleList *aList);

void AddNodeAtIndex(DoubleList *aList, DoubleNode *aNewNode, int anIndex);
void DeleteNodeAtIndex(DoubleList *aList, int anIndex);
DoubleNode *NodeAtIndex(const DoubleList *aList, int anIndex); 


#endif
