#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#pragma warning (disable: 4996)


void AddNode(Tree **myTree, int value)
{
	Tree *temp = NULL;
	if (!(*myTree))
	{
		temp = (Tree *)malloc(sizeof(Tree));
		temp->left = temp->right = NULL;
		temp->data = value;
		*myTree = temp;
		return;
	}


	if (value < (*myTree)->data)
	{
		AddNode(&(*myTree)->left, value);
	}
	else if (value >(*myTree)->data)
	{
		AddNode(&(*myTree)->right, value);
	}
}

void PrintElements(Tree *myNode)
{
	if (myNode) {
		printf("%d ", myNode->data);
		PrintElements(myNode->left);
		PrintElements(myNode->right);
	}

}

void DeleteElements(Tree *myTree) {

	if (myTree) {
		DeleteElements(myTree->left);
		DeleteElements(myTree->right);
		free(myTree);
		printf("Element deleted\n");
	}
}

Tree *Search(Tree **myTree, int value) {

	if (!(*myTree)) {
		return NULL;
	}

	if (value == (*myTree)->data) {
		return *myTree;
	}
	else if (value < (*myTree)->data) {
		Search(&((*myTree)->left), value);
	}
	else if (value >(*myTree)->data) {
		Search(&((*myTree)->right), value);
	}
}

