#include "tree.h"
#include "Node.h"
#include <stdlib.h>

void SymmetricPrintNode(FloatNode *aNode);
void PlainPrintNode(FloatNode *aNode);
void BackPrintNode(FloatNode *aNode);

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
		aTree->count ++;
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
	
		aTree->count ++;
	}
}

int countNodesWithTree(FloatTree *aTree)
{
	if(NULL != aTree)
		return aTree->count;
}

void printTree(FloatTree *aTree, int Way)
{
	if(NULL == aTree)
		return;
	if(1 == Way)
	{
		putchar('\n');
		SymmetricPrintNode(aTree->root);
	}
	else
	{
		if(2 == Way)
		{
			putchar('\n');
			PlainPrintNode(aTree->root);
		}
		else
		{
			if(3 == Way)
			{	
				putchar('\n');			
				BackPrintNode(aTree->root);
			}
			else			
				printf("Incorrect value!\n");
		}
	}
	
}

void SymmetricPrintNode(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		SymmetricPrintNode(aNode->leftChild);
		printf("%1.1f ",aNode->value);
		SymmetricPrintNode(aNode->rightChild);
	}
}

void PlainPrintNode(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%1.1f ",aNode->value);
		PlainPrintNode(aNode->leftChild);
		PlainPrintNode(aNode->rightChild);
	}
}

void BackPrintNode(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		BackPrintNode(aNode->leftChild);
		BackPrintNode(aNode->rightChild);
		printf("%1.1f ",aNode->value);
	}
}

