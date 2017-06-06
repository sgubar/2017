/*
 * main.c
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#include <stdio.h>
#include "tool.h"
#include <stdlib.h>
#include <time.h>
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
	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode3);
	AddNode(theList, theNode4);
	AddNode(theList, theNode5);
	AddNode(theList, theNode6);
	printf("number of elements: %d\n", CountList(theList));
	PrintList(theList);
	printf("Back print\n");
	BackPrintList(theList);
	FreeList(theList);

	printf("Done.\n");
}
