#ifndef tree
#define tree
#include <stdio.h>

typedef struct __tagNode DoubleNode;
typedef struct __tagNode
{
	double element;
	DoubleNode *leftChild;
	DoubleNode *rightChild;
} DoubleNode;
typedef struct __tagDrevo
{
	DoubleNode *root;
	int count;
} DoubleDrevo;
DoubleDrevo *createDoubleDrevo();
void destroyDoubleDrevo(DoubleDrevo *aDrevo);
void insertdoubleElementToDrevo(DoubleDrevo *aDrevo, double aElement);
DoubleNode* FindMin(DoubleNode *aNode);
DoubleNode* findNodeWithElement(DoubleDrevo *aDrevo, double aElement);
DoubleNode *deleteNodeWithElement(DoubleDrevo *aDrevo, DoubleNode* aNode, double aElement);
void printDrevo(DoubleDrevo*aDrevo,int count);
void BackPrint(DoubleNode *aNode);
int countNodesWithDrevo(DoubleDrevo *aDrevo);
#endif
