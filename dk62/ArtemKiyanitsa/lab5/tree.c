#include "tree.h"
#include "Node.h"
#include <stdlib.h>



DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

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
	
		aTree->count ++;
	}
}

int countNodesWithTree(DoubleTree *aTree)
{
	if(NULL != aTree)
		return aTree->count;
}

void printTree(DoubleTree *aTree)
{
	if(NULL == aTree)
		return;
	else
	{
		putchar('\n');
		PlainPrintNode(aTree->root);
		
	}
	
}


void PlainPrintNode(DoubleNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%0.2f ",aNode->value);
		PlainPrintNode(aNode->leftChild);
		PlainPrintNode(aNode->rightChild);
	}
}


