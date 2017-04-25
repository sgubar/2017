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

    TLAddCharSymbolToList(theList, "e");

    TLAddCharSymbolToList(theList, "f");
    TLAddCharSymbolToList(theList, "r");
    TLAddCharSymbolToList(theList, "m");
    
    TLAddCharSymbolToList(theList, "o");
    
    TLAddCharSymbolToList(theList, "i");
    
	TLPrintList(theList);
	
	printf ("The value at index %d: %c\n", 3, TLIntValueAtIndex(theList, 3));
    
	printf ("The count of value in the list: %d\n", theList->count);
	
	TLPrintList(theList);

    TLInsertCharSymbolAtIndex(theList,"L",5);
    LT_ExtractCharNode(theList,0);
    
    TLPrintList(theList);

    
    bubbleSort(theList);
    TLPrintList(theList);

    
    printf ("The count of value in the list: %d\n", theList->count);

	TLDestroyIntList(theList);
	
	// insert code here...
	printf("Hello, World!\n");

	return 0;
}
