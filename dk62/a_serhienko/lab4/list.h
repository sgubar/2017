#ifndef list
#define list 

#include <stdio.h>


typedef struct __List List;
typedef struct __Node Node;

struct __List
{
	Node *begin;
	Node *end;
	int count;
};

int CountList(const List *aList);
Node *AddNodeToList(List *aList, Node *aNewNode);
void printListNodebyNode(List*aList);

List*CreateList();
void FreeList(List *aList);


#endif