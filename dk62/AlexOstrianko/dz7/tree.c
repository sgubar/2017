#include "tree.h"
#include "Node.h"
#include <stdlib.h>

void SymmetricPrintNode(CharNode *aNode);
void PlainPrintNode(CharNode *aNode);
void BackPrintNode(CharNode *aNode);

CharTree *createCharTree()
{
	CharTree *theTree = (CharTree *)malloc(sizeof(CharTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyCharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertCharValueToTree(CharTree *aTree, char aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	CharNode *theNode = createCharNodeWithValue(aValue);
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
		CharNode *theCurrent = aTree->root;
		CharNode *theParent = NULL;

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

int countNodesWithTree(CharTree *aTree)
{
	if(NULL != aTree)
		return aTree->count;
}

void printTree(CharTree *aTree, int Way)
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

void SymmetricPrintNode(CharNode *aNode)
{
	if(NULL != aNode)
	{
		SymmetricPrintNode(aNode->leftChild);
		printf("%c",aNode->value);
		SymmetricPrintNode(aNode->rightChild);
	}
}

void PlainPrintNode(CharNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%c",aNode->value);
		PlainPrintNode(aNode->leftChild);
		PlainPrintNode(aNode->rightChild);
	}
}

void BackPrintNode(CharNode *aNode)
{
	if(NULL != aNode)
	{
		BackPrintNode(aNode->leftChild);
		BackPrintNode(aNode->rightChild);
		printf("%c",aNode->value);
	}
}

