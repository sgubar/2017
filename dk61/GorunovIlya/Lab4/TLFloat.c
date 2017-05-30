#include "TLFloat.h"
#include <stdlib.h>
#define FLTMAX  3.40282347E+38F

static FloatNode *createFloatNodeWithValue(float anFloatValue);

FloatList *TLCreateFloatList()
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

void TLDestroyFloatList(FloatList *aList)
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

int TLAddFloatValueToList(FloatList *aList, float anFloatValue)
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

float TLFloatValueAtIndex(FloatList *aList, int anIndex)
{
	float theResult = FLTMAX;
	
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


FloatNode *FindFloatValueAtIndex(FloatList *aList, int anIndex)
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

void TLPrintList(FloatList *aList)
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


int TLInsertFloatValueAtIndex(FloatList *aList, float anFloatValue, int anIndex)
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
	//else
	//{
	    aNewNode->next = aSomeNode;
	    aSomeNode->prev = aNewNode;
    //}
	aList->count ++;
	theResult = 0;
	
	return theResult;
}
int TLDestroyFloatValueAtIndex(FloatList *aList, int anIndex)
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
		//free(aSomeNode);
	}
	free(aSomeNode);
	
	
	aList->count --;
	
	return theResult;
}



//lesser than average
int deleteFirstFloatElement(FloatList *aList, int aValue)
{
	
	if(NULL == aList)
	{
		return -1;
	}
	
	FloatNode *aNode = aList->head;
	int i = 0;
	do
	{
		if(aNode->value < aValue  )
		{
		TLDestroyFloatValueAtIndex(aList, i);
			break;

		}
		aNode = aNode->next;
		i++;

		
	}while(NULL != aNode);
	
	return 0;
}


	
float FindAverageInList(FloatList *aList)
{
	FloatNode *aNode = aList->head;

	float theSum = 0;
	do
	{
				theSum+= aNode->value;
		aNode = aNode->next;

		
	}while(NULL != aNode);
	
	
	return theSum/aList->count;
}
