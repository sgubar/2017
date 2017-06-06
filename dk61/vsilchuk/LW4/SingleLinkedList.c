#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"

#include <stdlib.h>
#include <string.h>

const int kSLListError = -1;

slList *SLCreateList(void)
{
	slList *theList = (slList *)malloc(sizeof(slList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->nodeCounter = 0; //initial value of count is zero - no elements in the list

	return theList;
}

void SLFreeList(slList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	slNode *theNode = aList->head;
	
	while (NULL != theNode)
	{
		slNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		free(theNodeToBeFree);
	}

	free(aList);
}

int SLCountList(const slList *aList)	//the number of our nodes in the list
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->nodeCounter;
	}

	return theResult;
}

void entryCounterFunction(slList *aList)	//changing the number of entry of some letter in our text
{
	char textBuffer[200];
	
	printf("Enter your text, please. Max lenght is 200 symbols. :\n");
	
	gets(textBuffer);
    int lenght = strlen(textBuffer);
    
    int i;
    for(i = 0; i < lenght; i++)
    {
    	SLAddNode(aList, textBuffer[i]);	//creating the node with the letter, if this letter value from textBuffer[i] is unical
	}

	printf("\nNumber of the nodes in our list: %d\n\n", SLCountList(aList));
	
	slNode *someNode = NULL;
	for(i = 0; i < lenght; i++)
	{
		someNode = findNodeWithLetter(aList, textBuffer[i]);
		someNode -> letterEntryCounter++;
	}
}

slNode *SLAddNode(slList *aList, char aValue)
{
	if (NULL == aList)
	{
		return NULL;
	}
	
	if(NULL != findNodeWithLetter(aList, aValue))		//if we already have the node with this letter in our list, if we work with not unical letter from our textBuffer
	{
		return NULL;	
	}
	
	slNode *aNewNode = createNodeWithCharValue(aValue);		//creating new Node with the char value from our textBuffer, which is unical
	
	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;				//The list is empty
	}
	
	else 
	{
		slNode *theTail = aList->tail;
		aList->tail = aNewNode;
	
		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->nodeCounter += 1;
	
	return aNewNode;
}

slNode *findNodeWithLetter(slList *aList, char aValue)
{
	if (NULL == aList || 1 > aList->nodeCounter)
	{
		return NULL;
	}

		slNode *theNode = aList->head;
	
		do
		{
			if (theNode->letter == aValue) 	//when we have the node with this letter, if the letter from our textBuffer and the letter value fron node are the same
			{
				return theNode; 	
			}
		
			theNode = theNode->nextNode; //go to next node
		
		} while (NULL != theNode);
	
	return NULL;
}

slNode *SLNodeAtIndex(const slList *aList, int anIndex) 	//accessing the node with index
{
	slNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->nodeCounter)
	{
		int i = 0;
		slNode *theNode = aList->head;
		
		do
		{
			if (i == anIndex) //index was found
			{
				theResult = theNode; //our node
				break;
			}
		
			i++; // increase index
			theNode = theNode->nextNode; //go to next node
		
		} while (NULL != theNode);
	}
	return theResult;
}

void finalPrinting(const slList *aList)
{
	int i;
	for (i = 0; i < SLCountList(aList); i++) 		//passing through the list and printing our nodes
	{
		slNode *theNode = SLNodeAtIndex(aList, i);		
		if (NULL != theNode)
		{
			printf("Node[%d].letter = %c", i, theNode->letter);
			printf("\tThe number of entries of this letter in a text: %d\n", theNode -> letterEntryCounter);
		}
	}
}
