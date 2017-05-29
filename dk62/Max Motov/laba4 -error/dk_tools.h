#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main()
{
    Node *head = NULL;
    CreateList(&head);

    for(int i = 0; i < 4; i++)
    {
        AddElementToList(&head);
    }

    PrintElements(head);

    Sort(&head);

    PrintElements(head);

    for(int i = 0; i < 4; i++)
    {
        DeleteElement(&head);
    }

    system("pause");

    return 0;
}
