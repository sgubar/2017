#include "tree.h"
#include <stdlib.h>

static void destroyNode(intNode *aNode);
static intNode *createIntNodeWithValue(int aValue);

intTree *createIntTree()
{
	intTree *theTree = (intTree *)malloc(sizeof(intTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->size = 0;
	}
	
	return theTree;
}

void destroyIntTree(intTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertIntValueToTree(intTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	intNode *theNode = createIntNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->size ++;
	}
	else
	{
		intNode *theCurrent = aTree->root;
		intNode *theParent = NULL;

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
	
		aTree->size ++;
	}
}

intNode *findNodeWithValue(intTree *aTree, int aValue)
{
	intNode *theCurrentNode = NULL;
	
	int i = 0;
	if (NULL != aTree)
	{
		intNode *theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				i = 1;
				break;
			}
		}
	}
	
	if(i == 1)
	{
		printf("\naNode with %i value ISN'T in aTree\n", aValue);
	}
	else
	{
		printf("\naNode with %i value realy is in aTree\n", aValue);

	}
	
	return theCurrentNode;
}



int countNodesWithTree(intTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->size;		
	}
	return size;
}


static intNode *createIntNodeWithValue(int aValue)
{
		intNode *theNode = (intNode *)malloc(sizeof(intNode));

if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

static void destroyNode(intNode *aNode)
{
	if (aNode != NULL)
	{
		free (aNode);
	}
}

void printTreeToConsole(intTree *aTree)
{
	
     printf("\n");
		printNodeToConsole(aTree->root);  
  
	
}

void printNodeToConsole(intNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%i ",aNode->value);
		printNodeToConsole(aNode->leftChild);
		printNodeToConsole(aNode->rightChild);
	}
}

int fillingAnTree(intTree *aTree)
	{
	insertIntValueToTree(aTree, 1);
	insertIntValueToTree(aTree, 2);
	insertIntValueToTree(aTree, 3);
	insertIntValueToTree(aTree, 7);
	insertIntValueToTree(aTree, 14);
	insertIntValueToTree(aTree, 15);
	insertIntValueToTree(aTree, 19);
	insertIntValueToTree(aTree, 21);
	insertIntValueToTree(aTree, 23);
	insertIntValueToTree(aTree, 25);
	insertIntValueToTree(aTree, 27);
	insertIntValueToTree(aTree, 29);
	insertIntValueToTree(aTree, 34);
	insertIntValueToTree(aTree, 38);
	insertIntValueToTree(aTree, 45);
	insertIntValueToTree(aTree, 63);
	insertIntValueToTree(aTree, 97);
	
	int size = countNodesWithTree(aTree);
	return size;
	}
	


	void doTestTree()
{
	intTree *aTree = createIntTree();
	
	int size = fillingAnTree(aTree);// number of members of TREE
	printf("number of elements = %i\n", size);
	
	printTreeToConsole(aTree);
	
	printf("\ndo search testing. give me aKey for searching [0, 100] = ");
	int key = scan(0,100);
	intNode *findTestNode = findNodeWithValue(aTree, key);
	
	printf("\ngive me the value to delete [0;100] = ");
	int valueToDelete = scan(0,100);
	deleteNodeWithValue(aTree,aTree->root, valueToDelete);	

}

	int scan(int min, int max)// just scanf with checking on idiot
{
	
	int buffer;// variable for saving that what we scanned
	int q;// variable for checking on idiot
	do
	{
	q = scanf("%i", &buffer);
	
	fflush(stdin);// without this it willn't work correctly
	
	if((buffer<min || buffer>max) || q!=1)
	{
		printf("\ngive me the correct number pls!");	
	}		
	
	}
	
	while ((buffer<min || buffer>max) || q!=1);
	
	return buffer;	

}

intNode* deleteNodeWithValue(intTree *aTree,intNode* aNode, int aValue)
{
	
	if (aNode == NULL) 
	{
		printf("This node ISNT in aTree.\n");
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
			aTree->size--;
			printf("\n\nNode successfully deleted!\n");
		}

		else if (aNode->leftChild == NULL) 
		{
			intNode *theTmp = aNode;
			aNode = aNode->rightChild;
			free(theTmp);
			printf("\n\nNode successfully deleted!\n");
			aTree->size--;
			
		}
		
		else if (aNode->rightChild == NULL) 
		{
			intNode *theTmp = aNode;
			aNode = aNode->leftChild;
			free(theTmp);
			printf("\n\nNode successfully deleted!\n");
			aTree->size--;
			
		}
	
		else 
		{ 

			intNode *theTmp = FindMin(aNode->rightChild);
			aNode->value = theTmp->value;
			aNode->rightChild = deleteNodeWithValue(aTree, aNode->rightChild,theTmp->value);
			aTree->size--;
			printf("\n\nNode successfully deleted!\n");
		}	
	}
	return aNode;
}

intNode *FindMin(intNode* aNode)
{
	
	while (aNode->leftChild != NULL) 
	aNode = aNode->leftChild;
	return aNode;
}

