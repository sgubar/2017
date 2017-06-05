#include "dk_tool.h"

//зчитує нове число з клавіатури
int get() 
{
	int value;
	char str[10];
	
	do 
	{
		printf("Set new element: ");
		scanf("%s",str);
		value = atoi(str);
	} while (value == 0);
	return value;
}
//додає випадковий елемент до стеку
void push(Node **ptr) 
{
	if (*ptr == NULL) 
	{ //стек пустий
		*ptr = (Node*)malloc(sizeof(Node)); 
		(*ptr)->value = get(); 
		(*ptr)->link = NULL; 
	} 
	else 
	{
		Node* tmp = (Node*)malloc(sizeof(Node)); 
		tmp->value = get(); 
		tmp->link = *ptr; 
		*ptr = tmp; 
	}
}
//повертає значення ключа з вершини стеку 
int pop(Node **ptr) 
{
	if (ptr == NULL) 
		return 0;
	Node *tmp = *ptr; 
	*ptr = (*ptr)->link; 
	int value = tmp->value; 
	free(tmp); 
	return value; 
}

//рекурсивна очистка пам'яті (почергово від кінця до вершини)
void empty(Node *ptr) 
{
	if (ptr == NULL) 
		return;
	empty(ptr->link); 
	free(ptr); 
}

//рекурсивний вивід елементів стеку (почергово від вершини до кінця)
void show(Node *ptr) 
{
	if (ptr == NULL) 
	{ 
		printf("\n"); 
		return;
	}
	printf("%4i", ptr->value); 
	show(ptr->link); 
}
int find(Node *ptr) 
{
	int max = 0;
	int ret = -1;
	if (ptr != NULL) 
	{
		max = ptr->value;
		ret = 0;
	}
	for (int i = 0; ptr != NULL; i++) 
	{
		if (ptr->value > max) 
		{
			max = ptr->value;
			ret = i;
		}
		ptr = ptr->link;
	}
	return ret;
}
//обробка стеку
void replace(Node *top) 
{
	Node *ptr = top;
	if (ptr == NULL) 
		return;
	int max = find(ptr);
	for (int j = max; j > 0; j--) 
	{
		ptr = top;
		for (int i = 0; i < j; i++) 
		{
			if (ptr->value > ptr->link->value) 
			{
				int tmp = ptr->value;
				ptr->value = ptr->link->value;
				ptr->link->value = tmp;
			}
			ptr = ptr->link;
		}
	}
}