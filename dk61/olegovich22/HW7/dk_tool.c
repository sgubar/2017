//
// Created by Oleg on 05.05.2017.
//

#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>

//declaration
void destroyNode(intNode *aNode);
intNode *createIntNodeWithValue(int aValue);

//list way declaration
wayNode *createWayNodeWithValue(char aName[16], int level);
wayList *createWayList();
void destroyWayList(wayList *aList);
int addWayValueToList(wayList *aList, char aName[20], int level);
void printList(wayList *aList);


intTree *createIntTree()
{
    intTree *aTree=(intTree *)malloc(sizeof(intTree));

    if(aTree!=NULL)
    {
        aTree->count=0;
        aTree->root=NULL;
    }

    return aTree;
}

void destroyIntTree(intTree *aTree)
{
    if(aTree!=NULL)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

void insertIntValueToTree(intTree *aTree, int aValue)
{
    if(aTree==NULL)
        return;

    intNode *aNode=createIntNodeWithValue(aValue);
    if(aNode==NULL)
        return;

    if(aTree->root==NULL)
    {
        aTree->root=aNode;
    }
    else
    {
        intNode *theCurrent=aTree->root;
        while(1)
        {
            if(theCurrent->value==aValue)
            {
                printf("can't be 2 the same elements\n");
                break;
            }
            else if(theCurrent->value>aValue)
            {
                if(theCurrent->leftChild==NULL)
                {
                    theCurrent->leftChild=aNode;
                    break;
                }
                theCurrent=theCurrent->leftChild;
            }
            else if(theCurrent->value<aValue)
            {
                if(theCurrent->rightChild==NULL)
                {
                    theCurrent->rightChild=aNode;
                    break;
                }
                theCurrent=theCurrent->rightChild;
            }

        }
    }
    aTree->count++;
}

intNode *findNodeWithValue(intTree *aTree, int aValue)
{
    intNode *theResult=NULL;

    if(aTree==NULL)
        return theResult;

    if(aTree->root==NULL)
    {
        printf("Not found. Tree haven't elements\n");
        return theResult;
    }
    else
    {
        wayList *aList=createWayList();
        int counter=1;

        intNode *theCurrent=aTree->root;
        while(1)
        {
            if(theCurrent->value==aValue)
            {
                theResult=theCurrent;
                printList(aList);
                break;
            }
            else if(theCurrent->value>aValue)
            {
                if(theCurrent->leftChild==NULL)
                {
                    printf("Not found\n");
                    break;
                }
                addWayValueToList(aList, "left_Child_Lev", counter);
                theCurrent=theCurrent->leftChild;
            }
            else if(theCurrent->value<aValue)
            {
                if(theCurrent->rightChild==NULL)
                {
                    printf("Not found\n");
                    break;
                }
                addWayValueToList(aList, "right_Child_Lev", counter);
                theCurrent=theCurrent->rightChild;
            }

            counter++;

        }

        destroyWayList(aList);
    }

    return theResult;

}

void printTree(intTree *aTree)
{

}





void destroyNode(intNode *aNode)
{
    if(aNode!=NULL)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);
        free(aNode);
    }
}

intNode *createIntNodeWithValue(int aValue)
{
    intNode *aNode=(intNode *)malloc(sizeof(intNode));

    if(aNode!=NULL)
    {
        aNode->rightChild=NULL;
        aNode->leftChild=NULL;
        aNode->value=aValue;
    }
    return aNode;
}

//------list-------
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

wayNode *createWayNodeWithValue(char aName[20], int level)
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
    }
    return aNode;
}

//add int to end of list
int addWayValueToList(wayList *aList, char aName[20], int level)
{
    int theResult=-1;

    if (aList!=NULL)
    {
        wayNode *aNode=createWayNodeWithValue(aName, level);

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
                //aNode->prev=aTail;
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

    printf("WAY TO ELEMENT - /root_Lev0");

    wayNode *aNode=aList->head;
    int counter=0;

    while(counter<aList->count)
    {
        printf("/%s%i", aNode->name, aNode->level);
        aNode=aNode->next;
        counter++;
    }
    printf("\n");

}
//----list------




