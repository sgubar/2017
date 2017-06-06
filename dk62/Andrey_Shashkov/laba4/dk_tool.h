#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    char value;
    struct aNode *next;
}Node;

void gstring(char *min);
void crFirst_push(Node **head, char val);	
void delList(Node **head);				
void printList(Node *head);					

#endif
