//
//  TLIntList.h
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>

// Node description
typedef struct __tagIntNode CharNode;

struct __tagIntNode
{
	char value;
	CharNode *next;
};

// List description
typedef struct __tagIntList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

// Interface
CharList *TLCreateCharList();
void TLDestroyIntList(CharList *aList);

// -1 if the value was not added to the list
// otherwise 0
int TLAddCharSymbolToList(CharList *aList, char *anCharSymbol);

// -1 if the value was not added to the list
// otherwise 0
int TLIntValueAtIndex(CharList *aList, int anIndex);

// MaxInteger if value is not found
// otherwise 'int' value
int TLInsertCharSymbolAtIndex(CharList *aList, char *anCharValue, int anIndex);

int LT_ExtractCharNode(CharList *aList,int anIndex);

// print list
void TLPrintList(CharList *aList);


void quickSort(int anArray[], int aLeftIndex, int aRightIndex);

void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex);

int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);


//void bubbleSort(CharList *anArray);

#endif /* TLIntList_h */
