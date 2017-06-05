#include "list.h"
#include <stdlib.h>

CharNode *createCharNodeWithElement(char* anCharElement)
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

char* addCharElementToList(CharList *aList, char* anCharElement)
{
    char* theResult=-1;
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

CharNode *CharElementAtIndex(CharList *aList, int anIndex)
{
	CharNode *theResult = NULL;
	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
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
        printf("(%s) ", theNode->value);
        theNode=theNode->next;
    }while(NULL!= theNode);
    printf ("\n");
}

void minimum(CharList *aList)
{
	int i,j=0;

	CharNode *theNode = CharElementAtIndex(aList,i);
	int min = strlen(theNode->value);
	i=1;
	while(i<9)
	{
		CharNode *theNode = CharElementAtIndex(aList,i);
		int Flag = strlen(theNode->value);
		if(min>=Flag)
		{
			min=Flag;
			j=i;
		}
		if(i==8)
		{
			CharNode *theNode = CharElementAtIndex(aList,j);
			printf("slovo s minimalnoy dlinoy:%s\n",theNode->value);	
		}
		i++;
	}
}

char* InsertCharElementAtIndex(CharList *aList, char* anCharElement, char* anIndex)
{
    char* theResult=-1;
    anIndex--;
    if (NULL==aList||anIndex>=aList->count||anIndex<0)
    {
        return theResult;
    }
    CharNode *theNode=aList->head;
    char* i=0;
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

void DeleteCharElementAtIndex(CharList *aList, char* anIndex)
{
	anIndex--;
    if (NULL!=aList&&anIndex<aList->count)
    {
        char* i=0;
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



