#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "List.h"
#include "Sort.h"

int main(int argc, const char * argv[])
{
		
	DoubleElement *theElement1 = CreateElementWithDoubleValue(3.2);
	DoubleElement *theElement2 = CreateElementWithDoubleValue(6.12);
	DoubleElement *theElement3 = CreateElementWithDoubleValue(2.3);
	DoubleElement *theElement4 = CreateElementWithDoubleValue(2.28);
	DoubleElement *theElement5 = CreateElementWithDoubleValue(9.98);
	DoubleElement *theElement6 = CreateElementWithDoubleValue(23.13);
	DoubleElement *theElement7 = CreateElementWithDoubleValue(9.9);
	DoubleElement *theElement8 = CreateElementWithDoubleValue(8.1);
	DoubleElement *theElement9 = CreateElementWithDoubleValue(9);
	DoubleElement *theElement10 = CreateElementWithDoubleValue(1.01);

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
	printf("\nDeleted the element at index 0\n");	
	doPrintList(theList);
	
	quickSort2( theList, 0, 8);
	printf("\nAfter sort\n");	
	
	doPrintList(theList);
	
	FreeList(theList);
	

	return 0;
}

