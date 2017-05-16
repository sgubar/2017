#ifndef node
#define node


#include <stdio.h>
#include"list.h"


typedef struct __floatNode Node;


struct __floatNode
{
	float value;
	Node *next;
	Node *prev;
};


 Node *createNodeWithfloatValue(float aValue);
void FreefloatNode(Node *aNode);



#endif /*node*/