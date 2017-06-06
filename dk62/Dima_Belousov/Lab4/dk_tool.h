#ifndef dk_tool
#define dk_tool

#endif

typedef struct aNode {
	float data;
	struct aNode *next;
}Node;


void createList(Node **head, Node **last);
void addToList(Node **head, Node **last);
void deleteElement(Node **head);
void printElements(Node **head, Node **last);
Node *findMinimum(Node **head, Node **last);
void sort(Node **head, Node **last, Node **min);
