#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"


void AddNode(Tree **tagTree, double val) //
{
	Tree *now = NULL;
	if (!(*tagTree)) // esli dereve netu
	{
		now = (Tree *)malloc(sizeof(Tree));
		now->left = now->right = NULL;
		now->data = val; 
		*tagTree = now; // uzel
		return;
	}


	if (val < (*tagTree)->data) //rekursiya
	{
		AddNode(&(*tagTree)->left, val); //
	}
	else if (val >(*tagTree)->data)
	{
		AddNode(&(*tagTree)->right, val);
	}
}

void TreePrint(Tree *tagNode)
{
	if (tagNode) {
			
		TreePrint(tagNode->left); //rekursivij vizov funkcii
		TreePrint(tagNode->right);// sncachala levo potom pravo
		printf("%d ", tagNode->data); // posicia printf daet nam ponyat kakoi obhod mi delaem, v danniy moment "ZVOROTNIJ"
	}

}

Tree *Search(Tree **tagTree, double val) {

	if (!(*tagTree)) {
		return NULL;
	}

	if (val == (*tagTree)->data) {
		return *tagTree;
	}
	else if (val < (*tagTree)->data) {
		Search(&((*tagTree)->left), val);
	}
	else if (val >(*tagTree)->data) {
		Search(&((*tagTree)->right), val);
	}
}


void DestroyTree(Tree *tagTree) {

	if (tagTree) {
		DestroyTree(tagTree->left);
		DestroyTree(tagTree->right);
		free(tagTree);
		
	}
	//printf("Element destr\n");
}
