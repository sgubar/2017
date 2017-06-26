#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "List.h"
#include "Sort.h"
#include "tool.h"

int main(int argc, const char * argv[])
{	
	DoubleList *theList = CreateList();
	
	AddElement(theList, "32142");
	AddElement(theList, "2344");	
	AddElement(theList, "2");
	AddElement(theList, "214322");
	AddElement(theList, "335");
	AddElement(theList, "123456");
	AddElement(theList, "12345678");
	AddElement(theList, "1245673");
	AddElement(theList, "123456789");
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
	printf("\nAfter sort\n");	
	doPrintList(theList);
	


	FreeList(theList);
	return 0;
}
