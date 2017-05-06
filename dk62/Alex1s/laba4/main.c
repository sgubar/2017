#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to test a linked list of char elements.\n");
printf("Program is going to open file \"data.txt\" in same directory with program.\n\n");

Node *head = NULL;
FILE *file = fopen("data.txt","r");
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
