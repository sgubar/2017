#include <stdio.h>
#include <string.h>
#include "dk_tool.h"
#define MAX 1024

int main(void)
{
	FILE *file = fopen("STORAGE.txt", "r");
	FILE *file2 = fopen("Sort.txt", "w");

	if (fopen == NULL)
	{
		printf("progr. down");
		return 0;
	}
	char str[MAX];   //new string
	fgets(str, MAX, file);
		
	int lenght = strlen(str); //lenght 
	printf("FILE has (%i) symbols: %s\n", strlen(str), &str);
	fprintf(file2, "FILE has (%i) symbols: %s\n", strlen(str), &str);

	bubbleSort(str, lenght); //bubble_sort
	printf("BUBBLE:    %s\n", &str);
	fprintf(file2, "BUBBLE: %s\n", &str);

	fgets(str, MAX, file);
    
	selectionSort(str, lenght); //sorting
		printf("SELECTION: %s\n", &str);
	
fprintf(file2, "SELECTION: %s\n", &str);



 	
    fgets(str, MAX, file);
    
	selectionSort(str, lenght); //sorting
	  
	printf("INSERTION: %s", &str); //print arr after sort
	fprintf(file2, "INSERTION: %s", &str);
	printf("\n");
}
