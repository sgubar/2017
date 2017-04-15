#include "List.h"
#include "Element.h"
#include <stdlib.h>

// Constants
const int kSLListError = -1;

void doTestList()
{
	printf("Start to demo a double-linked list ...\n");
	
	DoubleElement *theElement1 = CreateElementWithDoubleValue(1);
	DoubleElement *theElement2 = CreateElementWithDoubleValue(2);
	DoubleElement *theElement3 = CreateElementWithDoubleValue(3);
	DoubleElement *theElement4 = CreateElementWithDoubleValue(4);
	DoubleElement *theElement5 = CreateElementWithDoubleValue(5);
	DoubleElement *theElement6 = CreateElementWithDoubleValue(6);
	DoubleElement *theElement7 = CreateElementWithDoubleValue(7);
	DoubleElement *theElement8 = CreateElementWithDoubleValue(8);
	DoubleElement *theElement9 = CreateElementWithDoubleValue(9);
	DoubleElement *theElement10 = CreateElementWithDoubleValue(10);

	DoubleList *theList = CreateList();
	
	AddElement(theList, theElement5);
	AddElement(theList, theElement8);	
	AddElement(theList, theElement6);
	AddElement(theList, theElement1);
	AddElement(theList, theElement2);
	AddElement(theList, theElement4);
	AddElement(theList, theElement3);
	AddElement(theList, theElement9);
	AddElement(theList, theElement7);
	
	doPrintList(theList);
	
	AddElementAtIndex(theList,theElement10,1);	
	printf("\nAdded the element at index\n");	
	
	DeleteElementAtIndex(theList, 0);	
	printf("\nDeleted the element at index\n");	
	doPrintList(theList);
	
	quickSort2( theList, 0, 8);
	printf("\nafter sort\n");	
	
	doPrintList(theList);
	
	FreeList(theList);
	
	printf("Done.\n");
}

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
	
		free(theElementToBeFree);
	}
	//2. Free memory for the List structure
	free(aList);
}

DoubleElement *AddElement(DoubleList *aList, DoubleElement *aNewElement)
{
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
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

void AddElementAtIndex(DoubleList *aList, DoubleElement *aNewElement, int anIndex)
{
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
				break;
			}		
			i++; // increase index
			theElement = theElement->nextElement; //<! - go to next node		
		} while (NULL != theElement);	
		aList->count += 1;
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
				else{
					aList->head = NextElement;
					NextElement->previousElement = NULL;
				}
				if(NULL != NextElement)
					NextElement->previousElement = PreviousElement;
				else{
					aList->tail = PreviousElement;
					PreviousElement->nextElement = NULL;
				}
				free(theElement);	
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



void swap(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	if (NULL != aList && aRightIndex < aList->count && -1 < aLeftIndex && 0 < (aRightIndex-aLeftIndex) && aRightIndex > aLeftIndex)
	{
		int i = 0;
		DoubleElement *theLeft = ElementAtIndex(aList, aLeftIndex);
		DoubleElement *theRight = ElementAtIndex(aList, aRightIndex);
		if(NULL != theLeft && NULL != theRight)	{
			if(1 < (aRightIndex-aLeftIndex)){
				DoubleElement *theNextLeft = theLeft->nextElement;
				DoubleElement *thePreviousLeft = theLeft->previousElement;
				DoubleElement *theNextRight = theRight->nextElement;
				DoubleElement *thePreviousRight = theRight->previousElement;
				
				theNextLeft->previousElement = theRight;
				if(NULL != thePreviousLeft)
					thePreviousLeft->nextElement = theRight;
				else				
					aList->head = theRight;
				if(NULL != theNextRight)
					theNextRight->previousElement = theLeft;
				else
					aList->tail = theLeft;
				thePreviousRight->nextElement = theLeft;
				theLeft->previousElement = thePreviousRight;
				if(NULL != theNextRight)
					theLeft->nextElement = theNextRight;
				else
					theLeft->nextElement = NULL;
				if(NULL != thePreviousLeft)
					theRight->previousElement = thePreviousLeft;
				else
					theRight->previousElement = NULL;
				theRight->nextElement = theNextLeft;
			}else{				
				DoubleElement *thePreviousLeft = theLeft->previousElement;
				DoubleElement *theNextRight = theRight->nextElement;
				if(NULL != thePreviousLeft)
					thePreviousLeft->nextElement = theRight;
				else				
					aList->head = theRight;
				if(NULL != theNextRight)
					theNextRight->previousElement = theLeft;
				else
					aList->tail = theLeft;
				theLeft->previousElement = theRight;
				theRight->nextElement = theLeft;
				if(NULL != theNextRight)
					theLeft->nextElement = theNextRight;
				else
					theLeft->nextElement = NULL;
				if(NULL != thePreviousLeft)
					theRight->previousElement = thePreviousLeft;
				else
					theRight->previousElement = NULL;
			}
		}
	}
}

