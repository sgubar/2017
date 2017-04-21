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
	
	TLAddCharSymbolToList(theList, "a");
    TLAddCharSymbolToList(theList, "b");
    TLAddCharSymbolToList(theList, "c");

    TLAddCharSymbolToList(theList, "d");


    
	TLPrintList(theList);
	
	printf ("The value at index %d: %c\n", 3, TLIntValueAtIndex(theList, 3));
    
	//printf ("The value at index %d: %c\n", 100, TLIntValueAtIndex(theList, 100));
	
	printf ("The count of value in the list: %d\n", theList->count);
	
    
	TLInsertCharSymbolAtIndex(theList, "H", 1);
    

	TLPrintList(theList);

    //LT_ExtractCharNode(theList,3);
    
    printf ("The count of value in the list: %d\n", theList->count);

    
   // quickSort(theList, theList->head, theList->tail);
   //  bubbleSort(theList, theList->count);

    
    
    
	TLDestroyIntList(theList);
	
	// insert code here...
	printf("Hello, World!\n");

	return 0;
}
