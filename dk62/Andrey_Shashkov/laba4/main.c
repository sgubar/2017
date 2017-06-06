#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[])
{

Node *head = NULL;
FILE *file = fopen("file.txt","r");
if(!file)
	{
    printf("No such file!\n");
	exit(-77);
	}

char c;
while(c != EOF)
	{
	c = fgetc(file);
	
	while(c != '\n' && c != EOF)
		{
		crFirst_push(&head, c);
		c = fgetc(file);
    	}
    
	if(c != EOF)
    	{
		printList(head);
		delList(&head);
		}
	}
fclose(file);

system("pause");
return 0;
}
