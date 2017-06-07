#include "dk_tool.h"
#define MAX 10000

int main(void)
{
	FILE *file = fopen("Container.txt", "r"); //open file to read
	FILE *file2 = fopen("Sort.txt", "w");  //open file to write

	FileOpenCheck(file, file2);
	char str[MAX];   //creating our string
	fgets(str, MAX, file); //get values from ValueContainter.txt
	int string_lenght = strlen(str); //determine lenght of our file
	
	printf("Before sorting: %s\n", &str);
	fprintf(file2, "Before sorting: %s\n", &str);
	
	printf("\nBubble Sort ");
	printf("Sorting...\n");
	float time3 = clock();
	bubbleSort(str, string_lenght); //bubble_sort
	time3 = (clock() - time3);
	printf("Time for Bubble Sort : %.10f \n", time3*0.001);

   	printf("\nSelection Sort ");
   	printf("Sorting...\n");
	MoveArrayPoint(file);
    fgets(str, MAX, file);
    float time4 = clock();
	selectionSort(str, string_lenght); //sorting
	time4 = (clock() - time4);
	printf("\nTime for Selection Sort : %.10f \n", time4*0.001);

	
   	printf("\nShell Sort");
   	printf("Sorting...\n");
	MoveArrayPoint(file);
    fgets(str, MAX, file);
    
    float time = clock();
	ShellSort(str, string_lenght); //sorting
	time = (clock() - time);
	
	printf("\nAfter sorting: %s\n", &str); 
	printf("Time for Shell Sort : %.10f \n", time*0.001);
	
	char key;
	float time2 = clock();
	
	LineSearch(file2, key, str, string_lenght); 	
	
	time2 = (clock() - time2);
	
	printf("Time for Linear search : %.10f sec\n", time2*0.001);
	fprintf(file2, "Time for Linear search : %.10f sec\n", time2*0.001);
	
	
	if (fclose (file) == EOF)
		   { 
		    printf ("Error. 'Container.txt' is not closed.\n");
		   }
 
	if (fclose (file2) == EOF)
		   { 
		    printf ("Error. 'Sort.txt' is not closed.\n");
		   }
		
}
