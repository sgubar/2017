#include "Proc.h"

#include <stdlib.h>
#include <stdio.h>
#define LEN 255



int readInt() {
	char in;
	scanf("%d",&in);
	return in;
}

int main() {
	int choice; 
	ptr top = NULL; 
	char *str;
	do {
		printf("\n1: Append to list\n2: Print list\n3: Process\n4: Delete list\n5: Exit\n");
		choice = readInt();
		switch(choice) {
			case 1:
				
				str = (char*)malloc(LEN+1);
				printf("Type line to check (no more than %d characters): ",LEN);
				getc(stdin);
				fgets(str,LEN,stdin);
				
				create(&top,str); 
				free(str); 
				break;
			case 2:
				
				print(top);
				printf("\n");
				break;
			case 3:
				show(process(reverse(top))); 
				top = NULL; 
				break;
			case 4:
				printf("Deleting list\n");
				empty(&top); 
				top = NULL; 
				break;
			case 5:
				empty(&top); 
				break;
			default:
				printf("Wrong command\n");
				break;
		}
	} while (choice != 5);
	return 0;
}
