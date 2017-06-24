#include "dk_tool.h"
#include <stdlib.h>


static FloatNode *createFloatNodeWithValue(float anFloatValue);

FloatList *CreateFloatList()
{
	FloatList *theList = (FloatList*)malloc(sizeof(FloatList));
	if(NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	return theList;
}

void DeleteFloatList(FloatList *aList)
{
	if(NULL == aList)
	{
		return ;
	}
	if(NULL != aList->head && NULL!= aList->tail)
	{
		FloatNode *aNode = aList->head;
		do
		{
			FloatNode *DeleteNode = aNode;
			aNode = aNode->next;
			free(DeleteNode);

		}while(NULL != aNode);

		free(aList);
	}
}

int AddFloatValue(FloatList *aList, float anFloatValue)
{
	int theResult = -1;
	if(NULL != aList)
	{
		FloatNode *aNode = createFloatNodeWithValue(anFloatValue);

		if(NULL != aNode)
		{
			if(NULL == aList->head && aList->head == aList->tail)
			{
				aList->head = aList->tail = aNode;
			}
			else
			{
				FloatNode *aTailNode = aList->tail;
				aList->tail = aNode;
				aTailNode->next = aNode;
				aNode->prev = aTailNode;
			}
			aList->count ++;
			theResult = 0;
		}
		return theResult;
	}

}



FloatNode *createFloatNodeWithValue(float SomeFloatValue)
{
	FloatNode *aNode = (FloatNode *)malloc(sizeof(FloatNode));
	if (NULL != aNode)
	{
		aNode->next = NULL;
		aNode->prev = NULL;
		aNode->value = SomeFloatValue;
	}

	return aNode;
}

float FloatValueIndex(FloatList *aList, int anIndex)
{
	float theResult = 0;

	if(NULL == aList || anIndex >= aList->count || anIndex < 0 )
	{
		return theResult;
	}

	FloatNode *aNode = aList->head;
	int i = 0;
	do
	{
		if(i == anIndex)
		{
			break;
		}
		aNode = aNode->next;
		i++;

	}while(NULL != aNode);

	return aNode->value;
}


FloatNode *FindFloatValueIndex(FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if(NULL == aList || anIndex >= aList->count || anIndex < 0 )
	{
		return theResult;
	}

	FloatNode *aNode = aList->head;
	int i = 0;
	do
	{
		if(i == anIndex)
		{
			theResult = aNode;
			break;
		}
		aNode = aNode->next;
		i++;

	}while(NULL != aNode);

	return theResult;
}

void PrintList(FloatList *aList)
{
	printf("List with count [%d]:", aList->count);
	FloatNode *aNode = aList->head;

	do
	{
		printf("[%.3f] ", aNode->value);
		aNode = aNode->next;

	}while (NULL != aNode);

	printf ("\n");
}


int InsertFloatValueIndex(FloatList *aList, float anFloatValue, int anIndex)
{
	int theResult = -1;

	if(NULL == aList || anIndex >= aList->count || anIndex < 0 )
	{
		return theResult;
	}
	FloatNode * aNode = aList->head;
	int i = 0;

	do
	{
		if(i == anIndex)
		{
			break;
		}
		aNode = aNode->next;
		i++;

	}while(NULL != aNode);

	FloatNode *aNewNode = createFloatNodeWithValue(anFloatValue);
	if(NULL == aNewNode)
	{
		return theResult;
	}
	FloatNode * aSomeNode = aNode;
	if(NULL != aSomeNode->prev)
	{
		aSomeNode->prev->next = aNewNode;
		aNewNode->prev = aSomeNode->prev;
	}
	else if(NULL == aSomeNode->prev)
	{
		//FloatNode *aTailNode = aList->tail;
		aList->head = aNewNode;
		aNewNode->next = aSomeNode;
		aSomeNode->prev = aNewNode;
	}
	else if(aSomeNode->next == aList->tail)
	{
		FloatNode *aTailNode = aList->tail;
		aList->tail = aNewNode;
		aTailNode->next = aNewNode;
		aNewNode->prev = aTailNode;
	}
	    aNewNode->next = aSomeNode;
	    aSomeNode->prev = aNewNode;
	aList->count ++;
	theResult = 0;

	return theResult;
}
int DeleteFloatValueIndex(FloatList *aList, int anIndex)
{
	int theResult = -1;
	if(NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}

	FloatNode *aNode = aList->head;
	int i = 0;
	do
	{
		if(i == anIndex)
		{
			break;
		}
		aNode = aNode->next;
		i++;

	}while(NULL != aNode);

	FloatNode * aSomeNode = aNode;
	if(NULL != aSomeNode->prev)
	{
		aSomeNode->prev->next = aSomeNode->next;
		aSomeNode->next = aSomeNode->prev;

	}
	else if(NULL == aSomeNode->prev)
	{
		aList->head = aSomeNode->next;
	}
	free(aSomeNode);


	aList->count --;

	return theResult;
}

void shellSort(FloatList *aList)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;


	while (theH <= aList->count / 3)
	{
		theH = theH * 3 + 1;
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aList->count; theOuter ++)
		{
			float theTmp = FloatValueIndex(aList, theOuter);
			theInner = theOuter;

			while (theInner > theH - 1 && FloatValueIndex(aList, theInner - theH) >= theTmp)
			{
				swap(aList, theInner, theInner - theH);
		//	aList->[theInner]=aList->count[theInner-theH];
				theInner -= theH;
			}

		}

		theH = (theH - 1) / 3;
	}
}


void swap(FloatList *aList, int left, int right)
{
    if(left > right)
    {
        int tmp = left;
        left = right;
        right = tmp;
    }

    FloatNode *firstNode = FindFloatValueIndex(aList, left);
    FloatNode *secondNode = FindFloatValueIndex(aList, right);

    FloatNode *theTmpPrev = firstNode->prev;
    FloatNode *theTmpNext = firstNode->next;


    if(left - right == -1)
    {
        firstNode->next = firstNode->next->next;

        if(right != aList->count - 1)
        {
            secondNode->next->prev = firstNode;
        }

        secondNode->next = firstNode;
        firstNode->prev = secondNode;

        if(left != 0)
        {
            theTmpPrev->next = secondNode;
        }

        secondNode->prev = theTmpPrev;
    }
    else
    {

        if( right != 0)
        {
            secondNode->prev->next = firstNode;
        }

        firstNode->prev = secondNode->prev;
        firstNode->next = secondNode->next;

        if(aList->count-1 != right)
        {
            secondNode->next->prev = firstNode;
        }


        if(left != 0)
        {
            theTmpPrev->next = secondNode;
        }

        secondNode->prev = theTmpPrev;
        secondNode->next=theTmpNext;

        if(left != aList->count - 1)
        {
		    theTmpNext->prev = secondNode;
		}

    }
    if(left == 0)
    {
        aList->head = secondNode;
    }
    if(right == 0)
    {
        aList->head = firstNode;
    }
    if(left == aList->count - 1)
    {
        aList->tail = secondNode;
    }
    if(right == aList->count - 1)
    {
        aList->tail= firstNode;
    }

 }
