#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

static void destroyNode(DoubleNode *aNode);
static DoubleNode *createDoubleNodeWithElement(double aElement);
DoubleDrevo *createDoubleDrevo()
{
	DoubleDrevo *theDrevo = (DoubleDrevo *)malloc(sizeof(DoubleDrevo));
	if (NULL != theDrevo)
	{
		theDrevo->root = NULL;
		theDrevo->count = 0;
	}
	return theDrevo;
}

void destroyDoubleDrevo(DoubleDrevo *aDrevo)
{
	if (NULL != aDrevo)
	{
		destroyNode(aDrevo->root);
		free(aDrevo);
	}
}

void insertdoubleElementToDrevo(DoubleDrevo *aDrevo, double aElement)
{
	if (NULL == aDrevo)
	{
		return;
	}
	DoubleNode *theNode = createDoubleNodeWithElement(aElement);
	if (NULL == theNode)
	{
		return;
	}
	if (NULL == aDrevo->root)
	{
		aDrevo->root = theNode;
		aDrevo->count++;
	}
	else
	{
		DoubleNode *theCurrent = aDrevo->root;
		DoubleNode *theParent = NULL;
		while (1)
		{
			theParent = theCurrent;
			if (aElement < theCurrent->element)
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
		aDrevo->count++;
	}
}

DoubleNode* findNodeWithElement(DoubleDrevo *aDrevo, double aElement)
{
	DoubleNode *theCurrentNode = NULL;
	if (NULL != aDrevo)
	{
		DoubleNode *theCurrentNode = aDrevo->root; ///< - start from root
		while (aElement != theCurrentNode->element) ///< - walk through the tree
		{
			theCurrentNode = (aElement < theCurrentNode->element)
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

void destroyNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}

DoubleNode *createDoubleNodeWithElement(double aElement)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->element = aElement;
	}
	return theNode;
}

void printDrevo(DoubleDrevo *aDrevo,int count)//printing by back metod of printing
{
	printf("Kolishestvo elementov v dreve :%d\n", count);
	printf("Elemeni v dreve: ");
	if (NULL != aDrevo) 
	{
		BackPrint(aDrevo->root);
    }
    printf("\n");
}

void BackPrint(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf(" %f ", aNode->element);
	}

}
DoubleNode* FindMin(DoubleNode* aNode)
{
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}

DoubleNode* deleteNodeWithElement(DoubleDrevo *aDrevo,DoubleNode* aNode, double aElement)
{
	if (aNode == NULL) {
		printf("that node is not found\n");
		return NULL;
	}
	else if (aElement < aNode->element)
	aNode->leftChild = deleteNodeWithElement(aDrevo,aNode->leftChild, aElement);
	else if (aElement > aNode->element)
	aNode->rightChild = deleteNodeWithElement(aDrevo , aNode->rightChild, aElement);
	else 
	{
		if (aNode->leftChild == NULL && aNode->rightChild == NULL) //in case there are no child
		{
			free(aNode);
			aNode = NULL;
			aDrevo->count--;
			printf("Element %f udalen!\n",aElement);
		}
		else if (aNode->leftChild == NULL)//in case there is one child
		{
			DoubleNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("Element %f udalen!\n",aElement);
			aDrevo->count--;
		}
		else if (aNode->rightChild == NULL) 
		{
			DoubleNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("Element %f udalen!\n",aElement);
			aDrevo->count--;
		}
		else //in case there are 2 children
		{ 
			DoubleNode *theTmp = FindMin(aNode->rightChild);
			aNode->element = theTmp->element;
			aNode->rightChild = deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->element);
			aDrevo->count--;
			printf("Element %f udalen!\n",aElement);
		}
	}
	return aNode;
}
int countNodesWithDrevo(DoubleDrevo *aDrevo)
{
	if (NULL != aDrevo)
		return aDrevo->count;
	return 0;
}
