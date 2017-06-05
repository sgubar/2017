#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main()
{
    Node *head = NULL;
    Node *last = NULL;
    CreateList(&head, &last);


    for(int i = 0; i < 15; i++)
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

    for(int i = 0; i < 15; i++)
    {
        DeleteElement(&head);
    }

    system("pause");

    return 0;
}
