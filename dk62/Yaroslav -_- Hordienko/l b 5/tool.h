#ifndef _tool
#define _tool



typedef struct aNode {
	float data;
	struct aNode *next;
}Node;


void CreateList(Node **head, Node **last);
void AddElementToList(Node **head, Node **last);
void DeleteElement(Node **head);
void PrintElements(Node **head, Node **last);
Node *FindMinimum(Node **head, Node **last);
void Sort(Node **head, Node **last, Node **min);



#endif
