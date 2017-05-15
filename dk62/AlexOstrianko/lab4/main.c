#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "List.h"
#include "Sort.h"
#include "tool.h"

int main(int argc, const char * argv[])
{
	printf("Start to demo a double-linked list ...\n");
	
	DoubleList *theList = CreateList();
	
	AddElement(theList, "1");
	AddElement(theList, "12");	
	AddElement(theList, "12345678");
	AddElement(theList, "123");
	AddElement(theList, "12345");
	AddElement(theList, "123456");
	AddElement(theList, "1234");
	AddElement(theList, "123456789");
	AddElement(theList, "1234567");	
	doPrintList(theList);
	
	printf("Enter value of element to add: ");
	char *ValueOfElementToAdd = EnterValueOfElementToAdd();	
	printf("Enter index of element to add: ");
	int IndexOfElement = EnterIndex(theList);	
	AddElementAtIndex(theList,ValueOfElementToAdd,IndexOfElement);	
	printf("\nAdded the element at index\n");
	doPrintList(theList);	
	
	printf("Enter index of element to delete: ");
	IndexOfElement = EnterIndex(theList);
	DeleteElementAtIndex(theList, IndexOfElement);	
	printf("\nDeleted the element at index\n");	
	doPrintList(theList);
	
	quickSort2(theList, 0, CountList(theList)-1);
	printf("\nafter sort\n");	
	doPrintList(theList);
	
	FreeList(theList);
	
	printf("Done.\n");

	return 0;
}



