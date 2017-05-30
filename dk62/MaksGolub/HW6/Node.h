#ifndef Node_h

#define Node_h

typedef struct __DoubleNode DoubleNode;

// The node declaration
struct __DoubleNode

{
	double value;
	DoubleNode *next;//<! - the reference to next node
	DoubleNode *prev;//<! - the reference to prev node
};

DoubleNode *CreateNodeWithValue(double aValue);
void FreeNode(DoubleNode *aNode);

#endif 
