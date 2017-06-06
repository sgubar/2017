#include <stdio.h>

#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

int main()
{
	printf("Okay, let's start working with singleLinkedLists...\n");
	
	slList *theList = SLCreateList();

	entryCounterFunction(theList);
	
	finalPrinting(theList);
	
	SLFreeList(theList);
	
	printf("\nDone.\n");

	return 0;
}
