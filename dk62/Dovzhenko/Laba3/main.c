#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "laba3.h"

int main(void)
{
	char find;
	 char *aline; 
	FILE *file = fopen("file.txt", "r"); 
	char line[1000];
	if (file == NULL) 
		{ 
			printf("Sorry, but file not found.\n"); 
			return -1; 
		} 
	aline = fgets(line, sizeof(line), file);
	printf("String of the file: %s \n", line); 
	int counter = strlen(line); 
	fclose(file);
	
	float time, time1, time2;
	
	time = clock();
	quickSort(line, 0, counter);
	time=clock() - time;
	printf ("Time of selectionSort: %.4f\n", time /CLOCKS_PER_SEC);
	printf("\n"); 
	
	printf("Please, enter the symbol what you want to find: \n");
	scanf("%c", &find);
	Print_To_File(counter,line);
	
	FILE *ffile = fopen("Ffile.txt", "r"); 
	if (ffile == NULL) 
		{ 
			printf("Sorry, but file not found.\n"); 
			return -1; 
		} 
	aline = fgets(line, sizeof(line), ffile);
	printf("String of the file: %s \n", line); 
	fclose(ffile);
	
	time1=clock();
	int finding = BinarySearch( line, find);
	time1=clock()-time1;
printf ("Time of search: %.4f\n", time1 /CLOCKS_PER_SEC);
if(-1==finding) 
	printf("This element is not found.\n");
else
	printf("\nFound in the %i position \n",finding+1);
}
