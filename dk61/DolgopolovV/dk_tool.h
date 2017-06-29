#ifndef dk_tool
#define dk_tool

typedef struct aNode
{
	char value;
	struct aNode *next;
	struct aNode *past;
}Node;

Node * create(void);
Node * add(Node *head);
Node * del(Node *head);
void show(Node * li);
void destr(Node *li);
void longe(Node *li);

#endif