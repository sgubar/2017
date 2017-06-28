#include "dk_tool.h"

Node* add(Node *cur, char val)
{
	Node *head = (Node*)calloc(1, sizeof(Node));
	head->value = val;
	head->next = cur;
	cur = head;
	return cur;
}

void print(Node *cur)
{
	while (cur != NULL)
	{
		printf("%c", cur->value);
		cur = cur->next;
	}
	return;
}

void del(Node *cur)
{
	Node *pre = cur;
	cur = cur->next;
	while (cur != NULL)
	{
		free(pre);
		pre = cur;
		cur = cur->next;
	}
	free(pre);
	return;
}
