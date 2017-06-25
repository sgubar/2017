#include "tree.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

int interface(FloatTree *aTree)
{	int input;
	printf("Interface of binary tree:\n");	
	printf("1 - insert value\n");
	printf("2 - delete value\n");
	printf("3 - Show count of elements\n");
	printf("4 - searching value\n");
	printf("5 - exit of interface\n");
	scanf("%d", &input);
	float value;
	switch (input)
	{	case 1:
			{
			printf("Enter value to insert: ");
			fflush(stdin);
			scanf("%f", &value);
			insertFloatValueToTree(aTree, value);
			break;
			}
		case 2:
			{
			printf("Enter value to delete: ");
			fflush(stdin);
			scanf("%f", &value);
			deleteNodeWithValue(aTree, value);
			break;
			}
		case 3:
			{
			printf("Size of tree %d\n", aTree->count);
			break;
			}
		case 4:	
		{
			printf("Enter value to searching: ");
			fflush(stdin);
			scanf("%f", &value);
			FloatNode* search = findNodeWithValue(aTree, value);
			if (search != NULL)
				printf("this value in tree\n");
			else
				printf("this value not found\n");
			break;	
		}
		case 5:
			return 0;
			
	}
	interface(aTree);
}

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

void printTree(FloatTree *aTree)
{
	if(NULL == aTree->root)
	{	
		return;
	}
	SymmetricPrintNode(aTree->root);
}

void SymmetricPrintNode(FloatNode *aNode)
{
if(NULL != aNode)

	{
		SymmetricPrintNode(aNode->leftChild);
		printf("%0.3f ",aNode->value);
		SymmetricPrintNode(aNode->rightChild);
	}

}

void deleteNodeWithValue(FloatTree *aTree, float aValue)
{
	if(NULL == aTree)
		return;

	FloatNode *theParentNode = NULL;	
	FloatNode *aNodeToDelete = aTree->root; //<! - start from root
	while (aValue != aNodeToDelete->value) //<! - walk through the tree
	{		
		theParentNode = aNodeToDelete;		
		aNodeToDelete = (aValue < aNodeToDelete->value)

					? aNodeToDelete->leftChild
					: aNodeToDelete->rightChild;

		if (NULL == aNodeToDelete)
		{	
			printf("Don't find Node\n");		
			return;
		}
	}

	if(aNodeToDelete->leftChild == NULL && aNodeToDelete->rightChild == NULL)
	{
		if(NULL != theParentNode)	
		{
			free(aNodeToDelete);	
			aTree->count--;
			printf("Deleted!\n");
			return;
		}
	}

	else if(NULL == aNodeToDelete->leftChild)
	{
			if(NULL != theParentNode)	
			{
				if(aNodeToDelete->value < theParentNode->value)
					theParentNode->leftChild = aNodeToDelete->rightChild;
				else
					theParentNode->rightChild = aNodeToDelete->rightChild;					
			}
			else					
				aTree->root = aNodeToDelete->rightChild;				
	}

	else if(NULL == aNodeToDelete->rightChild)
	{
			
		if(NULL != theParentNode)	
		{
			if(aNodeToDelete->value < theParentNode->value)
				theParentNode->leftChild = aNodeToDelete->leftChild;						
			else
				theParentNode->rightChild = aNodeToDelete->leftChild;	
			
		}
		else					
			aTree->root = aNodeToDelete->leftChild;	
	}

	else 
	{
		FloatNode *ParentOfReceiver = NULL;
		FloatNode *Receiver = aNodeToDelete->rightChild;
		if(Receiver->leftChild == NULL && Receiver->rightChild == NULL)
		{
			if(NULL != theParentNode)	
			{		
				if(aNodeToDelete->value < theParentNode->value)
					theParentNode->leftChild = Receiver;
				else
					theParentNode->rightChild = Receiver;					
				
			}
			else					
				aTree->root = Receiver;								
				Receiver->leftChild = aNodeToDelete->leftChild;
		}
		else
		{
			if(Receiver->leftChild == NULL)
			{
				if(NULL != theParentNode)					
					theParentNode->rightChild = Receiver;					
				else					
					aTree->root = Receiver;								
					Receiver->leftChild = aNodeToDelete->leftChild;	
			}

			else
			{
				while(Receiver->leftChild != NULL)
				{
				ParentOfReceiver = Receiver;
				Receiver = Receiver->leftChild;
				}
				if(Receiver->rightChild != NULL)
					ParentOfReceiver->leftChild = Receiver->rightChild;	
				else
					ParentOfReceiver->leftChild = NULL;
				if(NULL != theParentNode)					
					theParentNode->rightChild = Receiver;					
				else					
					aTree->root = Receiver;								
					Receiver->leftChild = aNodeToDelete->leftChild;		
					Receiver->rightChild = aNodeToDelete->rightChild;
			}
		}														
	}

	
	free(aNodeToDelete);	
	aTree->count--;
	printf("Deleted!\n");
}


