#include "tree.h"
#include "Node.h"
#include <stdlib.h>

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

void destroyNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}


CharNode *findNodeWithValue(CharTree *aTree, char aValue)
{

	CharNode *theCurrentNode = NULL;
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{				
			theCurrentNode = (aValue < theCurrentNode->value)

						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{			
				break;
			}
		}
	}
	return theCurrentNode;
}

