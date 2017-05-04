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
    
    printf("\t\t\t Before Sorting\n");

	TLPrintList(theList);
	
    /*
	printf ("The value at index %d: %c\n", 3, TLIntValueAtIndex(theList, 3));
    
	printf ("The count of value in the list: %d\n", theList->count);
	
	TLPrintList(theList);

    TLInsertCharSymbolAtIndex(theList,"L",5);
    LT_ExtractCharNode(theList,0);
    
    TLPrintList(theList);
    */
    
    
    quickSort( theList ,  0, theList->count);

    //bubbleSort(theList);

    printf("\t\t\t After Sorting\n");
    TLPrintList(theList);

    
    printf ("The count of value in the list: %d\n", theList->count);

	TLDestroyIntList(theList);


	return 0;
}
