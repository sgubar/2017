#include <stdio.h>
#include <time.h>
#include <string.h>
#include "dk_tool.h"
#define MAX 1024

int main(void)
{
	FILE *file = fopen("neotsort.txt", "r");
	FILE *file2 = fopen("otsort.txt", "w");  

	if (fopen == NULL) 
	{
		printf("Error...\n");
		return 0;
	}
	char str[MAX];   
	fgets(str, MAX, file); 
	
	int lenght = strlen(str); 
	
	printf("Before sorting: %s\n", &str);
	fprintf(file2, "Before sorting: %s\n", &str);
	printf("Sorting...\n\n");
	
	printf("bubble sort");

	bubbleSort(str, lenght); 
	
	printf("\nAfter sorting: %s\n", &str);
	fprintf(file2, "\nAfter sorting %s\n", &str);
	



   	printf("selection sort");
	   	if (fseek (file,0,SEEK_SET)==0) 
      	   printf (" ");
        else
         printf ("Error\n");
	   
    fgets(str, MAX, file);
    
	selectionSort(str, lenght); 
	
	printf("\nAfter sorting: %s\n", &str); 
	fprintf(file2, "\nAfter sorting %s\n", &str);



   	printf("insertion sort");	
	   if (fseek (file,0,SEEK_SET)==0) 
      	   printf (" ");
        else
        printf ("Error\n");
    
    fgets(str, MAX, file);
    
	selectionSort(str, lenght); 
	
	printf("\nAfter sorting: %s", &str); 
	fprintf(file2, "After sorting %s\n", &str);
	printf("\n");
	
	
	printf ("Closing neotsort: ");
   		if (fclose (file2) == EOF) 
		  printf ("Error\n");
   		else
		  {
		  printf ("Done\n");
		  }
		  
	printf ("Closing otsort: ");
   		if (fclose (file) == EOF) 
		  printf ("Error\n");
   		else
		  {
		  printf ("Done\n");
		  return 0;
		  }
}
