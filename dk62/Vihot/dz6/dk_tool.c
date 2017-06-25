#include "dk_tool.h"
#include <stdlib.h>

CharNode *createCharNodeWithElement(char anCharElement)
{
    CharNode *theNode=(CharNode *)malloc(sizeof(CharNode));
    if(NULL!=theNode)
    {
        theNode->next=NULL;
        theNode->prev=NULL;
        theNode->value=anCharElement;
    }
    return theNode;
}

CharList *CreateCharList()
{
    CharList *theList=(CharList *)malloc(sizeof(CharList));
    if(NULL!=theList)
    {
        theList->head=NULL;
        theList->tail=NULL;
        theList->count=0;
    }
    return theList;
}

void DestroyCharList(CharList *aList)
{
    if(NULL==aList)
    {
        return;
    }
    if (NULL!=aList->tail&&NULL!=aList->head)
    {
        CharNode *theNode = aList->head;
        do
        {
            CharNode *theNodeToDelete=theNode;
            theNode=theNode->next;
            free(theNodeToDelete);
        }while(NULL!=theNode);
        free(aList);
    }
}

char addCharElementToList(CharList *aList, char anCharElement)
{
    char theResult=-1;
    if(NULL!=aList)
    {
        CharNode *theNode=createCharNodeWithElement(anCharElement);
        if(NULL!=theNode)
        {
            if(NULL==aList->head&&aList->head==aList->tail)
            {
                aList->head=aList->tail=theNode;
            }
            else
            {
                CharNode *theTail=aList->tail;
                aList->tail=theNode;
                theTail->next=theNode;
                theNode->prev=theTail;
            }
            aList->count++;
            theResult=0;
        }
    }
    return theResult;
}

CharNode *CharElementAtIndex(CharList *aList, char anIndex)
{
	CharNode *theResult = NULL;
	if (NULL != aList && anIndex < aList->count)
	{
		char i = 0;
		CharNode *theNode = aList->head;
		do
		{
			if (i == anIndex) 
			{
				theResult = theNode;
				break;
			}
			i++; 
			theNode = theNode->next; 
		} while (NULL != theNode);
	}
	return theResult;
}

void PrintList(CharList *aList)

{
    printf("[Spisok] s razmerom (%d):", aList->count);
    CharNode *theNode=aList->head;
    do
    {
        printf("(%c) ", theNode->value);
        theNode=theNode->next;
    }while(NULL!= theNode);
    printf ("\n");
}

char InsertCharElementAtIndex(CharList *aList, char anCharElement, char anIndex)
{
    char theResult=-1;
    anIndex--;
    if (NULL==aList||anIndex>=aList->count||anIndex<0)
    {
        return theResult;
    }
    CharNode *theNode=aList->head;
    char i=0;
    do
    {
        if (i==anIndex)
        {
            break;
        }
        theNode=theNode->next;
        i++;
    }while(NULL!=theNode);
    CharNode *theNewNode=createCharNodeWithElement(anCharElement);
    if(NULL==theNewNode)
    {
        return theResult;
    }
    CharNode *theBNode=theNode;
    if (NULL!=theBNode->prev)
    {
        theBNode->prev->next=theNewNode;
        theNewNode->prev=theBNode->prev;
    }
    theNewNode->next=theBNode;
    theBNode->prev=theNewNode;
    aList->count++;
    theResult=0;
    return theResult;
}

void DeleteCharElementAtIndex(CharList *aList, char anIndex)
{
	anIndex--;
    if (NULL!=aList&&anIndex<aList->count)
    {
        char i=0;
        CharNode *theNode=aList->head;
        do
        {
            if(i==anIndex)
            {
                CharNode *PrevNode=theNode->prev;
                CharNode *NextNode=theNode->next;
                if(NULL!=PrevNode)
                {
                    PrevNode->next=NextNode;
                }
                else
                {
                    aList->head=NextNode;
                    NextNode->prev=NULL;
                }
                if(NULL!=NextNode)
                {
                    NextNode->prev=PrevNode;
                }
                else
                {
                    aList->tail=PrevNode;
                    PrevNode->next=NULL;
                }
                free(theNode);
                break;
            }
            i++;
            theNode=theNode->next;
        }while(NULL!=theNode);
        aList->count-=1;
    }
}

char mediana(CharList *aList, char aLeftIndex, char aRightIndex)
{
	char theCenter = (aLeftIndex + aRightIndex) / 2;
	CharNode *theLeftElement = CharElementAtIndex(aList,aLeftIndex);	
	CharNode *theRightElement = CharElementAtIndex(aList,theCenter);	
	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, theCenter);
	}
	theLeftElement = CharElementAtIndex(aList,aLeftIndex);	
	theRightElement = CharElementAtIndex(aList,aRightIndex);	
	if(theLeftElement->value > theRightElement->value)
	{
		swap(aList, aLeftIndex, aRightIndex);
	}
	theLeftElement = CharElementAtIndex(aList,theCenter);	
	theRightElement = CharElementAtIndex(aList,aRightIndex);
	if (theLeftElement->value > theRightElement->value)
	{
		swap(aList, theCenter, aRightIndex);
	}
	swap(aList, theCenter, aRightIndex);
	theRightElement = CharElementAtIndex(aList,aRightIndex);
	return theRightElement->value;
}

