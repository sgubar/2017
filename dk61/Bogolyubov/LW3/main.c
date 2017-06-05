#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
	FILE *file = fopen("STORAGE.txt", "r");
	FILE *file2 = fopen("sort.txt", "w");  
printf("The program can sort 100 characters\n\n");
	char str[100]; 
	fgets(str, 100, file); //get values from file
	int lenght = strlen(str); //lenght
	printf("FILE has (%i) symbols: %s\n\n", strlen(str), &str);
	fprintf(file2, "FILE has (%i) symbols: %s\n", strlen(str), &str);
	

    fgets(str, 100, file);
    
	ShellSort(str, lenght); //sorting
		printf("SHELL SORT: %s\n", &str);

	fprintf(file2, "SHELL SORT: %s\n", &str);

	char marker;
	LineSearch(file2, marker, str, lenght); // line search

}
