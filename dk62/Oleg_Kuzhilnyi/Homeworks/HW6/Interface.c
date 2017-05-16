
#include "TLCharList.h"
#include <stdlib.h>
#include "TLCharList.h"
#include "SortingList.h"
#include "DoCreateDestroyList.h"


int doList()
{
    
    CharList *theList = TLCreateCharList();
    if (NULL == theList)
    {
        return -1;
    }
    
    
    TLAddCharSymbolToList(theList, "i");
    TLAddCharSymbolToList(theList, "a");
    TLAddCharSymbolToList(theList, "o");
    TLAddCharSymbolToList(theList, "f");
    
    TLAddCharSymbolToList(theList, "c");
    TLAddCharSymbolToList(theList, "m");
    
    TLAddCharSymbolToList(theList, "d");
    
    TLAddCharSymbolToList(theList, "b");
    TLAddCharSymbolToList(theList, "r");
    
    TLAddCharSymbolToList(theList, "e");
    
    
    printf("\t\t\t Before Sorting\n");
    
    TLPrintList(theList);
    
    printf("\t\t\t After Sorting\n");
    
    
    //bubbleSort(theList);
    quickSort( theList,  0, 9);

    TLPrintList(theList);

     printf ("The value at index %d: (%c)\n", 9,FindCharElementAtIndex(theList, 9));
     printf ("The count of value in the list: %d\n", theList->count);
    
     //TLInsertCharSymbolAtIndex(theList,"L",5);
    TLInsertCharSymbolAtIndex(theList,"L",5);
    
    removeCharNodeAtIndex(theList, 0);
    removeCharNodeAtIndex(theList, 5);
    removeCharNodeAtIndex(theList, 8);

     TLPrintList(theList);
    
    printf ("The count of value in the list: %d\n", theList->count);
    
    TLDestroyIntList(theList);
    
    return 0;
}


CharList *TLCreateCharList()
{
    CharList *theList = (CharList *)malloc(sizeof(CharList));
    
    if (NULL != theList)
    {
        theList->head = NULL;
        theList->tail = NULL;
        theList->count = 0;
    }
    
    return theList;
}

void TLDestroyIntList(CharList *aList)
{
    if (NULL == aList)
    {
        return;
    }
    
    if (NULL != aList->tail && NULL != aList->head)
    {
        CharNode *theNode = aList->head;
        
        do
        {
            CharNode *theNodeToDelete = theNode;
            theNode = theNode->next;
            
            free (theNodeToDelete);
            
        }while (NULL != theNode);
        
        free(aList);
    }
}



