//
//  list.c
//  LR4
//
//  Created by Maxim Salim on 05.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#include "list.h"
#include <stdlib.h>

IntNode *createIntNodeWithValue(int anIntValue)
{
    IntNode *theNode=(IntNode *)malloc(sizeof(IntNode));
    if(NULL!=theNode)
    {
        theNode->next=NULL;
        theNode->prev=NULL;
        theNode->value=anIntValue;
    }
    return theNode;
}

IntList *CreateIntList()
{
    IntList *theList=(IntList *)malloc(sizeof(IntList));
    if(NULL!=theList)
    {
        theList->head=NULL;
        theList->tail=NULL;
        theList->count=0;
    }
    return theList;
}

void DestroyIntList(IntList *aList)
{
    if(NULL==aList)
    {
        return;
    }
    if(NULL!=aList->tail&&NULL!=aList->head)
    {
        IntNode *theNode=aList->head;
        do
        {
            IntNode *theNodeToDelete=theNode;
            theNode=theNode->next;
            free(theNodeToDelete);
        }while(aList->head!=theNode);
        free(aList);
    }
}

int AddIntValueToList(IntList *aList, int anIntValue)
{
    int theResult=-1;
    if(NULL!=aList)
    {
        IntNode *theNode=createIntNodeWithValue(anIntValue);
        if(NULL!=theNode)
        {
            if(NULL==aList->head&&aList->head==aList->tail)
            {
                aList->head=theNode;
                aList->tail=theNode;
            }
            else
            {
                IntNode *theTail=aList->tail;
                aList->tail=theNode;
                theTail->next=theNode;
                theNode->prev=theTail;
            }
            
            aList->tail->next=aList->head;
            aList->head->prev=aList->tail;
            
            aList->count++;
            theResult=0;
        }
    }
    return theResult;
}

IntNode *TheMinNode(IntList *aList)
{
    IntNode *theNode=aList->head;
    IntNode *theMin=NULL;
    theMin=theNode;
    do
    {
        if(theMin->value>theNode->value)
        {
            theMin=theNode;
            //if(theNode->next==aList->head)
            //{
            //return theMin;
            //}
            theNode=theNode->next;
        }
        else
        {
            if(theNode->next==aList->head)
            {
                return theMin;
            }
            theNode=theNode->next;
        }
    }while(1);
    return theMin;
}

void PrintList(IntList *aList)
{
    printf("[List] with count (%d):\n", aList->count);
    IntNode *theNode = NULL;
    theNode=TheMinNode(aList);
    for(int i=0; i<aList->count+5;i++)
    {
        printf("[Node] with number (%d):%d\n ", i+1, theNode->value);
        theNode=theNode->next;
    }
}



