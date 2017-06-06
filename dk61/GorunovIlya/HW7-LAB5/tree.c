#include "tree.h"
#include <stdlib.h>

static void destroyNode(FloatNode *aNode);
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

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{
	FloatNode *theCurrentNode = NULL;
	
	if (NULL != aTree)
	{
		FloatNode *theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				//printf("Node is not Found!");
				break;
			}
		}
	}
	
	
	return theCurrentNode;
}

void deleteNodeWithValue(FloatTree *aTree, float aValue)
{
	if (aTree == NULL)
    {
    	printf("Error with Tree!");
		return -1;
	}
	
//	else if(aNode == NULL)
//	{
//		printf("Error with Node!");
//		return -2;
//	}
	
	FloatNode *theParentNode = NULL;
	FloatNode *aNodeToDelete = aTree->root;
	
	while (aValue != aNodeToDelete->value)
	{		
		theParentNode = aNodeToDelete;		
		aNodeToDelete = (aValue < aNodeToDelete->value)

					? aNodeToDelete->leftChild
					: aNodeToDelete->rightChild;

		if (NULL == aNodeToDelete)
		{	
			printf("Node is not found!");
			//break;		
			return;
		}
	}

	if(aNodeToDelete->leftChild == NULL && aNodeToDelete->rightChild == NULL)
	{
		if(NULL != theParentNode)	
		{
			if(aNodeToDelete->value < theParentNode->value)
			{			
				theParentNode->leftChild = NULL;
			}
			if(aNodeToDelete->value > theParentNode->value)
			{
				theParentNode->rightChild = NULL;
			}	
		}
	}

	else if(NULL == aNodeToDelete->leftChild)
	{
			if(NULL != theParentNode)	
			{
				if(aNodeToDelete->value < theParentNode->value)
				{
				    theParentNode->leftChild = aNodeToDelete->rightChild;
			    }
				else
				{
				    theParentNode->rightChild = aNodeToDelete->rightChild;		
			    }
			}
			else
			{				
				aTree->root = aNodeToDelete->rightChild;	
			}
	}

	else if(NULL == aNodeToDelete->rightChild)
	{
			
		if(NULL != theParentNode)	
		{
			if(aNodeToDelete->value < theParentNode->value)
			{
				theParentNode->leftChild = aNodeToDelete->leftChild;		
			}
			else
			{
				theParentNode->rightChild = aNodeToDelete->leftChild;
		    }
			
		}
		else
		{					
			aTree->root = aNodeToDelete->leftChild;	
		}
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
				{
					theParentNode->leftChild = Receiver;
				}
				else
				{
					theParentNode->rightChild = Receiver;
			    }
				
			}
			else
			{			
				aTree->root = Receiver;								
				Receiver->leftChild = aNodeToDelete->leftChild;
			}
		}
		else
		{
			if(Receiver->leftChild == NULL)
			{
				if(NULL != theParentNode)
				{				
					theParentNode->rightChild = Receiver;
				}
				else
				{					
					aTree->root = Receiver;								
					Receiver->leftChild = aNodeToDelete->leftChild;
				}
			}

			else
			{
				while(Receiver->leftChild != NULL)
				{
				    ParentOfReceiver = Receiver;
				    Receiver = Receiver->leftChild;
				}
				if(Receiver->rightChild != NULL)
				{
					ParentOfReceiver->leftChild = Receiver->rightChild;	
				}
				else
				{
				
					ParentOfReceiver->leftChild = NULL;
				}
				if(NULL != theParentNode)
				{				
					theParentNode->rightChild = Receiver;
				}
				else					
					aTree->root = Receiver;								
					Receiver->leftChild = aNodeToDelete->leftChild;		
					Receiver->rightChild = aNodeToDelete->rightChild;
			}
		}														
	}

	
	free(aNodeToDelete);	
	aTree->count--;
}

	


void ReversePrintTree(FloatTree *aTree)
{
	if(aTree != NULL)
	{
		ReversePrintNode(aTree->root);
	}
}
	
	


void ReversePrintNode(FloatNode *aNode)
{
	if(NULL != aNode)
	{
		ReversePrintNode(aNode->leftChild);
		ReversePrintNode(aNode->rightChild);
		printf("%.3f\n",aNode->value);
	}
}


//#pragma mark -
void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
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
