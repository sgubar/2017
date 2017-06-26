#include "dk_tool.h"

static void destroyNode(CharNode *aNode);
static CharNode *createCharNodeWithValue(char aValue);
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void destroyCharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void InsertCharValueToTree(CharTree *aTree, char aValue)
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void destroyNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
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
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void printTree(CharTree *aTree)
{
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
	
	printf("\nThe root: (%c)\n", aTree->root->value);
	
	if (NULL != aTree) 
	{
		BackPrint(aTree->root);
    }
	
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
}

//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
void BackPrint(CharNode *aNode)
{
	if (NULL != aNode)
	{
		BackPrint(aNode->leftChild);
		BackPrint(aNode->rightChild);
		printf(" (%c) \t", aNode->value);
	}
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 

CharNode* FindMin(CharNode* aNode)
{	
	while (aNode->leftChild != NULL) aNode = aNode->leftChild;
	return aNode;
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 

CharNode* deleteNodeWithValue(CharTree *aTree,CharNode* aNode, char aValue)
{
	
	if (aNode == NULL)
	{
		printf(" !Node is not found!\n");
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
			printf("\nDone. Note is deleted.\n\n");
		}

		else if (aNode->leftChild == NULL)
		{
			CharNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\nDone. Note is deleted.\n\n");
			aTree->count--;	
		}
		
		else if (aNode->rightChild == NULL) 
		{
			CharNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\nDone. Note is deleted.\n\n");
			aTree->count--;	
		}
	
		else
		{ 
			CharNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->count--;
		//	printf("\nChoosen Node is Deleted!\n");
		}	
	}	
	return aNode;
}
//   -     -   -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     -    -     - // 
int countNodesWithTree(CharTree *aTree)
{
	if (NULL != aTree)
		return aTree->count;
	return 0;
}
