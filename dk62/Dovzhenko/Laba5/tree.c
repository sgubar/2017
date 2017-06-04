#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("Back print tree:\n");
		BackPrint(aTree->root);
    printf("\nPlain print tree:\n");
		PlainPrint(aTree->root);
  	printf("\nSymmetric print tree:\n");
		SymmetricPrint(aTree->root);
	
}



FloatNode* deleteNodeWithValue(FloatTree *aTree,FloatNode* aNode, float aValue)
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
			FloatNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\nDeleted!\n");
			aTree->count--;		
		}
		else if (aNode->rightChild == NULL) 
		{
			FloatNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\nDeleted!\n");
			aTree->count--;			
		}
		else //in case there are 2 children
		{ 

			FloatNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
			printf("\nDeleted!\n");
		}			
	}
	return aNode;
}

FloatNode* FindMin(FloatNode* aNode)
{
	
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}

void destroyFloatTree(FloatTree *aTree)
{
	if (NULL != aTree)
	{
		deleteNode(aTree->root);
		free(aTree);
	}
}

void deleteNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		deleteNode(aNode->leftChild);
		deleteNode(aNode->rightChild);

		free(aNode);
	}
}

void SymmetricPrint(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		SymmetricPrint(aNode->leftChild);
		printf("%1.1f ",aNode->value);
		SymmetricPrint(aNode->rightChild);
	}
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

void BackPrint(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf("%1.1f ", aNode->value);
	}
}
