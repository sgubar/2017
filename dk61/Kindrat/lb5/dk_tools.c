#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"



void AddNode(Tree **thisTree, int chislo)
{
	Tree *temp = NULL;
	if (!(*thisTree))
	{
		temp = (Tree *)malloc(sizeof(Tree));
		temp->leftson = temp->rightson = NULL;
		temp->data = chislo;
		*thisTree = temp;
		return;
	}


	if (chislo < (*thisTree)->data)
	{
		AddNode(&(*thisTree)->leftson, chislo);
	}
	else if (chislo >(*thisTree)->data)
	{
		AddNode(&(*thisTree)->rightson, chislo);
	}
}

void PrintTree(Tree *thisNode)
{
	if (thisNode) {
		PrintTree(thisNode->leftson);
		PrintTree(thisNode->rightson);
		printf("%d ", thisNode->data);
	}

}

void DeleteElements(Tree *thisTree) {

	if (thisTree) {
		DeleteElements(thisTree->leftson);
		DeleteElements(thisTree->rightson);
		free(thisTree);
		printf("Element deleted\n");
	}
}

Tree *Search(Tree **thisTree, int chislo) {

	if (!(*thisTree)) {
		return NULL;
	}

	if (chislo == (*thisTree)->data) {
		return *thisTree;
	}
	else if (chislo < (*thisTree)->data) {
		Search(&((*thisTree)->leftson), chislo);
	}
	else if (chislo >(*thisTree)->data) {
		Search(&((*thisTree)->rightson), chislo);
	}
}
