#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>


typedef struct __tagFloatNode FloatNode;

struct __tagFloatNode
{
	float value;
	FloatNode *prev;
	FloatNode *next;
};


typedef struct __tagFloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;


FloatList *TLCreateFloatList();
void TLDestroyFloatList(FloatList *aList);


int TLAddFloatValueToList(FloatList *aList, float anFloatValue);


int TLInsertFloatValueAtIndex(FloatList *aList, float anFloatValue, int anIndex);


float TLFloatValueAtIndex(FloatList *aList, int anIndex);

FloatNode *FindFloatValueAtIndex(FloatList *aList, int anIndex);


void TLPrintList(FloatList *aList);

int TLDestroyFloatValueAtIndex(FloatList *aList, int anIndex);
//void shellSort(FloatList *aList);
//void swap(FloatList *aList, int firstIndex, int secondIndex);
#endif
