//
// Created by Oleg on 08.05.2017.
//

#ifndef LW5_DK_TREE_H
#define LW5_DK_TREE_H

#include <stdio.h>


//tree description
typedef struct __tagNode doubleNode;

typedef struct __tagNode
{
    double value;
    doubleNode *leftChild;
    doubleNode *rightChild;
}doubleNode;

typedef struct __tagTree
{
    doubleNode *root;
    int count;
}doubleTree;

// interface
doubleTree *createDoubleTree();
void destroyDoubleTree(doubleTree *aTree);

//insert value to tree
//0 - if value inserted
//-1 - otherwise
int insertDoubleValueToTree(doubleTree *aTree, double aValue);

//find node in tree
doubleNode *findNodeWithValue(doubleTree *aTree, double aValue);

//delete value in tree
//0 - if value deleted
//-1 - otherwise
int deleteNodeWithValue(doubleTree *aTree, double aValue);

//print tree
void printTree(doubleTree *aTree, int typeBypass);

#endif //LW5_DK_TREE_H
