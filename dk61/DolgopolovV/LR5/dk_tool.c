#include "dk_tool.h"

b_tree* add(b_tree *atree)
{
	double symbol;
	b_tree* current;
	current = atree;
	system("cls");
	printf("Enter a symbol to add : ");
	scanf("%lf", &symbol);

	if (NULL == atree)
	{
		atree = (b_tree *)calloc(1, sizeof(b_tree));
		atree->value = symbol;
		return atree;
	}

	while (current->left != NULL || current->right != NULL)
	{
		if (current->value < symbol)
			if (current->right != NULL)
				current = current->right;
			else
				break;
		else
			if (current->left != NULL)
				current = current->left;
			else
				break;
	}

	if (current->value < symbol)
	{
		current->right = (b_tree *)calloc(1, sizeof(b_tree));
		current = current->right;
		current->value = symbol;
		return atree;
	}
	else
	{
		current->left = (b_tree *)calloc(1, sizeof(b_tree));
		current = current->left;
		current->value = symbol;
		return atree;
	}
}

b_tree* del(b_tree *atree)
{
	double symbol;
	b_tree* current, *change, *pre;
	
	current = change = atree;
	system("cls");

	printf("\nEnter a symbol to delete : ");
	scanf("%lf", &symbol);

	while (current->value != symbol)
	{
		if (current->value < symbol)
		{
			pre = current;
			current = current->right;
		}
		else
		{
			pre = current;
			current = current->left;
		}
	}

	if (change->left == NULL && change->right == NULL)
		if (pre->left->value == symbol)
			pre->left = NULL;
		else
			pre->right = NULL;

	else if ((change->left != NULL && change->right == NULL) || (change->left != NULL && change->right != NULL))
		if (pre->right->value == symbol)
			if (current->right == NULL)
				pre->right = current->left;
			else
				pre->right = current->right;
		else
			if (current->right == NULL)
				pre->left = current->left;
			else
				pre->left = current->right;
}

void print(b_tree *atree)
{
	if (atree == NULL)
		return;
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
	printf("\nThe root: (%.2lf)\n", atree->value);

	if (NULL != atree)
	{
		PrintElements(atree);
	}
	printf("\n*/");
	for (int i = 0; i < 35; i++) printf("- ");
	printf("/*");
	system("pause");
}

void PrintElements(b_tree *myNode)
{
	if (myNode) 
  {
		PrintElements(myNode->left);
		printf(" (%.2lf) \t", myNode->value);
		PrintElements(myNode->right);
	}
}

void destr(b_tree *aNode)
{
	free(aNode);	
}
