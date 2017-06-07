#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

static void destroyNode(IntNode *aNode);
static IntNode *createIntNodeWithValue(int aValue);

void Tree()
{
		IntTree *Tree = createIntTree();


	InsertIntValueToTree(Tree, 12);
	InsertIntValueToTree(Tree, 16);
	InsertIntValueToTree(Tree, 11);
	InsertIntValueToTree(Tree, 7);
	InsertIntValueToTree(Tree, 22);
	InsertIntValueToTree(Tree, 42);
	InsertIntValueToTree(Tree, 9);
	InsertIntValueToTree(Tree, 6);

	int count = countNodesWithTree(Tree);
	printf("the count of nodes in tree is : [%d]\n", count);
	

	IntNode* search = findNodeWithValue(Tree, 7);

	if (search != NULL)
		printf("Choosen node is in tree\n");
	else
		printf("Choosen node isn't found\n");


	printTree(Tree);

	IntNode *aNode = Tree->root;
	deleteNodeWithValue(Tree,aNode, 7);
deleteNodeWithValue(Tree,aNode, 6);

	count = 0;
	count = countNodesWithTree(Tree);
	printf("the count of nodes in modified tree is : [%d]\n", count+1);
	
	printTree(Tree);

	destroyIntTree(Tree);

	printf("\nThe Tree has been deleted!\n");
}

IntTree *createIntTree()
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyIntTree(IntTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void InsertIntValueToTree(IntTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	IntNode *theNode = createIntNodeWithValue(aValue);
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
		IntNode *theCurrent = aTree->root;
		IntNode *theParent = NULL;

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

IntNode* findNodeWithValue(IntTree *aTree, int aValue)
{
	IntNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
		IntNode *theCurrentNode = aTree->root; 
		while (aValue != theCurrentNode->value) 
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

void destroyNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

IntNode *createIntNodeWithValue(int aValue)
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void printTree(IntTree *aTree)
{
printf("The root: (%d)\n",aTree->root->value);
	if (NULL != aTree) 
	{
		BackPrint(aTree->root);
    }

}

void BackPrint(IntNode *aNode)
{

	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf(" (%d) \t", aNode->value);

	}

}
IntNode* FindMin(IntNode* aNode)
{
	
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}

IntNode* deleteNodeWithValue(IntTree *aTree,IntNode* aNode, int aValue)
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

		if (aNode->leftChild == NULL && aNode->rightChild == NULL) 
		{
			free(aNode);
			aNode = NULL;
			aTree->count--;
			printf("\n Choosen Node is Deleted!\n\n");
		}

		else if (aNode->leftChild == NULL)
		{
			IntNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\nChoosen Node is Deleted!\n\n");
			aTree->count--;
			
		}
		else if (aNode->rightChild == NULL) 
		{
			IntNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\nChoosen Node is Deleted!\n\n");
			aTree->count--;
			
		}
	
		else
		{ 

			IntNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
		//	printf("\nChoosen Node is Deleted!\n");
		}
		
		
	}
	
	
	return aNode;

}

int countNodesWithTree(IntTree *aTree)
{
	if (NULL != aTree)
		return aTree->count;
	return 0;
}



