//
 +//  tree.c
 +//  demoTree2
 +//
 +//  Created by Slava Gubar on 4/25/17.
 +//  Copyright © 2017 Slava Gubar. All rights reserved.
 +//
 +
 +#include "tree.h"
 +#include <stdlib.h>
 +
 +static void destroyNode(ShortNode *aNode);
 +static ShortNode *createShortNodeWithValue(short aValue);
 +
 +ShortTree *createShortTree()
 +{
 +	ShortTree *theTree = (ShortTree *)malloc(sizeof(ShortTree));
 +	
 +	if (NULL != theTree)
 +	{
 +		theTree->root = NULL;
 +		theTree->count = 0;
 +	}
 +	
 +	return theTree;
 +}
 +
 +void destroyShortTree(ShortTree *aTree)
 +{
 +	if (NULL != aTree)
 +	{
 +		destroyNode(aTree->root);
 +		free(aTree);
 +	}
 +}
 +
 +void insertShortValueToTree(ShortTree *aTree, short aValue)
 +{
 +	if (NULL == aTree)
 +	{
 +		return;
 +	}
 +
 +	ShortNode *theNode = createShortNodeWithValue(aValue);
 +	if (NULL == theNode)
 +	{
 +		return;
 +	}
 +	
 +	if (NULL == aTree->root)
 +	{
 +		aTree->root = theNode;
 +		aTree->count ++;
 +	}
 +	else
 +	{
 +		ShortNode *theCurrent = aTree->root;
 +		ShortNode *theParent = NULL;
 +
 +		while (1)
 +		{
 +			theParent = theCurrent;
 +		
 +			if (aValue < theCurrent->value)
 +			{
 +				theCurrent = theCurrent->leftChild;
 +				if (NULL == theCurrent)
 +				{
 +					theParent->leftChild = theNode;
 +					break;
 +				}
 +			}
 +			else
 +			{
 +				theCurrent = theCurrent->rightChild;
 +				if (NULL == theCurrent)
 +				{
 +					theParent->rightChild = theNode;
 +					break;
 +				}
 +			}
 +		}
 +	
 +		aTree->count ++;
 +	}
 +}
 +
 +ShortNode *findNodeWithValue(ShortTree *aTree, short aValue)
 +{
 +	ShortNode *theCurrentNode = NULL;
 +	
 +	if (NULL != aTree)
 +	{
 +		ShortNode *theCurrentNode = aTree->root; //<! - start from root
 +		while (aValue != theCurrentNode->value) //<! - walk through the tree
 +		{
 +			theCurrentNode = (aValue < theCurrentNode->value)
 +						? theCurrentNode->leftChild
 +						: theCurrentNode->rightChild;
 +		
 +			if (NULL == theCurrentNode)
 +			{
 +				break;
 +			}
 +		}
 +	}
 +	
 +	int a = 5;
 +	int b = 7;
 +	
 +	int c = (a > b) ? 5 : 8;
 +	
 +	return theCurrentNode;
 +}
 +
 +void deleteNodeWithValue(ShortTree *aTree, short aValue);
 +
 +void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);
 +
 +void printTree(ShortTree *aTree);
 +int countNodesWithTree(ShortTree *aTree);
 +
 +#pragma mark -
 +void destroyNode(ShortNode *aNode)
 +{
 +	if (NULL != aNode)
 +	{
 +		destroyNode(aNode->leftChild);
 +		destroyNode(aNode->rightChild);
 +	
 +		free(aNode);
 +	}
 +}
 +
 +ShortNode *createShortNodeWithValue(short aValue)
 +{
 +	ShortNode *theNode = (ShortNode *)malloc(sizeof(ShortNode));
 +	
 +	if (NULL != theNode)
 +	{
 +		theNode->leftChild = NULL;
 +		theNode->rightChild = NULL;
 +		theNode->value = aValue;
 +	}
 +	
 +	return theNode;
 +}
 +
