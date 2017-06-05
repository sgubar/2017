#include "tree.h"
#include "Node.h"
#include <stdlib.h>

void SymmetricPrintNode(intNode *aNode);
void PlainPrintNode(intNode *aNode);
void BackPrintNode(intNode *aNode);

Tree *createTree()
{
	Tree *theTree = (Tree *)malloc(sizeof(Tree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyTree(Tree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
		
	}
}

void insertValueToTree(Tree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	intNode *theNode = createintNodeWithValue(aValue);
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
		intNode *theCurrent = aTree->root;
		intNode *theParent = NULL;

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

int countNodesWithTree(Tree *aTree)
{
	if(NULL != aTree)
		return aTree->count;
}

void printTree(Tree *aTree, int Way)
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
void SymmetricPrintNode(intNode *aNode)
{
	if(NULL != aNode)
	{
		SymmetricPrintNode(aNode->leftChild);
		printf("%d ",aNode->value);
		SymmetricPrintNode(aNode->rightChild);
	}
}

void PlainPrintNode(intNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%d ",aNode->value);
		PlainPrintNode(aNode->leftChild);
		PlainPrintNode(aNode->rightChild);
	}
}

void BackPrintNode(intNode *aNode)
{
	if(NULL != aNode)
	{
		BackPrintNode(aNode->leftChild);
		BackPrintNode(aNode->rightChild);
		printf("%d ",aNode->value);
	}
}