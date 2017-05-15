#include "List.h"
#include "Element.h"
#include <stdlib.h>


DoubleList *CreateList()
{
	//Allocate memory for the list structure
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));
	//Clean internal data
	theList->head = NULL; //<!- not head
	theList->tail = NULL; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list	
	return theList;
}

void FreeList(DoubleList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}
	//1. Remove all elements
	DoubleElement *theElement = aList->head;
	
	while (NULL != theElement)
	{
		DoubleElement *theElementToBeFree = theElement;
		theElement = theElement->nextElement;
	
		FreeDoubleElement(theElementToBeFree);
	}
	//2. Free memory for the List structure
	free(aList);
}

DoubleElement *AddElement(DoubleList *aList, char *aValue)
{
	DoubleElement *aNewElement = CreateElementWithDoubleLink(aValue);
	// Check the input parameter
	if (NULL == aList || NULL == aNewElement)
	{
		return NULL;
	}	
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewElement;
	}
	else
	{
		DoubleElement *theTail = aList->tail;
		aList->tail = aNewElement;
		aNewElement->previousElement = theTail;
		theTail->nextElement = aList->tail;			
	}
	aList->count += 1;	
	return aNewElement;
}

int CountList(const DoubleList *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

void AddElementAtIndex(DoubleList *aList, char *aValue, int anIndex)
{
	DoubleElement *aNewElement = CreateElementWithDoubleLink(aValue);
	if (NULL != aList && anIndex < aList->count  && NULL != aNewElement)
	{
		int i = 0;
		DoubleElement *theElement = aList->head;
		do
		{
			if (i == anIndex) //<!- index was found
			{				
				DoubleElement *thePreviousElement = theElement->previousElement;
				aNewElement->nextElement = theElement;
				if(NULL != thePreviousElement)
					thePreviousElement->nextElement = aNewElement;
				else
					aList->head = aNewElement;
				aNewElement->previousElement = thePreviousElement;
				theElement->previousElement = aNewElement;				
				aList->count += 1;
				break;
			}		
			i++; // increase index
			theElement = theElement->nextElement; //<! - go to next node		
		} while (NULL != theElement);	
	}
}

void DeleteElementAtIndex(DoubleList *aList, int anIndex)
{
	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleElement *theElement = aList->head;	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				DoubleElement *PreviousElement = theElement->previousElement;
				DoubleElement *NextElement = theElement->nextElement;
				if(NULL != PreviousElement)
						PreviousElement->nextElement = NextElement;	
				else
				{
					aList->head = NextElement;
					if(NULL != NextElement)
						NextElement->previousElement = NULL;
				}
				if(NULL != NextElement)
					NextElement->previousElement = PreviousElement;
				else{
					aList->tail = PreviousElement;
					if(NULL != PreviousElement)
						PreviousElement->nextElement = NULL;
				}
				FreeDoubleElement(theElement);	
				break;
			}		
			i++; // increase index
			theElement = theElement->nextElement; //<! - go to next element		
		} while (NULL != theElement);		
		aList->count-=1; 
	}
}

DoubleElement *ElementAtIndex(const DoubleList *aList, int anIndex)
{
	DoubleElement *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleElement *theElement = aList->head;
	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theElement; //<! - our element
				break;
			}
		
			i++; // increase index
			theElement = theElement->nextElement; //<! - go to next element
		
		} while (NULL != theElement);
	}
	
	return theResult;
}

void doPrintList(const DoubleList *aList)
{
	int i;
	DoubleElement *theElement = aList->head;
	for (i = 0; i < CountList(aList); i++)
	{
		if (NULL != theElement)
		{
			printf("Element[%d].string = %s\n", i, theElement->str);
		}
		theElement = theElement->nextElement;
	}
}

void DeleteElement (DoubleList *aList)
{
	if(NULL != aList && aList->count != 0)
	{
		DoubleElement *theElementToDelete = aList->tail;
		DoubleElement *theElement = theElementToDelete->previousElement;
		aList->tail = theElement;
		theElement->nextElement = NULL;
		FreeDoubleElement(theElementToDelete);
		aList->count -= 1;		
	}	
}
