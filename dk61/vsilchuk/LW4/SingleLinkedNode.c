#include "SingleLinkedNode.h"
#include <stdlib.h>

slNode *createNodeWithCharValue(char aValue)
{
	slNode *newNode = (slNode *)malloc(sizeof(slNode));
	
	newNode->letter = aValue;
	newNode->letterEntryCounter = 0;
	newNode->nextNode = NULL;
	
	return newNode;
}

