#ifndef link_h
#define link_h

typedef struct aNode
{
    int value;
    struct aNode *next;
}Node;

Node *createList(int aSize);
void createElement(Node *head, int val);

float findAverage(Node *head);
int findTrash(Node *head, float pivot);
int valueElement(Node *head, int num);

int deleteElement(Node **head, int value);
void deleteList(Node **head);

void printLinkedList(Node *head);

#endif
