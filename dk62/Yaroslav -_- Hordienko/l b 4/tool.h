/*
 * tool.h
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#ifndef TOOL_H_
#define TOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct __DoubleNode DoubleNode;

typedef struct __DoubleList
{

	DoubleNode *head;
	DoubleNode *tail;
	int count;

}DoubleList;

DoubleList *CreateList();
void FreeList(DoubleList *aList);
DoubleNode *AddNode(DoubleList *aList, DoubleNode *aNewNode);
DoubleNode *NodeAtIndex(DoubleList *aList, int anIndex);
int CountList(DoubleList *aList);
void PrintList(DoubleList *aList);
void BackPrintList(DoubleList *aList);

typedef struct __DoubleNode DoubleNode;

// The node declaration
struct __DoubleNode

{
	double value;
	DoubleNode *next;//<! - the reference to next node
	DoubleNode *prev;//<! - the reference to prev node
};

DoubleNode *CreateNodeWithValue(double aValue);
void FreeNode(DoubleNode *aNode);

#endif
