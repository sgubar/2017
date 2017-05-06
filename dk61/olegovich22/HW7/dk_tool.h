//
// Created by Oleg on 05.05.2017.
//

#ifndef HW7_DK_TOOL_H
#define HW7_DK_TOOL_H

#include <stdio.h>
//list description
typedef struct __tagWayNode wayNode;

struct __tagWayNode
{
    int level;
    char name[16];
    //intNode *prev;
    wayNode *next;
};

typedef struct __tagWayList
{
    wayNode *head;
    wayNode *tail;
    int count;

}wayList;

//tree description
typedef struct __tagNode intNode;

typedef struct __tagNode
{
    int value;
    intNode *leftChild;
    intNode *rightChild;
}intNode;

typedef struct __tagTree
{
    intNode *root;
    int count;
}intTree;

// interface
intTree *createIntTree();
void destroyIntTree(intTree *aTree);

void insertIntValueToTree(intTree *aTree, int aValue);

intNode *findNodeWithValue(intTree *aTree, int aValue);

//all bypass function use in loop till when it return NULL
intNode *simetryBypass(intTree *aTree);

intNode *directBypass(intTree *aTree);

intNode *reverseBypass(intTree *aTree);


void deleteNodeWithValue(intTree *aTree, int aValue);

void printTree(intTree *aTree);


#endif //HW7_DK_TOOL_H
