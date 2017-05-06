#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    char value;
    struct aNode *next;
}Node;

void crFirst_push(Node **head, char val);	//create element on first position
void delList(Node **head);					//delete all elements in list
void printList(Node *head);					//print elements in list

#endif
