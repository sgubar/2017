#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

// Predeclaration
typedef struct __Node slNode;

typedef struct __List
{
	slNode *head;
	slNode *tail;
	int nodeCounter;
}slList;

slList *SLCreateList();
void freeList(slList *aList);
int SLCountList(const slList *aList);					//counting the number of nodes in the list

slNode *SLAddNode(slList *aList, char aValue);			//adding the node with some value-letter, if we already haven't got the node with this letter 

slNode *SLNodeAtIndex(const slList *aList, int aIndex);		//access to the node with some index in the list

slNode *findNodeWithLetter(slList *aList, char aValue);		//searching the nodes with some letter in our list
void entryCounterFunction(slList *aList);			//iteration of the counter of the number of entries of our letter in the text if we find the same letters
void finalPrinting(const slList *aList);		//finally prints our letters and the number of occurrences in the text of each of them

#endif