char m_partitionIt(CharList *aList, char aLeftIndex, char aRightIndex, char aPivot)
{
	if(NULL != aList)
	{
		char theLeft = aLeftIndex;
		char theRight = aRightIndex;
		while (1)
		{		
			CharNode *theLeftElement = CharElementAtIndex(aList,theLeft);
			while (theLeftElement->value < aPivot)
			{
				theLeft++;
				theLeftElement = CharElementAtIndex(aList,theLeft);
			}
			CharNode *theRightElement = CharElementAtIndex(aList,theRight);	
			while (theRightElement->value > aPivot){
				theRight--;
				theRightElement = CharElementAtIndex(aList,theRight);		
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

void quickSort(CharList *aList, char aLeftIndex, char aRightIndex)
{
	char theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(aList, aLeftIndex, aRightIndex);
	}
	else
	{
		char thePivot = mediana(aList, aLeftIndex, aRightIndex);
		char thePartitionIndex = m_partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
		quickSort(aList, aLeftIndex, thePartitionIndex - 1);
		quickSort(aList, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(CharList *aList, char aLeftIndex, char aRightIndex)
{
	char theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 1)
	{
		return;
	}
	if (2 == theSize)
	{	
		CharNode *theLeftNode = CharElementAtIndex(aList,aLeftIndex);		
		CharNode *theRightNode = CharElementAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{		
		CharNode *theLeftNode = CharElementAtIndex(aList,aLeftIndex);		
		CharNode *theRightNode = CharElementAtIndex(aList,aRightIndex-1);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex - 1);
		}
		theLeftNode = CharElementAtIndex(aList,aLeftIndex);		
		theRightNode = CharElementAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{
			swap(aList, aLeftIndex, aRightIndex);
		}
		theLeftNode = CharElementAtIndex(aList,aRightIndex-1);		
		theRightNode = CharElementAtIndex(aList,aRightIndex);
		if (theLeftNode->value > theRightNode->value)
		{	
			swap(aList, aRightIndex - 1, aRightIndex);
		}
	}
}

void swap(CharList *aList, char aLeftIndex, char aRightIndex)
{
	if (NULL != aList && aRightIndex < aList->count && -1 < aLeftIndex && 0 < (aRightIndex-aLeftIndex) && aRightIndex > aLeftIndex)
	{
		CharNode *theLeft = CharElementAtIndex(aList, aLeftIndex);
		CharNode *theRight = CharElementAtIndex(aList, aRightIndex);
		if(NULL != theLeft && NULL != theRight)	
		{
			if(1 < (aRightIndex-aLeftIndex))
			{ 
				CharNode *theNextLeft = theLeft->next;
				CharNode *thePreviousLeft = theLeft->prev;
				CharNode *theNextRight = theRight->next;
				CharNode *thePreviousRight = theRight->prev;
				theNextLeft->prev = theRight;
				if(NULL != thePreviousLeft)
				{
					thePreviousLeft->next = theRight;
				}	
				else
				{
				aList->head = theRight;
				}					
				if(NULL != theNextRight)
				{
					theNextRight->prev = theLeft;
				}			
				else
				{
					aList->tail = theLeft;
				}	
				thePreviousRight->next = theLeft;
				theLeft->prev = thePreviousRight;
				if(NULL != theNextRight)
				{
					theLeft->next = theNextRight;
				}					
				else
				{
				    theLeft->next = NULL;
				}					
				if(NULL != thePreviousLeft)
				{
					theRight->prev = thePreviousLeft;
				}	
				else
				{
					theRight->prev = NULL;
				}						
				theRight->next = theNextLeft;
			}			
			else
			{				
				CharNode *thePreviousLeft = theLeft->prev;
				CharNode *theNextRight = theRight->next;
				if(NULL != thePreviousLeft)
				{
				    thePreviousLeft->next = theRight;	
				}
				else
				{
					aList->head = theRight;	
				}														
				if(NULL != theNextRight)
				{
					theNextRight->prev = theLeft;
				}						
				else
				{
					aList->tail = theLeft;
				}
				theLeft->prev = theRight;
				theRight->next = theLeft;
				if(NULL != theNextRight)
				{
					theLeft->next = theNextRight;
				}				
				else
				{
					theLeft->next = NULL;
				}				
				if(NULL != thePreviousLeft)
				{
					theRight->prev = thePreviousLeft;
				}				
				else
				{
					theRight->prev = NULL;
				}	
			}
		}
	}
}
