//
// Created by Oleg on 07.05.2017.
//

#ifndef HW7_DK_TREE_H
#define HW7_DK_TREE_H

#include <stdio.h>


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

//insert value to tree
//0 - if value inserted
//-1 - otherwise
int insertIntValueToTree(intTree *aTree, int aValue);

//find node in tree
intNode *findNodeWithValue(intTree *aTree, int aValue);

//delete value in tree
//0 - if value deleted
//-1 - otherwise
int deleteNodeWithValue(intTree *aTree, int aValue);

//print tree
void printTree(intTree *aTree, int typeBypass);

#endif //HW7_DK_TREE_H
