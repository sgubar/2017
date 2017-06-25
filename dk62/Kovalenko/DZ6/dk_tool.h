#ifndef dk_tool_h
#define dk_tool_h
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

IntNode *IntValueAtIndex(IntList *aList, int anIndex);

void PrintList(IntList *aList);

int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);

void DeleteIntValueAtIndex(IntList *aList, int anIndex);

void quickSort(IntList *aList, int aLeftIndex, int aRightIndex);

void m_manualSort(IntList *aList, int aLeftIndex, int aRightIndex);

int mediana(IntList *aList, int aLeftIndex, int aRightIndex);

int m_partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);

void swap(IntList *aList, int aLeftIndex, int aRightIndex);

#endif
