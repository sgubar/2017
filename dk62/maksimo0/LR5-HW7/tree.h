//
//  tree.h
//  HW7
//
//  Created by Maxim Salim on 04.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
    int value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} IntNode;

typedef struct __tagTree
{
    IntNode *root;
    int count;
} intTree;

intTree *createIntTree();

void destroyIntTree(intTree *aTree);

void insertIntValueToTree(intTree *aTree, int aValue);

void deleteNodeWithValue(intTree *aTree, int aValue);

int countNodesWithTree(intTree *aTree);

void printTree(intTree *aTree);

void plainPrintNode(IntNode *aNode);


#endif /* tree_h */
