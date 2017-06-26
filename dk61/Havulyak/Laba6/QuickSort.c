#include "TLList.h"
#include "TLNode.h"
#include "QuickSort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	if (NULL != aList && aRightIndex < aList->count && -1 < aLeftIndex && 0 < (aRightIndex-aLeftIndex) && aRightIndex > aLeftIndex)
	{
		int i = 0;
		DoubleNode *theLeft = NodeAtIndex(aList, aLeftIndex); 
		DoubleNode *theRight = NodeAtIndex(aList, aRightIndex);
		if(NULL != theLeft && NULL != theRight)	{
			if(1 < (aRightIndex-aLeftIndex)){
				DoubleNode *theNextLeft = theLeft->nextNode;
				DoubleNode *thePreviousLeft = theLeft->previousNode;
				DoubleNode *theNextRight = theRight->nextNode;
				DoubleNode *thePreviousRight = theRight->previousNode;
				
				theNextLeft->previousNode = theRight;
				if(NULL != thePreviousLeft)
					thePreviousLeft->nextNode = theRight;
				else				
					aList->head = theRight;
				if(NULL != theNextRight)
					theNextRight->previousNode = theLeft;
				else
					aList->tail = theLeft;
				thePreviousRight->nextNode = theLeft;
				theLeft->previousNode = thePreviousRight;
				if(NULL != theNextRight)
					theLeft->nextNode = theNextRight;
				else
					theLeft->nextNode = NULL;
				if(NULL != thePreviousLeft)
					theRight->previousNode = thePreviousLeft;
				else
					theRight->previousNode = NULL;
				theRight->nextNode = theNextLeft;
			}else{				
				DoubleNode *thePreviousLeft = theLeft->previousNode;
				DoubleNode *theNextRight = theRight->nextNode;
				if(NULL != thePreviousLeft)
					thePreviousLeft->nextNode = theRight;
				else				
					aList->head = theRight;
				if(NULL != theNextRight)
					theNextRight->previousNode = theLeft;
				else
					aList->tail = theLeft;
				theLeft->previousNode = theRight;
				theRight->nextNode = theLeft;
				if(NULL != theNextRight)
					theLeft->nextNode = theNextRight;
				else
					theLeft->nextNode = NULL;
				if(NULL != thePreviousLeft)
					theRight->previousNode = thePreviousLeft;
				else
					theRight->previousNode = NULL;
			}
		}
	}
}

double mediana(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	DoubleNode *theLeftNode = NodeAtIndex(aList,aLeftIndex);	
	DoubleNode *theRightNode = NodeAtIndex(aList,theCenter);	
	if (theLeftNode->value > theRightNode->value)
	{
		swap(aList, aLeftIndex, theCenter);
	}
	
	theLeftNode = NodeAtIndex(aList,aLeftIndex);	
	theRightNode = NodeAtIndex(aList,aRightIndex);	
	if(theLeftNode->value > theRightNode->value)
	{
		swap(aList, aLeftIndex, aRightIndex);
	}
	
	theLeftNode = NodeAtIndex(aList,theCenter);	
	theRightNode = NodeAtIndex(aList,aRightIndex);
	if (theLeftNode->value > theRightNode->value)
	{
		swap(aList, theCenter, aRightIndex);
	}
	
	swap(aList, theCenter, aRightIndex);
	
	theRightNode = NodeAtIndex(aList,aRightIndex);
	return theRightNode->value;
}

int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot)
{
	if(NULL != aList){
		int theLeft = aLeftIndex;
		int theRight = aRightIndex;
		
		while (1)
		{		
			DoubleNode *theLeftNode = NodeAtIndex(aList,theLeft);
			while (theLeftNode->value < aPivot){
				theLeft++;
				theLeftNode = NodeAtIndex(aList,theLeft);
			}
			DoubleNode *theRightNode = NodeAtIndex(aList,theRight);	
			while (theRightNode->value > aPivot){
				theRight--;
				theRightNode = NodeAtIndex(aList,theRight);		
			}
			if (theLeft >= theRight) 
			{
				break;
			}
			else
			{
				swap(aList, theLeft, theRight);
			}
		}		
		return theLeft; 
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
		
		quickSort2(aList, aLeftIndex, thePartitionIndex - 1); //Left sorting
		
		quickSort2(aList, thePartitionIndex + 1, aRightIndex); //Right sorting
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
		DoubleNode *theLeftNode = NodeAtIndex(aList,aLeftIndex);		
		DoubleNode *theRightNode = NodeAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes		
		DoubleNode *theLeftNode = NodeAtIndex(aList,aLeftIndex);		
		DoubleNode *theRightNode = NodeAtIndex(aList,aRightIndex-1);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex - 1);
		}
	
		theLeftNode = NodeAtIndex(aList,aLeftIndex);		
		theRightNode = NodeAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}

		theLeftNode = NodeAtIndex(aList,aRightIndex-1);		
		theRightNode = NodeAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{	
			swap(aList, aRightIndex - 1, aRightIndex);
		}
	}
}
