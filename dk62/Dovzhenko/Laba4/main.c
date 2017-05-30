#include <stdio.h>
#include <stdlib.h>

#include "link.h"

int main(int argc, const char *argv[])
{
	int size;
	
	//Enter size of list
	do{
		printf("Enter size of linked list between 3 and 25: ");
		scanf("%i", &size);
	}while(size < 3 || size > 25);
	
	//creating list with random values
	Node *head = createList(size);
	printLinkedList(head);
	
	//find average of linked list
	float center = findAverage(head);
	printf("\nAverage value of list: %.3f\n", center);
	
	//find max value before average in list
	int trash = findTrash(head, center);
	printf("Number of element to delete: %i\n", trash);
	printf("With value: %i\n", valueElement(head, trash));
	
	//deleting this value
	deleteElement(&head, trash);
	printLinkedList(head);
	
	//deleting all list
	deleteList(&head);
	
	return 0;
}
