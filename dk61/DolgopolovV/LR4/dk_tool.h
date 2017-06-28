

#ifndef dk_tool
#define dk_tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aNode
{
	char value;
	struct aNode *next;
}Node;

Node* add(Node *theNode, char val);
void del(Node *theNode);
void print(Node *theNode);

#endif
