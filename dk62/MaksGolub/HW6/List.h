#ifndef List_h
#define List_h
#include <stdio.h>

// Predeclaration

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
void DeleteElementAtIndex(DoubleList *aList, int anIndex);
void AddNodeAtIndex(DoubleList *aList, DoubleNode *aNewNode, int anIndex);
double mediana(DoubleList *aList, int aLeftIndex, int aRightIndex);
int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot);
void quickSort2(DoubleList *aList, int aLeftIndex, int aRightIndex);
void m_manualSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

#endif 
