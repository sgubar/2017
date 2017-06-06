#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"


int main(void)
{
	Tree *myTree = NULL;
	Tree *tmp;
	float value;

	for (int i = 0; i < 7; i++)
	{
		printf("Enter value: ");
		scanf("%f", &value);
		AddNode(&myTree, value);
	}

	printf("Elements: ");
	PrintElements(myTree);
	printf("\n");

	printf("Enter value that you want to find: ");
	scanf("%f", &value);
	tmp = Search(&myTree, 4);
	if (tmp)
	{
		printf("Searched node = %f\n", tmp->data);
	}
	else
	{
		printf("Element was not found in you tree.\n");
	}

	DeleteElements(myTree);

	system("pause");
	return 1;
}
