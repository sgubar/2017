
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "List.h"


LinkNode *createLinkNodeWithValue(int anIntValue);
LinkNode *FindTheNodeAtIndex(IntList *aList, int anIndex);


IntList *getIntListWithRandValues( int amount, bool state )
{
    IntList *aList = CreateIntList();
    if(NULL == aList)
        return NULL;
    int i;

    //sequence for Euclid's Sieve
    if(state  == 1)
    {
        for (i = 0; i < amount; i++)
            AddIntValueToList(aList, i+1);
    }
    else
    {
        for (i = 0; i < amount; i++)
            AddIntValueToList(aList, randomIntFromRange(0, 999));
    }
    return aList;
}

IntList *CreateIntList( void )
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));

	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}

	return theList;
}

void DestroyIntList(IntList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->head)
	{
		int anIndex = aList->count - 1;

		do
		{
		LinkNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
		free (theNodeToDelete);
		anIndex--;
		}while (anIndex >= 0);

		free(aList);
	}
}

LinkNode *FindTheNodeAtIndex(IntList *aList, int anIndex)
{
	if(aList == NULL || anIndex < 0 || aList->count < anIndex )
	{
		return NULL;
	}

	int i = 0;
	LinkNode *theNode = aList->head;
	do
	{
		if (i == anIndex)
		{
			break;
		}

		theNode = theNode->next;
		i++;

	}while (theNode != aList->head);

	return theNode;
}


int AddIntValueToList(IntList *aList, int anIntValue)
{
	int theResult = -1;

	if (NULL != aList)
	{
		LinkNode *theNode = createLinkNodeWithValue(anIntValue);

		if (NULL != theNode)
		{
			// lets to add to the end of the list
			//1. The list is empty
			if (NULL == aList->head)
			{
				aList->head = theNode;
				aList->head->next = aList->head->prev = aList->head; //self recursion
			}
			else
			{
				//2. Have 2 or more elements
				if (aList->head->next != aList->head)
				{
					// (head) a b(tail)  + c => (head) a b c (tail)
					aList->tail->next = theNode; // b->c
					theNode->prev = aList->tail; // b<-c

					aList->tail = theNode;	// New tail

					aList->tail->next = aList->head; // c->a
					aList->head->prev = aList->tail; // c<-a
				}
				else
				{
					//3. Have only 1 element
					// (head) a  +  b  =>  (head) a b (tail)
					aList->tail = theNode;
					aList->head->next = aList->head->prev = aList->tail;
					aList->tail->next = aList->tail->prev = aList->head;
				}
			}

			aList->count ++;
			theResult = 0;
		}
	}
	return theResult;
}

int IntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = INT_MAX;

	//list is empty   or   typed wrong index
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}

	LinkNode *theNode = FindTheNodeAtIndex(aList, anIndex);

	return theNode->value;
}

int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{
	int theResult = -1;

	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}

	LinkNode *theNewNode = createLinkNodeWithValue(anIntValue);
	LinkNode *theNode = FindTheNodeAtIndex(aList, anIndex);

	// Can't create theNewNode
	if (NULL == theNewNode)
	{
		return theResult;
	}

	//1. Have 1 element {b} => {a, b}
	if ( aList->count == 1 )
	{
		aList->tail = aList->head;
		aList->head = theNewNode;

		aList->head->next = aList->head->prev = aList->tail;
		aList->tail->next = aList->tail->prev = aList->head;
	}

	else
	// 2. For the first element {b,c} => {a,b,c}
	if (anIndex == 0)
	{
		LinkNode *thePrevHead = aList->head;

		aList->tail->next = theNewNode;
		theNewNode->prev = aList->tail;

		aList->head = theNewNode;

		aList->head->next = thePrevHead;
		aList->head->prev = aList->tail;
	}

	//2. adding in the middle
	else
	{
		LinkNode *theANode = theNode;

		// b c a d ^ z(2) = b->c->z->a->z
		theANode->prev->next = theNewNode; // c->z
		theNewNode->prev = theANode;	   // z<-a

		theNewNode->next = theANode;		// z->a
		theANode-> prev = theNewNode;		// z<-a
	}

	aList->count ++;
	theResult = 0;

	return theResult;
}

