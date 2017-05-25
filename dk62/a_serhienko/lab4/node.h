#ifndef node
#define node

#include <stdio.h>
#include "list.h"

typedef struct __Node Node;




struct __Node
{
	char symbol;
	int counter;//counter of entry points
	Node*next;
	

};

Node *createNodeWithValue(char aValue);
void CountEntryPoints(List* aList);
void IncrementOrCreateNodeByValue(List *aList, char aValue, int size);
void CreateNodeAndAddtoList(List*aList, char text, Node*theNode);
#endif 