#ifndef list_tools_h
#define list_tools_h

#include<stdio.h>

typedef struct NodeChar
{
	char value;// letter or sumbol
	struct NodeChar *nextNode;
//	struct NodeChar *prevNode;//previous
}nodeChar;

//create a new NODE with char value
nodeChar *CreateNodeWithCharValue( char aValue);
//FREE a NODE
nodeChar FreeCharNode(nodeChar *aNode);

typedef struct NodeList
{
	struct nodeChar *head;
	struct nodeChar *tail;
	int count;	//lenght of LIST
}List;


List *CreateList();//create a nev element of LIST

void FreeList(List *aList);// free a memory, occupied by LIST

nodeChar *addNodeToTheEndOfList(List *aList, nodeChar *aNewNode);//add node to the end of list

int printTextFromFileBackToFront (List *aList,FILE *aFile_INPUT, FILE *aFile_OUTPUT);//print text from file to a console and to another file

int checkNewLineSymbol (char letter);// if letter is NEW LINE SYMBOL - return 1, if it isnt - return 0

int CountList(List *aList);//return a lenght of LIST

nodeChar *ShowNodeAtIndex(List *aList, int aIndex);//show a value of node, which stays at definite index in the LIST

void printListToFILE(FILE *aFile, List *aList);//printf a linked LIST to the console







#endif /*list_tools_h*/


