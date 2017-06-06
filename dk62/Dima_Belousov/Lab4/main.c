#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "dk_tool.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Node *head = NULL;
    Node *last = NULL;

    createList(&head, &last);

    int x,i;
    printf("Введите размер списка: ");
    scanf("%d", &x);

    for(i = 0; i < x; i++){
    addToList(&head, &last);
    }


    Node *tmpHead = head;
    head = head->next;
    free(tmpHead);

    printElements(&head, &last);

    Node *tmp = findMinimum(&head, &last);

    sort(&head, &last, &tmp);

    printElements(&head, &last);

    int k=0;

    for( k = 0; k < 5; k++)
    {
        deleteElement(&head);
    }

    return 0;
}
