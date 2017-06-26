#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tools.h"

int main()
{
Node *theNode = NULL;
FILE *file = fopen("txt.txt", "r");
int a, b, edge;
printf("There is a range [A;B]\n");

	printf("What will be A?: ");
	scanf("%i", &a);
	printf("What will be B?: ");
	scanf("%i", &b);
	printf("Diapason is [%i;%i]\n", a, b);
	printf("What will be edge?: ");
	scanf("%i", &edge);



    Node *head = NULL;
    Node *last = NULL;
    CreateList(&head, &last);

if(file != NULL)
	{
		char obj;
		while((obj = fgetc(file)) != EOF)
		{
		//	if(isalpha(obj))
		//	{
				while(obj != '\n' && obj != EOF)
				{
   // for(int i = 0; i < 10; i++)
   // {
       addElement(&theNode, obj);
  //  }
    }
   // }
    }
    }

    Node *tmpHead = head;
    head = head->next;
    free(tmpHead);
    
	PrintEdge(&head, &last, edge);
    PrintRange(&head, &last, a, b);
    PrintNOTRange(&head, &last, a, b);
    return 0;
}
