#include "tree.h"
#include "Node.h"
#include <stdlib.h>

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

void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}


FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{

	FloatNode *theCurrentNode = NULL;
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
