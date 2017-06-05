#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#pragma warning (disable: 4996)

int main(void)
{

	Tree *myTree = NULL;
	Tree *tmp;
	int value, command;

	for (int i = 0; i < 7; i++)
	{
		printf("Enter value: ");
		scanf("%i", &value);
		AddNode(&myTree, value);
	}

	printf("Elements: ");
	PrintElements(myTree);
	printf("\n");

	do
	{
		printf("Enter command: ");
		scanf("%d", &command);
		switch (command)
		{
		case 1:
			printf("Enter value: ");
			scanf("%i", &value);
			AddNode(&myTree, value);
			break;

		case 2:
			printf("Elements: ");
			PrintElements(myTree);
			printf("\n");
			break;
		
		case 3:
			printf("Head: %i\n", myTree->data);
			printf("Enter value that you want to find: ");
			break;

		default:
			printf("No such command\n");
			break;
		}
	} while (command != 3);
	
	
	scanf("%i", &value);
	tmp = Search(&myTree, value);
	if (tmp)
	{
		printf("Searched node = %d\n", tmp->data);
	}
	else
	{
		printf("Element was not found in you tree.\n");
	}

	DeleteElements(myTree);

	system("pause");
	return 1;
}
