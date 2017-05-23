#include <stdio.h>
#include <time.h>
#include <string.h>
#include "SortMethod.h"
#define MAX 1024

int main(void)
{
	FILE *file = fopen("ValueContainer.txt", "r"); //open file to read
	FILE *file2 = fopen("SortedValues.txt", "w");  //open file to write

	if (fopen == NULL)  //check did the file open
	{
		printf("Error...\n");
		return 0;
	}
	char str[MAX];   //creating our string
	fgets(str, MAX, file); //get values from ValueContainter.txt
	
	int string_lenght = strlen(str); //determine lenght of our file
	
	printf("Before sorting: %s\n", &str);
	fprintf(file2, "Before sorting: %s\n", &str);
	printf("\n");
	fprintf(file2, "\n");
	printf("Sorting...\n");
	fprintf(file2, "Sorting...\n", &str);
	printf("\n");
	fprintf(file2, "\n");
	
	/*------------------------BUBBLE SORT-------------------------*/
	unsigned int BubbleStartTime = clock(); //determine sort time
	bubbleSort(str, string_lenght); //bubble_sort
	unsigned int BubbleEndTime = clock();
	unsigned int BubbleSearchTime = BubbleEndTime - BubbleStartTime;
	
	printf("After sorting: %s\n", &str); //print arr after sort
	fprintf(file2, "After sorting %s\n", &str);
	printf("\n");
	fprintf(file2, "\n");
	
	printf("BubbleSort_Time: %.10f",(double)(BubbleSearchTime/CLOCKS_PER_SEC)); //print time of execution
	fprintf(file2,"BubbleSort_Time: %.10f\n",(double)(BubbleSearchTime/CLOCKS_PER_SEC));
	/*------------------------SELECTION SORT-------------------------*/
   		if (fseek (file,0,SEEK_SET)==0) //check, has a point moved or isn't
      	   printf (" ");
        else
         printf ("Error\n");
	   
    fgets(str, MAX, file);
    
	unsigned int SelectionStartTime =  clock();
	selectionSort(str, string_lenght); //sorting
	unsigned int SelectionEndTime = clock();
	unsigned int SelectionSearchTime = SelectionEndTime - SelectionStartTime; 
	
	printf("\nSelectionSort_Time : %.10f",(double)(SelectionSearchTime/CLOCKS_PER_SEC));
	fprintf(file2,"SelectionSort_Time: %.10f\n",(double)(SelectionSearchTime/CLOCKS_PER_SEC)); //print time of execution
	/*------------------------INSERTION SORT-------------------------*/
   		if (fseek (file,0,SEEK_SET)==0) //check, has a point moved or isn't
      	   printf (" ");
        else
        printf ("Error\n");
    
    fgets(str, MAX, file);
    unsigned int InsertionStartTime =  clock();
	selectionSort(str, string_lenght); //sorting
	unsigned int InsertionEndTime = clock();
	unsigned int InsertionSearchTime = InsertionEndTime - InsertionStartTime;
	
	printf("\nInsertionSort_Time : %.10f\n",(double)(InsertionSearchTime/CLOCKS_PER_SEC));
	fprintf(file2,"InsertionSort_Time: %.10f\n",(double)(InsertionSearchTime/CLOCKS_PER_SEC)); //print time of execution
	
	printf("\n");
	printf ("Closing SortedValues: ");
   		if (fclose (file2) == EOF) //check, is a file closed or not
		  printf ("Error\n");
   		else
		  {
		  printf ("Done\n");
		  }
		  
	printf ("Closing ValueContainer: ");
   		if (fclose (file) == EOF) //check, is a file closed or not
		  printf ("Error\n");
   		else
		  {
		  printf ("Done\n");
		  return 0;
		  }
}
