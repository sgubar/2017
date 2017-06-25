#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");

	IntNode *theNode2 = SLCreateNodeWithIntValue(2);

	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));



	 SLRemovedNodeAtIndex(theList,0);
    //SLInsertIntValueAtIndex(theList, 1, 2);
	doPrintSLList(theList);

	SLFreeList(theList);

	printf("Done.\n");
}

void doPrintSLList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}