void doPrintList(const DoubleList *aList)
{
	int i;
	DoubleElement *theElement = aList->head;
	for (i = 0; i < CountList(aList); i++)
	{
		if (NULL != theElement)
		{
			printf("Element[%d].value = %.2f\n", i, theElement->value);
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
		free(theElementToDelete);
		aList->count -= 1;		
	}
	
}

double mediana(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	DoubleElement *theLeftElement = ElementAtIndex(aList,aLeftIndex);	
	DoubleElement *theRightElement = ElementAtIndex(aList,theCenter);	
	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, theCenter);
	}
	
	theLeftElement = ElementAtIndex(aList,aLeftIndex);	
	theRightElement = ElementAtIndex(aList,aRightIndex);	
	if(theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, aRightIndex);
	}
	
	theLeftElement = ElementAtIndex(aList,theCenter);	
	theRightElement = ElementAtIndex(aList,aRightIndex);
	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, theCenter, aRightIndex);
	}
	
	swap(aList, theCenter, aRightIndex);
	
	theRightElement = ElementAtIndex(aList,aRightIndex);
	return theRightElement->value;
}

int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot)
{
	if(NULL != aList){
		int theLeft = aLeftIndex;
		int theRight = aRightIndex;
		
		while (1)
		{
			// search the bigest element		
			DoubleElement *theLeftElement = ElementAtIndex(aList,theLeft);
			while (theLeftElement->value < aPivot){
				theLeft++;
				theLeftElement = ElementAtIndex(aList,theLeft);
			}
			// search the lowest element
			DoubleElement *theRightElement = ElementAtIndex(aList,theRight);	
			while (theRightElement->value > aPivot){
				theRight--;
				theRightElement = ElementAtIndex(aList,theRight);		
			}
			if (theLeft >= theRight) // pointer are the same 
			{
				break;
			}
			else
			{
				//lets to swap elements
				swap(aList, theLeft, theRight);
			}
		}		
		return theLeft; // return break position
	}
}


void quickSort2(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 3)
	{
		m_manualSort(aList, aLeftIndex, aRightIndex);
	}
	else
	{
		double thePivot = mediana(aList, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
		
		//left part sorting
		quickSort2(aList, aLeftIndex, thePartitionIndex - 1);
		
		//right part sorting
		quickSort2(aList, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{	
		DoubleElement *theLeftElement = ElementAtIndex(aList,aLeftIndex);		
		DoubleElement *theRightElement = ElementAtIndex(aList,aRightIndex);
		if (theLeftElement->value > theRightElement->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes		
		DoubleElement *theLeftElement = ElementAtIndex(aList,aLeftIndex);		
		DoubleElement *theRightElement = ElementAtIndex(aList,aRightIndex-1);
		if (theLeftElement->value > theRightElement->value)
		{
			swap(aList, aLeftIndex, aRightIndex - 1);
		}
	
		theLeftElement = ElementAtIndex(aList,aLeftIndex);		
		theRightElement = ElementAtIndex(aList,aRightIndex);
		if (theLeftElement->value > theRightElement->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}

		theLeftElement = ElementAtIndex(aList,aRightIndex-1);		
		theRightElement = ElementAtIndex(aList,aRightIndex);
		if (theLeftElement->value > theRightElement->value)
		{	
			swap(aList, aRightIndex - 1, aRightIndex);
		}
	}
}


