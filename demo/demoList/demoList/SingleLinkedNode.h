//
//  SingleLinkedNode.h
//  demoList
//
//  Created by Slava Gubar on 3/2/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	IntNode *nextNode;//<! - the reference to next node
};

//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(int aValue);
//Free a created node
void SLFreeIntNode(IntNode *aNode);

#endif /* SingleLinkedNode_h */
