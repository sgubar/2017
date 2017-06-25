#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int readInt() {
	int in;
	scanf("%d",&in);
	return in;

int main()
{
	srand(time(NULL)); 
	int choice; 
	ptr root = NULL; 
	do {
		printf("\n1: Create tree\n2: Print tree\n3: Add node\n4: Find node\n5: Remove node\n6: Delete tree\n7: Exit\n");
		choice = readInt();
		switch(choice) {
			case 1:
				printf("Tree size: ");
				if (root) 
					erase(&root); 
				root = create(readInt()); 
				break;
			case 2:
				print(root,0); 
				break;
			case 3:
				printf("Node value (integer value, except zero): ");
				
				printf("%s\n", add(&root,readInt()) ? "Creating new node" : "Replacing node"); 
				break;
			case 4:
				printf("Node value (integer value, except zero): ");
				
				printf("%s\n", find(root,readInt()) ? "Element exists" : "No node found");
				break;
			case 5:
				printf("Node value (integer value, except zero): ");
				int value = readInt();
				if (find(root,value) == NULL) 
					printf("No element to remove\n");
				else { 
					rem(&root,value);
					printf("Removing node\n");
				}
				break;
			case 6:
				
				printf("Deleting tree\n");
				erase(&root);
				root = NULL;
				break;
			case 7:
				erase(&root); 
				break;
			default:
				printf("Wrong command\n");
				break;
		}
	} while (choice != 7);
	return 0;
}
