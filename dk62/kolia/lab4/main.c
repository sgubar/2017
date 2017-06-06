#include <stdio.h>
#include <stdlib.h>

#include "link.h"

int main(int argc, const char *argv[])
{
	int size;


	do{
		printf("Enter size of linked list between 3 and 25: ");
		scanf("%i", &size);
	}while(size < 3 || size > 25);


	Node *head = createList(size);
	printLinkedList(head);


	float center = findAverage(head);
	printf("\nAverage value of list: %.3f\n", center);


	int trash = findTrash(head, center);
	printf("Number of element to delete: %i\n", trash);
	printf("With value: %i\n", valueElement(head, trash));


	deleteElement(&head, trash);
	printLinkedList(head);


	deleteList(&head);

	return 0;
}
