#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>

typedef struct __Node slNode;

struct __Node
{
	char letter;
	int letterEntryCounter;
	slNode *nextNode; 					//the reference to next node
};

//Create a new Node with char value
slNode *createNodeWithCharValue(char aValue);

#endif 
