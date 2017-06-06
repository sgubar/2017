#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>

static void destroyNode(FloatNode *aNode);
static FloatNode *createFloatNodeWithValue(float aValue);

FloatTree *createFloatTree()
{
	FloatTree *theTree = (FloatTree *)malloc(sizeof(FloatTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyFloatTree(FloatTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertFloatValueToTree(FloatTree *aTree, float aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	FloatNode *theNode = createFloatNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		FloatNode *theCurrent = aTree->root;
		FloatNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count++;
	}
}

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{
	FloatNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
		FloatNode *theCurrentNode = aTree->root; ///< - start from root
		while (aValue != theCurrentNode->value) ///< - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
				? theCurrentNode->leftChild
				: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
		return theCurrentNode;
	}

	
	return theCurrentNode;
}



void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

FloatNode *createFloatNodeWithValue(float aValue)
{
	FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void printTree(FloatTree *aTree)	
{
	if (NULL != aTree) 
	{
		BackPrint(aTree->root);
    }

}

void BackPrint(FloatNode *aNode)
{

	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf("%f  ", aNode->value);
	}

}

FloatNode *FindMin(FloatNode* aNode)
{
	
	while (aNode->leftChild != NULL) 
	aNode = aNode->leftChild;
	return aNode;
}

FloatNode* deleteNodeWithValue(FloatTree *aTree,FloatNode* aNode, float aValue)
{
	
	if (aNode == NULL) 
	{
		printf("This node is not in the tree.\n");
		return NULL;
	}
	
	else if (aValue < aNode->value)
	aNode->leftChild = deleteNodeWithValue(aTree,aNode->leftChild, aValue);

	else if (aValue > aNode->value)
	aNode->rightChild = deleteNodeWithValue(aTree , aNode->rightChild, aValue);

	else 
	{

		if (aNode->leftChild == NULL && aNode->rightChild == NULL) //in case there are no child
		{
			free(aNode);
			aNode = NULL;
			aTree->count--;
			printf("\n\nNode successfully deleted!\n");
		}

		else if (aNode->leftChild == NULL) //in case there is one child
		{
			FloatNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\n\nNode successfully deleted!\n");
			aTree->count--;
			
		}
		
		else if (aNode->rightChild == NULL) 
		{
			FloatNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\n\nNode successfully deleted!\n");
			aTree->count--;
			
		}
	
		else //in case there are 2 children
		{ 

			FloatNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
			printf("\n\nNode successfully deleted!\n");
		}	
	}
	return aNode;
}

int countNodesWithTree(FloatTree *aTree)
{
	if (NULL != aTree)
		return aTree->count;
	return 0;
}
