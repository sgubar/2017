#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "list.h"
#include "node.h"



Node *createNodeWithValue(char aValue)
{
	Node *theResult = (Node *)malloc(sizeof(Node));

	theResult->symbol = NULL;
	theResult->next = NULL;
	theResult->counter = 0;

	return theResult;
}



void CountEntryPoints(List*aList)
{
	char text[1000];
	printf("Type some text :\n");
	gets(text);
	Node*theNode = aList->begin;
	for (int i = 0; i < strlen(text); i++) 
	{
		while (text[i] == ' ')//check if text has spaces
			i++;
		if (aList->count == 0)
		{
			CreateNodeAndAddtoList(aList, text[i], theNode);
		}
		else {
			IncrementOrCreateNodeByValue(aList, text[i], strlen(text));
		}
	
	}

	
}


void CreateNodeAndAddtoList(List*aList, char text, Node*theNode) 
{
	theNode = createNodeWithValue(text);
	theNode->symbol = text;
	theNode->counter++;
	AddNodeToList(aList, theNode);
	theNode = theNode->next;

}


void IncrementOrCreateNodeByValue(List *aList, char aValue,int size)
{

	
	if (aList == NULL || aList->count == 0)
	{
		return;
	}
	Node*aNode = aList->begin;// get the start node
	int counter = 0;

	if (aList->count == 1) //check if we have more than one node
	{
		if (aNode->symbol == aValue) {
			aNode->counter++;// increment the node parameter
			return ;
		}
		else {
			CreateNodeAndAddtoList(aList, aValue, aNode);
			return ;
		}
	}


	while (counter<size) // looking for node that already exists
	{
		if (aNode == NULL) // if didn't find - create
		{
			CreateNodeAndAddtoList(aList, aValue, aNode);
			return;
		}
		if (aNode->symbol == aValue)
		{
			aNode->counter++;
			return ;
		}
		
			
		aNode = aNode->next;
		counter++;
	}
	

}

