#include "List.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

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
	DoubleNode *theNode = aList->head;
	while (NULL != theNode)
	{
		DoubleNode *theNodeToBeFree = theNode;
		theNode = theNode->next;
		free(theNodeToBeFree);
	}
	//2. Free memory for the List structure
	free(aList);
}

DoubleNode *AddNode(DoubleList *aList, DoubleNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)

	{
		return NULL;
	}
	//Add the new node to end of the list
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{

		DoubleNode *theTail = aList->tail;
		aList->tail = aNewNode;
		aNewNode->prev = theTail;
        theTail->next = aList->tail;
	}

	aList->count += 1;
	return aNewNode;
}

int CountList(DoubleList *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

DoubleNode *NodeAtIndex(DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}
			i++; // increase index
			theNode = theNode->next; //<! - go to next node
		} while (NULL != theNode);
	}

	return theResult;
}

void PrintList(DoubleList *aList)
{
	int i;
	for (i = 0; i < CountList(aList); i++)
	{
		DoubleNode *theNode = NodeAtIndex(aList, i);

		if (NULL != theNode)
		{
			printf("node[%d].value = %f\n", i, theNode->value);
		}
	}
}

void DeleteElementAtIndex(DoubleList *aList, int anIndex)
{
	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				DoubleNode *PrevNode = theNode->prev;
				DoubleNode *NextNode = theNode->next;
				if(NULL != PrevNode)

					PrevNode->next = NextNode;

				else{
					aList->head = NextNode;
					NextNode->prev = NULL;
				}
				if(NULL != NextNode)
					NextNode->prev = PrevNode;
				else
				{
					aList->tail = PrevNode;
					PrevNode->next = NULL;
				}
				free(theNode);	
				break;
			}		
			i++; // increase index
			theNode = theNode->next; //<! - go to next element		
		} while (NULL != theNode);		
		aList->count-=1; 
	}
}

void AddNodeAtIndex(DoubleList *aList, DoubleNode *aNewNode, int anIndex)
{
	if (NULL != aList && anIndex <= aList->count  && NULL != aNewNode)
	{
		
		int i = 0;
		DoubleNode *theNode = aList->head;	
		do
		{

		//i; // increase index
			if (i == anIndex) //<!- index was found
			{			
				DoubleNode *PrevNode = theNode->prev;
				aNewNode->next = theNode;
				if(NULL != PrevNode)
				PrevNode->next = aNewNode;
				else
				aList->head = aNewNode;
				aNewNode->prev = PrevNode;
				theNode->prev= aNewNode;
				break;
			}	i++;
			theNode = theNode->next; //<! - go to next node			
		} while (NULL != theNode);
		aList->count += 1;
	}
}

double mediana(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;

	DoubleNode *theLeftElement = NodeAtIndex(aList,aLeftIndex);	
	DoubleNode *theRightElement = NodeAtIndex(aList,theCenter);	

	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, theCenter);
	}

	theLeftElement = NodeAtIndex(aList,aLeftIndex);	
	theRightElement = NodeAtIndex(aList,aRightIndex);
		
	if(theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, aRightIndex);
	}

	theLeftElement = NodeAtIndex(aList,theCenter);	
	theRightElement = NodeAtIndex(aList,aRightIndex);

	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, theCenter, aRightIndex);
	}

	swap(aList, theCenter, aRightIndex);
	theRightElement = NodeAtIndex(aList,aRightIndex);
	return theRightElement->value;
}

int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot)
{
	if(NULL != aList)
	{

		int theLeft = aLeftIndex;
		int theRight = aRightIndex;

		while (1)
		{
			// search the bigest element		
			DoubleNode *theLeftElement = NodeAtIndex(aList,theLeft);
			while (theLeftElement->value < aPivot)
			{
				theLeft++;
				theLeftElement = NodeAtIndex(aList,theLeft);
			}
			// search the lowest element
			DoubleNode *theRightElement = NodeAtIndex(aList,theRight);	
			while (theRightElement->value > aPivot){
				theRight--;
				theRightElement = NodeAtIndex(aList,theRight);		
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

void swap(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	if (NULL != aList && aRightIndex < aList->count && -1 < aLeftIndex && 0 < (aRightIndex-aLeftIndex) && aRightIndex > aLeftIndex)
	{
		int i = 0;
		DoubleNode *theLeft = NodeAtIndex(aList, aLeftIndex);
		DoubleNode *theRight = NodeAtIndex(aList, aRightIndex);

		if(NULL != theLeft && NULL != theRight)	
		{
			if(1 < (aRightIndex-aLeftIndex))
			{ 
				DoubleNode *theNextLeft = theLeft->next;
				DoubleNode *thePreviousLeft = theLeft->prev;
				DoubleNode *theNextRight = theRight->next;
				DoubleNode *thePreviousRight = theRight->prev;

				theNextLeft->prev = theRight;

				if(NULL != thePreviousLeft)
					thePreviousLeft->next = theRight;

				else				
					aList->head = theRight;

				if(NULL != theNextRight)
					theNextRight->prev = theLeft;

				else
					aList->tail = theLeft;

				thePreviousRight->next = theLeft;
				theLeft->prev = thePreviousRight;

				if(NULL != theNextRight)
					theLeft->next = theNextRight;

				else
					theLeft->next = NULL;

				if(NULL != thePreviousLeft)
					theRight->prev = thePreviousLeft;

				else
					theRight->prev = NULL;
					
				theRight->next = theNextLeft;

			}
			
			else
			{				
				DoubleNode *thePreviousLeft = theLeft->prev;
				DoubleNode *theNextRight = theRight->next;

				if(NULL != thePreviousLeft)
					thePreviousLeft->next = theRight;

				else				
					aList->head = theRight;
					
				if(NULL != theNextRight)
					theNextRight->prev = theLeft;
					
				else
					aList->tail = theLeft;
				theLeft->prev = theRight;
				theRight->next = theLeft;

				if(NULL != theNextRight)
					theLeft->next = theNextRight;

				else
					theLeft->next = NULL;

				if(NULL != thePreviousLeft)
					theRight->prev = thePreviousLeft;

				else
					theRight->prev = NULL;
			}
		}
	}
}
