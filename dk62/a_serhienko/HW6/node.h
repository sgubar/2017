#ifndef node
#define node

#include <stdio.h>


typedef struct __floatNode Node;


struct __floatNode
{
	float value;
	Node *next;
};


Node *createNodeWithfloatValue(float aValue);

void FreefloatNode(Node *aNode);



#endif /*node*/