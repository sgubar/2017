#include "dk_tool.h"

static void destroyNode(FloatNode *aNode);
static FloatNode *createFloatNodeWithValue(float aValue);
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void destroyFloatTree(FloatTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void InsertFloatValueToTree(FloatTree *aTree, float aValue)
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void printTree(FloatTree *aTree)
{
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
	
	printf("\nThe root: (%.2f)\n", aTree->root->value);
	
	if (NULL != aTree) 
	{
		BackPrint(aTree->root);
    }
	
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
}

//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void BackPrint(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf(" (%.2f) \t", aNode->value);

	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 

FloatNode* FindMin(FloatNode* aNode)
{	
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 

FloatNode* deleteNodeWithValue(FloatTree *aTree,FloatNode* aNode, int aValue)
{
	
	if (aNode == NULL)
	{
		printf("!Node is not found!\n");
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
			FloatNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\nChoosen Node is Deleted!\n\n");
			aTree->count--;	
		}
		
		else if (aNode->rightChild == NULL) 
		{
			FloatNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\nChoosen Node is Deleted!\n\n");
			aTree->count--;	
		}
	
		else
		{ 
			FloatNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
		//	printf("\nChoosen Node is Deleted!\n");
		}	
	}	
	return aNode;
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
int countNodesWithTree(FloatTree *aTree)
{
	if (NULL != aTree)
		return aTree->count;
	return 0;
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
