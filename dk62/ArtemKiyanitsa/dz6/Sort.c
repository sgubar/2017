#include "List.h"
#include "Element.h"
#include "Sort.h"
#include <stdlib.h>

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
