#include "SortMethod.h"
#define MAX 1024

int main(void)
{
	FILE *file = fopen("ValueContainer.txt", "r"); //open file to read
	FILE *file2 = fopen("SortedValues.txt", "w");  //open file to write

	FileOpenCheck(file, file2);
	char str[MAX];   //creating our string
	fgets(str, MAX, file); //get values from ValueContainter.txt
	int string_lenght = strlen(str); //determine lenght of our file
	
	printf("Before sorting: %s\n", &str);
	fprintf(file2, "Before sorting: %s\n", &str);
//- - - - - - - - - - - - - - - - - - -	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	//
	
	printf("\n -Bubble Sort- ");
	
	bubbleSort(str, string_lenght); //bubble_sort
	
	printf("\nAfter sorting: %s\n", &str); //print arr after sort
	fprintf(file2, "\n -Bubble Sort-\nAfter sorting: %s\n", &str);
	
//- - - - - - - - - - - - - - - - - - -	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	//

   	printf("\n -Selection Sort- ");
   	
	MoveArrayPoint(file);
    fgets(str, MAX, file);
	selectionSort(str, string_lenght); //sorting
	
	printf("\nAfter sorting: %s\n", &str); //print arr after sort
	fprintf(file2, "\n -Selection Sort-\nAfter sorting: %s\n", &str);
	
//- - - - - - - - - - - - - - - - - - -	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	//	
	//float time = clock();//
   	printf("\n -Shell Sort- ");
	MoveArrayPoint(file);
    fgets(str, MAX, file);
    
	ShellSort(str, string_lenght); //sorting
	//time = (clock() - time);//
	
	printf("\nAfter sorting: %s\n", &str); //print arr after sort
	fprintf(file2, "\n -Shell Sort-\nAfter sorting: %s\n", &str);
	//printf("Time for Shell Sort : %.10f \n", (double)time/CLOCKS_PER_SEC);//
//- - - - - - - - - - - - - - - - - - -	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	//
	char key;
	float time2 = clock();
	LineSearch(file2, key, str, string_lenght); //func of linesearch	
	time2 = (clock() - time2);
	printf("Time for Linear search : %.3f sec\n", time2*0.001);
	fprintf(file2, "Time for Linear search : %.3f sec\n", time2*0.001);
//- - - - - - - - - - - - - - - - - - -	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	//
	
	FileCloseCheck(file, file2); //closing a file
}
