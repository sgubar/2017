#ifndef List_h
#define List_h

#include <stdio.h>

typedef struct __DoubleElement DoubleElement;

typedef struct __DoubleList
{
	DoubleElement *head;
	DoubleElement *tail;
	int count;
}DoubleList;

DoubleList *CreateList();
void doPrintList(const DoubleList *aList);
void AddElementAtIndex(DoubleList *aList, int aValue, int anIndex);
void DeleteElementAtIndex(DoubleList *aList, int anIndex);
DoubleElement *AddElement(DoubleList *aList, int aValue);
DoubleElement *ElementAtIndex(const DoubleList *aList, int anIndex);
int CountList(const DoubleList *aList);
void DeleteElement (DoubleList *aList);
void FreeList(DoubleList *aList);
//void FunkToDellTheSame(DoubleList *aList);

#endif
