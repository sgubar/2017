//
// Created by maksi on 5/12/2017.
//

#include "Tool.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static IntNode *createIntNodeWithValue(int anIntValue);

//void swap(IntNode **a, IntNode **b);

IntList *TLCreateIntList()
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

void TLDestroyIntList(IntList *aList)
{
    if (NULL == aList)
    {
        return;
    }

    if (NULL != aList->tail && NULL != aList->head)
    {
        IntNode *theNode = aList->head;

        do
        {
            IntNode *theNodeToDelete = theNode;
            theNode = theNode->next;

            free (theNodeToDelete);

        }while (NULL != theNode);

        free(aList);
    }
}

int TLAddIntValueToList(IntList *aList, int anIntValue)
{
    int theResult = -1;

    if (NULL != aList)
    {
        IntNode *theNode = createIntNodeWithValue(anIntValue);

        if (NULL != theNode)
        {
            // lets to add to the end of the list
            //1. The list is empty
            if (NULL == aList->head && aList->head == aList->tail)
            {
                aList->head = aList->tail = theNode;
            }
            else
            {
                // (head) a b c (tail) + d -> (head)a b c=>d (tail)
                IntNode *theTail = aList->tail;
                aList->tail = theNode;
                theTail->next = theNode;
            }

            aList->count ++;
            theResult = 0;
        }
    }

    return theResult;
}

int TLIntValueAtIndex(IntList *aList, int anIndex)
{
    int theResult = INT_MAX;

    if (NULL == aList || anIndex >= aList->count)
    {
        return theResult;
    }

    IntNode *theNode = aList->head;
    int i = 0;

    do
    {
        if (i == anIndex)
        {
            break;
        }

        theNode = theNode->next;
        i++;

    }while (NULL != theNode);

    return theNode->value;
}

int TLDeliteIntValueAtIndex(IntList *aList, int anIndex)
{

    if (NULL == aList || anIndex >= aList->count || anIndex < 0)
    {
        return -1;
    }

    IntNode *theDelNode;

    if(anIndex == 0)
    {
        theDelNode=aList->head;
        aList->head = aList->head->next;
        free(theDelNode);
        return 0;
    }

    IntNode *theNode = aList->head;

    int i = 0;

    do
    {
        if (i == anIndex-1)
        {
            break;
        }

        theNode = theNode->next;
        i++;

    }while (NULL != theNode);

    if(anIndex == aList->count-1)
    {
        theDelNode = theNode->next;
        theNode->next=NULL;
        aList->tail = theDelNode;
        free(theDelNode);
        return 0;
    }

    theDelNode = theNode->next;

    theNode->next = theNode->next->next;

    free(theDelNode);
    return 0;
}


// print list
void TLPrintList(IntList *aList)
{
    printf("[List] with count (%d):", aList->count);
    IntNode *theNode = aList->head;

    do
    {
        printf("(%d) ", theNode->value);
        theNode = theNode->next;

    }while (NULL != theNode);

    printf ("\n");
}

int TLInsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{

    if (NULL == aList || anIndex >= aList->count || anIndex < 0)
    {
        return -1;
    }

    IntNode *theNode = aList->head;

    if(anIndex==0)
    {
        IntNode *theNewNode0 = createIntNodeWithValue(anIntValue);
        if (NULL == theNewNode0)
        {
            return -1;
        }

        theNewNode0->next=theNode;
        aList->head=theNewNode0;
        aList->count++;

        return 0;
    }

    int i = 0;

    do
    {
        if (i == anIndex-1)
        {
            break;
        }

        theNode = theNode->next;
        i++;

    }while (NULL != theNode);

    // a b c ^ d(1) => a ->d->b c

    IntNode *theNewNode = createIntNodeWithValue(anIntValue);
    if (NULL == theNewNode)
    {
        return -1;
    }

    IntNode *theBNode = theNode;

    theNewNode->next = theBNode->next; //d->b
    theBNode->next = theNewNode; //b->d

    aList->count ++;

    return 0;
}


IntNode *createIntNodeWithValue(int anIntValue)
{
    IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
    if (NULL != theNode)
    {
        theNode->next = NULL;
        theNode->value = anIntValue;
    }

    return theNode;
}



int read_tru(int min_s, int max_s)
{
    int sc_sym;
    int t;
    do
    {
        t=scanf("%i",&sc_sym);
        fflush(stdin);
        if(t!=1 || sc_sym<min_s || sc_sym>max_s) printf("%s","Invalid input. Try again.\n");
    }
    while(t!=1 || sc_sym<min_s || sc_sym>max_s);
    return sc_sym;
}

int Lion_analysis(char *value)
{
    for (int i = 0; i < strlen(value); ++i) {
        if (value[i]>47 && value[i]<58 || i==0 && value[0]==45);
        else return -1;
    }
    return 0;
}

void QuickSort1(IntList *aList, IntNode *pbeg, IntNode *pend)
{
    if(pbeg == pend)
        return;

    IntNode *sup = pbeg;
// Reference element
    IntNode *current = sup->next;
//The first behind the support
    IntNode *help = current;
// Auxiliary element

    //before sup
    IntNode *befsup;

    IntNode *befhelp = sup;
    if (pbeg==aList->head) befsup = NULL;
    else {
        befsup = aList->head;

        while (befsup->next != sup) {
            befsup=befsup->next;
        }
    }

    while( current != (pend)->next )
    {
        help = current;

        if( sup->value > help->value ) {
            befhelp->next = help->next;
            help->next = sup;
            if (sup==aList->head) {
                aList->head = help;
            }
            else
            {
                befsup->next = help;
            }

            if(help == aList->tail)
            {
                aList->tail = befhelp;
            }

            if(sup == pbeg)
            {
                pbeg = help;
            }

            if(pend == help)
            {
                pend = befhelp;
                befsup = help;
                break;
            }
            befsup = help;
        }

        befhelp = current;
        current = current->next;
    }

    if( (pbeg) != sup )
//Если в левой части списка осталось больше одного элемента
        QuickSort1(aList, pbeg, befsup);

    if( (pend) != sup )
//Если в правой части списка осталось больше одного элемента
        QuickSort1(aList, (sup->next), pend );
}

