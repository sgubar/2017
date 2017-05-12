//
//  main.c
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//
//Hello
#include <stdio.h>
#include "TLIntList.h"

int main(int argc, const char * argv[])
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
    
    //bubbleSort(theList);
    quickSort(theList, 0, 10);
    printf("\t\t\t Before Sorting\n");

	TLPrintList(theList);
	
    /*
    printf ("The value at index %d: (%c)\n", 9, FindElementAtIndex(theList, 9));
    
	printf ("The count of value in the list: %d\n", theList->count);
	
	TLPrintList(theList);

    TLInsertCharSymbolAtIndex(theList,"L",5);
    */
    
        
    LT_DeleteCharNode(theList,0);

   // printf("theil %c\n",FindElementAtIndex(theList, 8));
    TLPrintList(theList);
    
    
    
   // quickSort( theList ,  0, theList->count);


   // printf("\t\t\t After Sorting\n");
   // TLPrintList(theList);

    
    printf ("The count of value in the list: %d\n", theList->count);

	TLDestroyIntList(theList);


	return 0;
}
