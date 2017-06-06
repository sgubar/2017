#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main()
{
	Node *theNode = NULL;
	FILE *afile = fopen("txt.txt","r");
	
	if(afile != NULL)
	{
		char obj;
		while((obj = fgetc(afile)) != EOF)
		{
			if(isalpha(obj))
			{
				while(isalpha(obj) && obj != '\n' && obj != EOF)
				{
					addElement(&theNode, obj);
					obj = fgetc(afile);
			   	}
				
				if(theNode != NULL)
			   	{
					printList(theNode);
					deleteList(&theNode);
				}
			}
			printf("%c", obj);
		}
		fclose(afile);
	}
	else
	{
		printf("No file\n");
		return 1;
	}
	
	return 0;
}
