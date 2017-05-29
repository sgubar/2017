#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"


void CreateList(Node **head)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = 0;
    newNode->next = (*head);

    (*head) = newNode;

    newNode = NULL;
}


void AddElementToList(Node **head)
{
    float theData;
    printf("Enter value: ");
    scanf("%f", &theData);

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = theData;
    newNode->next = (*head);

    (*head) = newNode;

    printf("Element added\n");

}

void DeleteElement(Node **head)
{
    if((*head)->next == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *tmp = (*head);
    (*head) = (*head)->next;
    free(tmp);

    printf("Element deleted\n");
}


void PrintElements(Node *head)
{
    int size = 0;
    printf("List elements: ");
    while(head->next)
    {
        printf("%f ", head->data);
        size++;
        head = head->next;
    }
    printf("\n");
    printf("List size %i\n", size);
}


Node *FindMinimum(Node **head)
{
    Node *minNode = (*head);
    do
    {
        if(minNode->data > (*head)->next->data)
        {
            minNode->data = (*head)->next->data;
        }
        (*head) = (*head)->next;
    }
    while((*head)->next->next);
    printf("Minimum: %f\n", minNode->data);
    return minNode;
}

void swap(Node *a, Node *b)
{
    float temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void Sort(Node **head)
{
    Node *minNode = (*head);
    do
    {
        if(minNode->data > (*head)->next->data)
        {
            minNode->data = (*head)->next->data;
        }
        (*head) = (*head)->next;
    }
    while((*head)->next->next);
    printf("Minimum: %f\n", minNode->data);


    int swapped;
    float temp;

    Node *lptr = NULL;

    do
    {
        swapped = 0;

        while (minNode->next->next != lptr)
        {
            if (minNode->data > minNode->next->data)
            {
                temp = minNode->data;
                minNode->data = minNode->next->data;
                minNode->next->data = temp;

                swapped = 1;
            }

            minNode = minNode->next;
        }
        lptr = minNode;
    }
    while (swapped);
}
