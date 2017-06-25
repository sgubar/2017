#include <stdlib.h>

#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *SLCreateList()
{
    //Allocate memory for the list structure
    IntList *theList = (IntList *)malloc(sizeof(IntList));

    //Clean internal data
    theList->head = NULL; //<!- not head
    theList->tail = NULL; //<!- not tail
    theList->count = 0; //<!- initial value of count is zero - no elements in the list

// or
//	bzero(theList, sizeof(IntList));

    return theList;
}

void SLFreeList(IntList *aList)
{
    // Check the input parameter
    if (NULL == aList)
    {
        return;
    }

    //1. Remove all elements
    IntNode *theNode = aList->head;

    while (NULL != theNode)
    {
        IntNode *theNodeToBeFree = theNode;
        theNode = theNode->nextNode;

        free(theNodeToBeFree);
    }

    //2. Free memory for the List structure
    free(aList);
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode)
{
    // Check the input parameter
    if (NULL == aList || NULL == aNewNode)
    {
        return NULL;
    }

    //Add the new node to end of the list

    // a b c d e + G = a b c d e G

    if (NULL == aList->head && NULL == aList->tail)
    {
        //The list is empty
        aList->head = aList->tail = aNewNode;
    }
    else
    {
        IntNode *theTail = aList->tail;
        aList->tail = aNewNode;

        if (NULL != theTail)
        {
            theTail->nextNode = aList->tail;
        }
    }

    aList->count += 1;

    return aNewNode;
}

int SLCountList(const IntList *aList)
{
    int theResult = kSLListError;

    if (NULL != aList)
    {
        theResult = aList->count;
    }

    return theResult;
}

//find node at index
IntNode *SLNodeAtIndex(const IntList *aList, int anIndex)
{
    IntNode *theResult = NULL;

    if (NULL != aList && anIndex < aList->count)
    {
        int i = 0;
        IntNode *theNode = aList->head;

        do
        {
            if (i == anIndex) //<!- index was found
            {
                theResult = theNode; //<! - our node
                break;
            }

            i++; // increase index
            theNode = theNode->nextNode; //<! - go to nextNode node

        } while (NULL != theNode);
    }

    return theResult;
}


/*int SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
    int theResult = -1;

    if(NULL == aList || anIndex >= aList->count || anIndex < 0 )
    {
        return theResult;
    }
    IntNode * theNode = aList->head;
    int i = 0;

    do
    {
        if(i == anIndex)
        {
            break;
        }
        theNode = theNode->nextNode;
        i++;

    }while(NULL != theNode);

    IntNode *aNewNode = SLCreateNodeWithIntValue(anIndex);
    if(NULL == aNewNode)
    {
        return theResult;
    }
    IntNode * theNode = theNode;
    if(NULL != theNode->prev)
    {
        theNode->prev->nextNode = aNewNode;
        aNewNode->prev = theNode->prev;
    }
    else if(NULL == theNode->prev)
    {
        //FloatNode *aTailNode = aList->tail;
        aList->head = aNewNode;
        aNewNode->nextNode = theNode;
        theNode->prev = aNewNode;
    }
    else if(theNode->nextNode == aList->tail)
    {
        FloatNode *aTailNode = aList->tail;
        aList->tail = aNewNode;
        aTailNode->nextNode = aNewNode;
        aNewNode->prev = aTailNode;
    }
    //else
    //{
    aNewNode->nextNode = theNode;
    theNode->prev = aNewNode;
    //}
    aList->count ++;
    theResult = 0;

    return theResult;
}*/
int SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{

//	if anIndex<=0 || anIndex>aList>count-1;
//	{
    //	return;
    //}

    IntNode *theNode = SLNodeAtIndex (aList, anIndex);
    if (theNode == NULL)
    {
        return -1;
    }
    //1. when list have only 1 element
    if (aList->count == 1)
    {

        aList->count =0;
        aList->tail = NULL;
        aList->head = NULL;
        free(theNode);
        return 0;
    }
    //2. delete head
    if  (anIndex == 0)
    {
        IntNode *aNode=aList->head->nextNode;
        aList->head = aNode;
//	aList->head->nextNode =aNode->nextNode;
    }
    else //3.Delete tail
    if (anIndex == aList->count-1)
    {
        aList->tail = SLNodeAtIndex(aList, anIndex-1);
        aList->tail->nextNode=NULL;
    }
    else //4.Deleting middle value

    {
        IntNode *middleNode= SLNodeAtIndex (aList, anIndex-1);
        middleNode->nextNode = theNode->nextNode;
    }
    aList->count --;
    free(theNode);
    return 0;
}