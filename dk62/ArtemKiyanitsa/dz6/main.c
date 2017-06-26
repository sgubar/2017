#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "List.h"
#include "Sort.h"

int main(int argc, const char * argv[])
{
		
	DoubleElement *theElement1 = CreateElementWithDoubleValue(32);
	DoubleElement *theElement2 = CreateElementWithDoubleValue(612);
	DoubleElement *theElement3 = CreateElementWithDoubleValue(23);
	DoubleElement *theElement4 = CreateElementWithDoubleValue(228);
	DoubleElement *theElement5 = CreateElementWithDoubleValue(998);
	DoubleElement *theElement6 = CreateElementWithDoubleValue(2313);
	DoubleElement *theElement7 = CreateElementWithDoubleValue(99);
	DoubleElement *theElement8 = CreateElementWithDoubleValue(81);
	DoubleElement *theElement9 = CreateElementWithDoubleValue(9);
	DoubleElement *theElement10 = CreateElementWithDoubleValue(10);

	DoubleList *theList = CreateList();
	
	AddElement(theList, theElement5);
	AddElement(theList, theElement8);	
	AddElement(theList, theElement6);
	AddElement(theList, theElement1);
	AddElement(theList, theElement2);
	AddElement(theList, theElement4);
	AddElement(theList, theElement3);
	AddElement(theList, theElement9);
	AddElement(theList, theElement7);
	
	doPrintList(theList);
	
	AddElementAtIndex(theList,theElement10,1);	
	printf("\nAdded the element at index\n");	
	
	DeleteElementAtIndex(theList, 0);	
	printf("\nDeleted the element at index\n");	
	doPrintList(theList);
	
	quickSort2( theList, 0, 8);
	printf("\nAfter sort\n");	
	
	doPrintList(theList);
	
	FreeList(theList);
	

	return 0;
}

