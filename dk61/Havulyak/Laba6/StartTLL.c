#include "TLList.h"
#include "TLNode.h"
#include "StartTLL.h"
#include "QuickSort.h"
#include <stdlib.h>
#include <stdio.h>


void StartTLL()
{
	printf("Start a two-linked list ...\n");
	
	DoubleNode *theNode1 = TLCreateNodeWithDoubleValue(1);
	DoubleNode *theNode2 = TLCreateNodeWithDoubleValue(2);
	DoubleNode *theNode3 = TLCreateNodeWithDoubleValue(3);
	DoubleNode *theNode4 = TLCreateNodeWithDoubleValue(4);
	DoubleNode *theNode5 = TLCreateNodeWithDoubleValue(5);
	DoubleNode *theNode6 = TLCreateNodeWithDoubleValue(6);
	DoubleNode *theNode7 = TLCreateNodeWithDoubleValue(7);
	DoubleNode *theNode8 = TLCreateNodeWithDoubleValue(8);
	DoubleNode *theNode9 = TLCreateNodeWithDoubleValue(9);
	DoubleNode *theNode10 = TLCreateNodeWithDoubleValue(10);
	
	DoubleList *theList = TLCreateList();
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode8);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode6);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode1);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode2);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode4);
	printf("number of elements: %f\n", TLCountList(theList));

    TLAddNode(theList, theNode3);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode9	);
	printf("number of elements: %f\n", TLCountList(theList));
	
	TLAddNode(theList, theNode7);
	printf("number of elements: %f\n", TLCountList(theList));
	
	doPrintTLList(theList);
	
	AddNodeAtIndex(theList,theNode10,1);	
	printf("\nAdded the element at index\n");	
	
	DeleteNodeAtIndex(theList, 0);	
	
	printf("\nDeleted the element at index\n");	
	doPrintTLList(theList);
	
	quickSort2( theList, 0, 8);
	printf("\nafter sort\n");	
	
	doPrintTLList(theList);
	
	TLFreeList(theList);
	
	printf("Done.\n");	
}
	
void doPrintTLList(const DoubleList *aList)
{
	int i;
	DoubleNode *theNode = aList->head;
	for (i = 0; i < TLCountList(aList); i++)
	{
		if (NULL != theNode)
		{
			printf("node[%d].value = % 2f\n", i, theNode->value);
		}
		theNode = theNode->nextNode;
	}
}
