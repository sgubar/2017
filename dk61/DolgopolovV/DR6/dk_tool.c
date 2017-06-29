#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Node * create(void)
{
	Node *past, *cur, *next, *head;
	char a;
	head = cur = past = (Node*)calloc(1, sizeof(Node));
	system("cls");
	printf("Enter symbol(/ - to end): ");
	scanf("%c", &a);
	while (getchar() != '\n');
	cur->value = a;

	while (a != '/')
	{
		system("cls");
		printf("Enter symbol(/ - to end): ");
		scanf("%c", &a);
		if (a == '/')
			break;
		cur = (Node*)calloc(1, sizeof(Node));
		while (getchar() != '\n');
		cur->value = a;
		past->next = cur;
		cur->past = past;
		past = cur;
	}
	return head;
}

Node * add(Node *head)
{
	int count = 1, nam;
	char a;
	Node *past, *cur, *last, *next;
	cur = head;
	while (cur->next != 0)
	{
		cur = cur->next;
		count++;
	}
	
	system("cls");
	printf("Enter a namber sfter which you want to insert: ");
	scanf("%i", &nam);
	while (getchar() != '\n');
	if (nam == 0)
	{
		system("cls");
		printf("Enter symbol: ");
		scanf("%c", &a);
		while (getchar() != '\n');
		cur = past = (Node*)calloc(1, sizeof(Node));
		cur->value = a;
		cur->next = head;
		head->past = past;
		head = cur;
		return head;
	}
	else if (nam == count)
	{
		system("cls");
		printf("Enter symbol: ");
		scanf("%c", &a);
		while (getchar() != '\n');
		last = (Node*)calloc(1, sizeof(Node));

		while (cur->next != 0)
		{
			cur = cur->next;
			count++;
		}
		past = cur;
		last->value = a;
		cur->next = last;
		last->past = past;
		return head;
	}
	else
	{
		system("cls");
		printf("Enter symbol: ");
		scanf("%c", &a);
		while (getchar() != '\n');
		past = head;
		cur = (Node*)calloc(1, sizeof(Node));
		cur->value = a;

		for (int i = 0; i < nam-1; i++)
		{
			past = past->next;
		}
		next = past->next;

		past->next = cur;
		cur->past = past;
		cur->next = next;
		next->past = cur;
		return head;
	}
}

Node * del(Node *head)
{
	int count = 1, nam;
	char a;
	Node *past, *cur, *last, *next;
	cur = head;
	while (cur->next != 0)
	{
		cur = cur->next;
		count++;
	}

	system("cls");
	printf("Enter a namber sfter which you want to insert: ");
	scanf("%i", &nam);
	while (getchar() != '\n');

	if (nam == 1)
	{
		cur = head;
		head = head->next;
		return head;
	}
	else if (nam == count)
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->past->next = NULL;	
		return head;
	}
	else
	{
		past = head;
		for (int i = 0; i < nam - 1; i++)
		{
			past = past->next;
		}
		past->past->next = past->next;
		return head;
	}
}

void show(Node * li)
{
	system("cls");
	while (li != 0)
	{
		printf("%c ", li->value);
		li = li->next;
	}
	getch();
}

void longe(Node *li)
{
	system("cls");
	Node *cur;
	int count = 1;
	cur = li;
	while (cur->next != 0)
	{
		cur = cur->next;
		count++;
	}
	printf("%i", count);
	getch();
}

void destr(Node *li)
{
	Node *cur, *past;
	past = li;
	cur = past->next;

	while (cur != 0)
	{
		free(past);
		past = cur;
		cur = cur->next;
	}
	free(past);
}