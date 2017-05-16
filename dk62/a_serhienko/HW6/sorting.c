#include <stdio.h>
#include "sorting.h"
#include "list.h"
#include "node.h"

void ShellSort(floatList*aList, int size)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;


	while (theH <= size / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}


	while (theH > 0)
	{
		for (theOuter = theH; theOuter < size; theOuter++)
		{
			 float theTmp = floatValueAtIndex(aList, theOuter);
			theInner = theOuter;


			while (theInner > theH - 1 && floatValueAtIndex(aList, theInner-theH) >= theTmp)
			{
				swap(aList, theInner, theInner - theH);
				theInner -= theH;
			}

		}

		theH = (theH - 1) / 3;
	}
}


void swap(floatList*aList, int firstindex, int secondindex)
{
	if (firstindex>secondindex)
	{
		int thetmp = firstindex;
		firstindex = secondindex;
		secondindex = thetmp;
	}

	Node *firstNode = floatNodeAtIndex(aList, firstindex);
	Node *secondNode = floatNodeAtIndex(aList, secondindex);
	Node *theTmpPrev = firstNode->prev;
	Node *theTmpNext = secondNode->next;

	

 int checking = firstindex - secondindex;
	if (checking == -1)
	{
		firstNode->next = firstNode->next->next;

		if (secondindex != aList->count - 1)
			secondNode->next->prev = firstNode;

		secondNode->next = firstNode;
		firstNode->prev = secondNode;

		if (firstindex != 0)
			theTmpPrev->next = secondNode;

		secondNode->prev = theTmpPrev;
	}
	else
	{
		//changing pointers for firstNode
		if (secondindex != 0)
			secondNode->prev->next = firstNode;

		firstNode->prev = secondNode->prev;
		firstNode->next = secondNode->next;

		if (aList->count - 1 != secondindex)
			secondNode->next->prev = firstNode;

		//changing pointers for secondNode 
		if (firstindex != 0)
			theTmpPrev->next = secondNode;

		secondNode->prev = theTmpPrev;
		secondNode->next = theTmpNext;

		if (firstindex != aList->count - 1)
			theTmpNext->prev = secondNode;

	}
	

	if (firstindex == 0)
	{
		aList->begin = secondNode;
	}
	if (secondindex == 0)
	{
		aList->end = firstNode;
	}
	if (firstindex == aList->count - 1)
	{
		aList->begin = secondNode;
	}
	if (secondindex == aList->count - 1)
	{
		aList->end = firstNode;
	}
}