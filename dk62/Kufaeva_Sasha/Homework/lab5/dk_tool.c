#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Tree *createTree()
{
	Tree *aTree = (Tree *) malloc(sizeof(Tree));
	
	if(aTree != NULL)
	{
		aTree->count = 0;
		aTree->root = NULL;
	}
	return aTree;
}

void destroyTree(Tree *aTree)
{
	if(aTree != NULL)
	{
		if(aTree->root != NULL)
		{
			destroyCore(aTree->root);
		}
		
		free(aTree);
	}
}

Core *createCore(char val)
{
	Core *aCore = (Core *) malloc(sizeof(Core));
	
	if(aCore != NULL)
	{
		aCore->left = NULL;
		aCore->right = NULL;
		aCore->value = val;
	}
	return aCore;
}

void destroyCore(Core *aCore)
{
	if(aCore)
	{
		destroyCore(aCore->left);
		destroyCore(aCore->right);
		free(aCore);
	}
}

void fillElements(Tree *aTree)
{
	srand(time(NULL));
		insertElement(aTree, 'm');
	
	for(int i = 0; i < 30; i++)
		insertElement(aTree, (97 + (rand() % 26)));
}

int insertElement(Tree *aTree, char val)
{
	if(aTree != NULL)
	{
		if(aTree->root == NULL)
		{
			Core *aCore = createCore(val);
			
			if(aCore != NULL)
			{
				aTree->root = aCore;
				aTree->count++;
			}
			else
			{
				printf("Element hasn't created");
				return 1;
			}
		}
		
		else
		{
			Core *fast = aTree->root;
			Core *low = NULL;
			
			while(1)
			{
				low = fast;
				
				if(val == fast->value)
				{
					return 1;
				}
				
				else if(val < fast->value)
				{
					fast = fast->left;
					if(fast == NULL)
					{
						Core *aCore = createCore(val);
						low->left = aCore;
						aTree->count++;
						break;
					}
				}
				
				else
				{
					fast = fast->right;
					if(fast == NULL)
					{
						Core *aCore = createCore(val);
						low->right = aCore;
						aTree->count++;
						break;
					}
				}
			}
		}
		return 0;
	}
	return 1;
}

void deleteValueElement(Tree *aTree, char val)
{
	if(aTree != NULL && aTree->root != NULL)
	{
		Core *toDelete = search(aTree->root, val);
		
		if(toDelete != NULL)
			deleteElement(aTree, toDelete);
		
		else
		{
			printf("Error!\n");
			return;
		}
	}
	
	else
	{
		printf("Error!\n");
		return;
	}
}

void deleteElement(Tree *aTree, Core *aCore)
{
	if(aCore->left != NULL && aCore->right != NULL)
	{
		Core *min = minVal(aCore->right);
		char tmp = min->value;
		deleteElement(aTree, min);
		aCore->value = tmp;
		return;
	}
	
	else if(aCore->left != NULL)
	{
		Core *parent = findParent(aTree, aCore->value);
		
		if(aCore == parent->left)
			parent->left = aCore->left;
		else
			parent->right = aCore->left;
	}
	
	else if(aCore->right != NULL)
	{
		Core *parent = findParent(aTree, aCore->value);
		
		if(aCore == parent->right)
			parent->right = aCore->right;
		else
			parent->left = aCore->right;
	}
	
	else
	{
		Core *parent = findParent(aTree, aCore->value);
		
		if(aCore == parent->left)
			parent->left = NULL;
		else
			parent->right = NULL;
		
		if(aCore == aTree->root)
			aTree->root = NULL;
	}
	free(aCore);
	aTree->count--;
}

Core *findParent(Tree *aTree, char val)
{
	Core *aParent = NULL;
	Core *toDelete = aTree->root;
	
    while(toDelete->value != val)
    {
    	aParent = toDelete;
    	if(toDelete->value > val)
    		toDelete = toDelete->left;
    	else
			toDelete = toDelete->right;
	}
	return aParent;
}


Core *minVal(Core *aCore)
{
	Core *temp = aCore;
	
	while(temp->left != NULL)
		temp = temp->left;
	
	return temp;
}

Core *search(Core *aCore, char val)
{
	if(aCore != NULL)
	{
		if(val < aCore->value)
			return search(aCore->left, val);
		
		else if(val > aCore->value)
			return search(aCore->right, val);
		
		else
			return aCore;
	}
	
	return NULL;
}

void printTree(Core *aCore)
{
	if(aCore != NULL)
	{
		printTree(aCore->left);
		printf("%c ", aCore->value);
		printTree(aCore->right);
	}
}

void print(Tree *aTree)
{
	printf("\nAmount: %i\n", aTree->count);
	
	if(aTree->root != NULL)
	{
		printf("Binary tree:\n");
		printTree(aTree->root);
		printf("\n\n");
	}
}

void deleteRootElement(Tree *aTree)
{
	printf("Deleting root element: %c", aTree->root->value);
	deleteValueElement(aTree, aTree->root->value);
	printf("\nNew value: %c\n", aTree->root->value);
}

void createNotSameElement(Tree *aTree)
{
	int k;
	char toAdd;
	
	do{
		toAdd = 97 + (rand() % 26);
		k = insertElement(aTree, toAdd);
	}while(k != 0);
	
	printf("Adding element '%c'\n", toAdd);
}

void searchRandomChar(Tree *aTree)
{
	char toSearch = 97 + (rand() % 26);
	printf("Searching random char '%c'\n", toSearch);
	
	Core *result = search(aTree->root, toSearch);
	
	if(result != NULL)
		printf("Is present\n");
	else
		printf("Not present\n");
}