LinkNode *createLinkNodeWithValue(int anIntValue)
{
	LinkNode *theNode = (LinkNode *)malloc(sizeof(LinkNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anIntValue;
		theNode->mark = 0;
	}

	return theNode;
}


void PrintList(IntList *aList)
{
	if (NULL == aList || 0 == aList->count)
	{
		printf(" empty\n");
		return;
	}

	printf("List with count (%d):\n", aList->count);
	LinkNode *theNode = aList->head;
	do
	{
		printf("(%d) ", theNode->value);
		theNode = theNode->next;

	}while (aList->head != theNode);

	printf ("\n");
}

int DeleteValueFromIntList(IntList *aList, int aValue)
{
    if (NULL == aList || aList->head == NULL)
	{
		return -1;
	}
	LinkNode *aNode = aList->head;
	int index = 0;
	while (aNode->value != aValue)
    {
        if (NULL == aNode)
            return -1;

        aNode = aNode->next;
        index++;
    }
    DeleteIntValueAtIndex(aList, index);
    return 0;

}

int DeleteIntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = -1;

	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}

	LinkNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);

	//1. for list with 1 element: {a} => {empty}
	if (aList->count == 1)
	{
		free(theNodeToDelete);
		aList->count = 0;
		aList->head = NULL;
		aList->tail = NULL;
		theResult = 0;
		return theResult;
	}

	//2. for the head: {a, b, c} => {b, c}
	if (theNodeToDelete == aList->head)
	{
		LinkNode *theNextNode = aList->head->next;
		aList->head = theNextNode; 		//change the head
		aList->head->next = theNextNode->next;
		aList->head->prev = aList->tail;

		aList->tail->next = aList->head;
		theResult = 0;
	}
	else
	//3. for the tail {a, b, c} => {a, b}
	if (theNodeToDelete == aList->tail)
	{
		aList->tail = aList->tail->prev; //change the tail
		aList->tail->next = aList->head;
		aList->head->prev = aList->tail;
		theResult = 0;
	}
	else
	//3. delete from the middle {a, b, c} => {a, c}
	{
		theNodeToDelete->prev->next = theNodeToDelete->next;
		theNodeToDelete->next->prev = theNodeToDelete->prev;
		theResult = 0;
	}

	free(theNodeToDelete);
	aList->count--;
	return theResult;
}

//return 0 if sucsess
//otherwsise -1
int DeleteMarksElements( IntList *aList )
{
    if (aList == NULL)
    {
        return -1;
    }
    int theResult = -1;
	LinkNode *aNode = aList->head;
	int IndexToDelete = 0;

	while (IndexToDelete < aList-> count)
    {
        if (aNode->mark)  //different states
        {
            aNode = aNode->next;
            DeleteIntValueAtIndex(aList, IndexToDelete);
            theResult = 0;
        }
        else
        {
            aNode = aNode->next;
            IndexToDelete++;
        }

        if (aNode == NULL)
            break;
    }
    //PrintList (aList); //finish result
return theResult;
}

void MarkIndexToDelete(IntList *aList, int MultipleIndex, bool markFirst)
{
    if (MultipleIndex > aList->count - 1 || MultipleIndex < 0)
    {
        return;
    }

    int IndexToMark;
    LinkNode *aNode = aList->head;

    //mark all cells
    if (MultipleIndex == 0)
    {
        if(markFirst)
        {
            IndexToMark = MultipleIndex;
        }
        //without first element
        else
        {
            IndexToMark = 1;
            aNode = aNode->next;
        }

         for( ; IndexToMark < aList->count; IndexToMark++)
        {
            aNode->mark = (aNode->mark + 1) % 2; // different states
            aNode = aNode->next;
        }
    }

    //mark multiples cells
    else
    {
        (markFirst) ? IndexToMark = MultipleIndex // within
                    : (IndexToMark = 2 * MultipleIndex+1); //without chosen element

        while(IndexToMark < aList->count)
        {
            aNode = FindTheNodeAtIndex(aList, IndexToMark);
            if (aNode == NULL)
                break;

            IndexToMark += MultipleIndex+1;
            if (!markFirst)
            {
                if (aNode->mark == 0)               //temporary line
                    aNode->mark = (aNode->mark + 1) % 2; // different states
            }
            else
            {
                aNode->mark = (aNode->mark + 1) % 2; // different states
            }
        }
    }
}
