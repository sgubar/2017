#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
//
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

void floatValueToTree(FloatTree *aTree, float aValue)
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

int counterNodes(FloatTree *aTree)
{
	if(NULL != aTree)
	return aTree->count;
}

void printTree(FloatTree *aTree)
{
	
     printf("\nPlain print tree:\n");
		PlainPrint(aTree->root);  
  
	
}


FloatNode* FindMin(FloatNode* aNode)
{
	
	while (aNode->leftChild != NULL)
	 aNode = aNode->leftChild;
	return aNode;
}


void PlainPrint(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%1.1f ",aNode->value);
		PlainPrint(aNode->leftChild);
		PlainPrint(aNode->rightChild);
	}
}




FloatNode* findNodeWithValue(FloatTree *aTree, float aValue)
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
