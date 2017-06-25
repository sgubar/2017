//
// Created by 28-07-2014 on 20.06.2017.
//

#ifndef UNTITLED_SINGLELINKEDNODE_H
#define UNTITLED_SINGLELINKEDNODE_H

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

#endif //UNTITLED_SINGLELINKEDNODE_H
