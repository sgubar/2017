#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"



void AddNode(Tree **myTree, float value)
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
		PrintElements(myNode->left);
        cout << root->data << " ";
		printf("%f", myNode->data);
		PrintElements(myNode->right);
	}

}

void DeleteElements(Tree *myTree) {

	if (myTree) {
		DeleteElements(myTree->left);
		DeleteElements(myTree->right);
		free(myTree);
	}
}

Tree *Search(Tree **myTree, float value) {

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
