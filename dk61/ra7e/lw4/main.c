#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    Node *head = NULL;
    Node *last = NULL;
    CreateList(&head, &last);

    int i=0;

    for(i = 0; i < 5; i++)
    {
        AddElementToList(&head, &last);
    }

    Node *tmpHead = head;
    head = head->next;
    free(tmpHead);

    PrintElements(&head, &last);

    Node *tmp = FindMinimum(&head, &last);

    Sort(&head, &last, &tmp);

    PrintElements(&head, &last);
    int k=0;

    for( k = 0; k < 5; k++)
    {
        DeleteElement(&head);
    }


    return 0;
}
