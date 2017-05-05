//
// Created by Oleh on 22.04.2017.
//

#include "dk_list.h"
#include <stdlib.h>
#include <stdio.h>

//declaration


//create list
intList *createIntList()
{
    intList *aList=(intList *)malloc(sizeof(intList));

    if (aList!=NULL)
    {
        aList->count=0;
        aList->head=NULL;
        aList->tail=NULL;
    }
    return aList;
}

//destroy list
void destroyIntList(intList *aList)
{
    if(aList==NULL)
    {
        return;
    }

    if(aList->tail!=NULL && aList->head!=NULL)
    {
        intNode *aNode=aList->head;

        while(aNode!=NULL)
        {
            intNode *aNodeToDelete=aNode;
            aNode=aNode->next;

            free(aNodeToDelete);
        }
    }

    free(aList);
}

//add int to end of list
int addIntValueToList(intList *aList, int anIntValue)
{
    int theResult=-1;

    if (aList!=NULL)
    {
        intNode *aNode=createIntNodeWithValue(anIntValue);

        if(aNode!=NULL)
        {
            if(aList->head==NULL && aList->tail==NULL)
            {
                aList->tail=aList->head=aNode;
            }
            else
            {
                // (head) a b c (tail) + d -> (head)a b c=>d (tail)
                intNode *aTail=aList->tail;
                aList->tail=aNode;
                aNode->prev=aTail;
                aTail->next=aNode;
            }

            aList->count++;
            theResult=0;
        }
    }

    return theResult;
}

//insert int value in list by index
int insertIntValueAtIndex(intList *aList, int anIntValue, int anIndex)
{
    int theResult=-1;

    if(aList==NULL || anIndex>aList->count || anIndex<0)
    {
        return theResult;
    }

    // a b c ^ d(1) => a ->d->b c
    intNode *aNewNode=createIntNodeWithValue(anIntValue);
    if(aNewNode==NULL)
        return theResult;

    if(anIndex==0)
    {
        aNewNode->next=aList->head;
        aList->head=aNewNode;
    }
    else if(anIndex==aList->count-1)
    {
        aList->tail->next=aNewNode;
        aNewNode->prev=aList->tail;
        aList->tail=aNewNode;
    }
    else
    {
        intNode *aNode=intNodeAtIndex(aList, anIndex);
        aNewNode->next=aNode;
        aNewNode->prev=aNode->prev;
        aNode->prev->next=aNewNode;
        aNode->prev=aNewNode;

    }
    aList->count++;

    theResult=0;

    return theResult;

}

//delete int value in list by index
void deleteIntValueAtIndex(intList *aList, int anIndex)
{
    if(aList==NULL || anIndex>=aList->count || anIndex<0)
    {
        printf("You have wrong index or problem with list\n");
        return;
    }

    if(aList->count==1)
    {
        intNode *aNode=aList->head;
        aList->head=NULL;
        aList->tail=NULL;
        free(aNode);
    }
    else if(anIndex==0)
    {
        intNode *aNode=aList->head;
        aList->head=aList->head->next;
        aList->head->prev=NULL;
        free(aNode);
    }
    else if(anIndex==aList->count-1)
    {
        intNode *aNode=aList->tail;
        aList->tail=aList->tail->prev;
        aList->tail->next=NULL;
        free(aNode);
    }
    else
    {
        intNode *aNode=intNodeAtIndex(aList, anIndex);
        aNode->prev->next=aNode->next;
        aNode->next->prev=aNode->prev;
        free(aNode);
    }
    aList->count--;
}

//delete int value
int deleteIntValue(intList *aList, int key)
{
    int index=searchKeyPosition(aList, key);
    if (index==-1)
    {
        return -1;
    }

    deleteIntValueAtIndex(aList, index);
    return 0;
}

// return value at index
int intValueAtIndex(intList *aList, int anIndex)
{
    if(aList==NULL || anIndex>=aList->count || anIndex<0)
    {
        return -1;
    }

    intNode *aNode=intNodeAtIndex(aList, anIndex);

    return aNode->value;
}

// print list
void printList(intList *aList)
{
    if(aList==NULL || aList->count==0)
    {
        printf("Your List haven't elements\n");
        return;
    }

    printf("LIST(%i elements):", aList->count);

    intNode *aNode=aList->head;
    int counter=0;

    while(counter<aList->count)
    {
        printf(" (%i)%i", counter, aNode->value);
        aNode=aNode->next;
        counter++;
    }
    printf("\n");

}

//return address of node which user to need
intNode *intNodeAtIndex(intList *aList, int anIndex)
{
    if(aList==NULL || aList->count==0)
    {
        return NULL;
    }
    intNode *aNode=aList->head;
    int counter=0;

    while(counter<anIndex)
    {
        aNode=aNode->next;
        counter++;
    }
    return aNode;
}

//create node
intNode *createIntNodeWithValue(int anIntValue)
{
    intNode *aNode=(intNode *)malloc(sizeof(intNode));

    if (aNode!=NULL)
    {
        aNode->value=anIntValue;
        aNode->next=NULL;
        aNode->prev=NULL;
    }
    return aNode;
}

//search key position in list
int searchKeyPosition(intList *aList, int key)
{
    int theResult=-1;
    if(aList==NULL || aList->count==0)
    {
        return theResult;
    }


    intNode *aNode=aList->head;
    int counter=0;

    while(counter<aList->count)
    {
        if(aNode->value==key)
        {
            theResult=counter;
            break;
        }
        aNode=aNode->next;
        counter++;
    }
    return theResult;
}