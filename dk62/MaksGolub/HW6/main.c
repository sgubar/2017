#include "List.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	printf("Start a list ...\n");
	DoubleList *theList = CreateList();
	DoubleNode *theNode1 = CreateNodeWithValue(1);
	DoubleNode *theNode2 = CreateNodeWithValue(2);
	DoubleNode *theNode3 = CreateNodeWithValue(3);
	DoubleNode *theNode4 = CreateNodeWithValue(4);
	DoubleNode *theNode5 = CreateNodeWithValue(5);
	DoubleNode *theNode6 = CreateNodeWithValue(6);
	DoubleNode *theNode7 = CreateNodeWithValue(7);

	printf("number of elements: %d\n", CountList(theList));
	AddNode(theList, theNode6);
	AddNode(theList, theNode3);
	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode4);
	AddNode(theList, theNode5);
	printf("number of elements: %d\n", CountList(theList));
	PrintList(theList);
	DeleteElementAtIndex(theList, 1);
	AddNodeAtIndex(theList, theNode7, 3);
	printf("After sorting\n");
	quickSort2(theList, 0, theList->count-1);
	PrintList(theList);
	FreeList(theList);
	
	printf("Done.\n");
}
