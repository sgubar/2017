//
//  main.c
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "TLIntList.h"

int main(int argc, const char * argv[])
{
	IntList *theList = TLCreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	TLAddIntValueToList(theList, 34);
	TLAddIntValueToList(theList, 344);
	TLAddIntValueToList(theList, 343);
	TLAddIntValueToList(theList, 342);
	TLAddIntValueToList(theList, 345);
	TLAddIntValueToList(theList, 346);
	TLAddIntValueToList(theList, 347);
	TLAddIntValueToList(theList, 343);
	TLAddIntValueToList(theList, 345);
	
	TLPrintList(theList);
	
	printf ("The value at index %d: %d\n", 3, TLIntValueAtIndex(theList, 3));

	printf ("The value at index %d: %d\n", 100, TLIntValueAtIndex(theList, 100));
	
	printf ("The count of value in the list: %d\n", theList->count);
	
	TLInsertIntValueAtIndex(theList, 123456, 3);
	TLPrintList(theList);

	
	TLDestroyIntList(theList);
	
	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
