include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{

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


    for(int i = 0; i < 10; i++)
    {
        AddElementToList(&head, &last);
    }

    Node *tmpHead = head;
    head = head->next;
    free(tmpHead);
    
	PrintEdge(&head, &last, edge);
    PrintRange(&head, &last, a, b);
    PrintNOTRange(&head, &last, a, b);
    return 0;
}
