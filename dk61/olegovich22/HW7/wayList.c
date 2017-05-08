//
// Created by Oleg on 08.05.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wayList.h"

//declaration
wayNode *createWayNodeWithValue(char aName[20], int level, int value);

//create list
wayList *createWayList()
{
    wayList *aList=(wayList *)malloc(sizeof(wayList));

    if (aList!=NULL)
    {
        aList->head=NULL;
        aList->tail=NULL;
        aList->count=0;
    }
    return aList;
}

//destroy list
void destroyWayList(wayList *aList)
{
    if(aList==NULL)
    {
        return;
    }

    if(aList->tail!=NULL && aList->head!=NULL)
    {
        wayNode *aNode=aList->head;
        int counter=0;
        while(counter<aList->count)
        {
            wayNode *aNodeToDelete=aNode;
            aNode=aNode->next;

            free(aNodeToDelete);
            counter++;
        }
    }

    free(aList);
}

//add int to end of list
int addWayValueToList(wayList *aList, char aName[20], int level, int value)
{
    int theResult=-1;

    if (aList!=NULL)
    {
        wayNode *aNode=createWayNodeWithValue(aName, level, value);

        if(aNode!=NULL)
        {

            if(aList->head==NULL && aList->tail==NULL)
            {
                aList->tail=aList->head=aNode;
            }
            else
            {
                // (head) a b c (tail) + d -> (head)a b c=>d (tail)
                wayNode *aTail=aList->tail;
                aList->tail=aNode;
                aTail->next=aNode;
            }

            aList->count++;
            theResult=0;
        }
    }

    return theResult;

}

// print list
void printList(wayList *aList)
{
    if(aList->head==NULL)
        return;

    //printf(" - /root_Lev0");

    wayNode *aNode=aList->head;
    int counter=0;

    while(counter<aList->count)
    {
        printf("/%s%i_Value%i", aNode->name, aNode->level, aNode->value);
        aNode=aNode->next;
        counter++;
    }
    printf("\n");

}


//create node in list
wayNode *createWayNodeWithValue(char aName[20], int level, int value)
{
    wayNode *aNode=(wayNode *)malloc(sizeof(wayNode));

    if (aNode!=NULL)
    {
        int counter=0;
        while(counter<strlen(aName))
        {
            aNode->name[counter]=aName[counter];
            counter++;
        }
        aNode->name[counter]='\0';
        aNode->level=level;
        aNode->value=value;
    }
    return aNode;
}