//
// Created by Oleg on 07.05.2017.
//

#ifndef HW7_DK_TREE_H
#define HW7_DK_TREE_H

#include <stdio.h>
//list description
typedef struct __tagWayNode wayNode;

struct __tagWayNode
{
    int level;
    int value;
    char name[16];
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

int insertIntValueToTree(intTree *aTree, int aValue);

intNode *findNodeWithValue(intTree *aTree, int aValue);

int deleteNodeWithValue(intTree *aTree, int aValue);

void printTree(intTree *aTree, int typeBypass);

#endif //HW7_DK_TREE_H
