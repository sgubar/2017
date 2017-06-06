#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

static CharNode *createCharNodeWithValue(char aValue);

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

CharNode *createCharNodeWithValue(char aValue)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void CharValueToTree(CharTree *aTree, char aValue)
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
		aTree->count++;
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

		aTree->count++;
	}
}

int counterNodes(CharTree *aTree)
{
	if(NULL != aTree)
	return aTree->count;
}

void printTree(CharTree *aTree)
{
	printf("Back print tree:\n");
		BackPrint(aTree->root);
    printf("\nPlain print tree:\n");
		PlainPrint(aTree->root);
  	printf("\nSymmetric print tree:\n");
		SymmetricPrint(aTree->root);
	
}



CharNode* deleteNodeWithValue(CharTree *aTree,CharNode* aNode, char aValue)
{
	
	if (aNode == NULL) {
		printf("that node is not found\n");
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
			printf("\nDeleted!\n");
		}

		else if (aNode->leftChild == NULL)//in case there is one child
		{
			CharNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\nDeleted!\n");
			aTree->count--;		
		}
		else if (aNode->rightChild == NULL) 
		{
			CharNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\nDeleted!\n");
			aTree->count--;			
		}
		else //in case there are 2 children
		{ 

			CharNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
			printf("\nDeleted!\n");
		}			
	}
	return aNode;
}

CharNode* FindMin(CharNode* aNode)
{
	
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}

void destroyCharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		deleteNode(aTree->root);
		free(aTree);
	}
}

void deleteNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		deleteNode(aNode->leftChild);
		deleteNode(aNode->rightChild);

		free(aNode);
	}
}

void SymmetricPrint(CharNode *aNode)
{
	if(NULL != aNode)
	{
		SymmetricPrint(aNode->leftChild);
		printf("%c", aNode->value);
		SymmetricPrint(aNode->rightChild);
	}
}

void PlainPrint(CharNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%c", aNode->value);
		PlainPrint(aNode->leftChild);
		PlainPrint(aNode->rightChild);
	}
}

void BackPrint(CharNode *aNode)
{
	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf("%c", aNode->value);
	}
}


CharNode* findNodeWithValue(CharTree *aTree, char aValue)
{
	CharNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
		CharNode *theCurrentNode = aTree->root; ///< - start from root
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
