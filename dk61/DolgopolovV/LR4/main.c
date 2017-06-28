#include "dk_tool.h"

int main()
{
	Node *theNode = NULL;
	char file_name[100];
	printf("Enter file name:");
	scanf("%s", file_name);
	system("cls");
	FILE *afile = fopen(file_name, "r");

	if (afile != NULL)
	{
		char obj;
		while ((obj = fgetc(afile)) != EOF)
		{
			if (isalpha(obj))
			{
				while (isalpha(obj))
				{
					theNode = add(theNode, obj);
					obj = fgetc(afile);
				}

				if (theNode != NULL)
				{
					print(theNode);
					del(theNode);
					theNode = NULL;
				}
			}
			printf("%c", ' ');
		}
		fclose(afile);
		getch();
	}
	else
	{
		printf("No file\n");
		return 1;
	}

	return 
