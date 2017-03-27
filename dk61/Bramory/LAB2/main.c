/*
Практично визначити час сортування,
що затрачений кожним з алгоритмів для сортування масиву.
Кожен з алгоритмів реалізувати у вигляді окремої функції

5. Отримати масив букв (a-z, A-Z) з файлу. 
Сортувати по спаданню значень символів.
 Результат записати до файлу
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "tool.h"
#include "sort.h"
#include "quickSort.h"

#define AMOUNT_OF_SORT 5
#define SIZE_OF_BUFFER 200

char compare(const void * x1, const void * x2)// for implemented qsort
{
  return ( *(char*)x1 - *(char*)x2 );              
}

int main()
{
	unsigned int size_of_array = 99999;
	int size;
	char click;
	char *path  = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER); 
	getcwd(path, 100);
	strcat(path, "\\Sorted_Arrays\\"); // directory for the results
	mkdir(path);

	char *inputFile  = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER); 
	memset(inputFile, '\0', sizeof(char) *SIZE_OF_BUFFER);
	char *name_of_sort = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER);
	char *myArray;
	
printf("Choose the type:\n (r)andom or filling from (f)ile:");
while( click != 'r' && click != 'f')
{
	int result;
	click = getch();
	if (click == 'r')	
	{
		srand(time(0)); 
		size = size_of_array;
		myArray = (char *) malloc( sizeof(char) * size);
		fillArrayChar('A', 'z', size * sizeof(char), myArray);	
	}
	if (click == 'f')
	{
		system("cls");
		system("dir");
		printf("\nType a name of a file, which do you want to sort\n");
		printf("Follow the next format: \"example.txt\"\n");
		result = read_filename(inputFile, SIZE_OF_BUFFER);
		if (result != 0 )
		{
			printf("Error 5. Filename too big");
			return -5;	
		}
	myArray = scan_text(&size_of_array, inputFile); 	// fill array with text from file
		if (myArray == NULL)		// Check file
	{
		free(myArray);
		printf("Error 1. Can\'t find \"%s\" ", inputFile);
		return -1;
	}
	
		if (size_of_array == -1)		//	If size of file > size_of_array
	{
		free(myArray);
		printf("Error 2. Memory overflow");
		return -2;
	}
	
	size = strlen(myArray);

	}
}
fileWrite("Original_array", size, myArray);


	
	
	char *temp = (char *)malloc(sizeof(char) * size);	
	if (NULL == temp) 
	{
		printf("Error 3. Can\'t create temp array");
		return -3;
	}

	printf("\nSize of array = %i bytes\n", size * sizeof(char) );   
	memmove(temp, myArray, sizeof(char) * size);	//save original array

	strcat(path, "\\Sort_results.csv");
	FILE *theFile = fopen(path, "w+");
	if (NULL == theFile) 
	{
		printf("Error 4. Can\'t create output file for results");
		return -4;
	}

//	interface for output file
	fprintf(theFile, "#,"); 
	fprintf(theFile, "Time - msec," ); 
	fprintf(theFile, "Type of Sort,");
	fprintf(theFile, "Size of array = %i bytes\n", size * sizeof(char));
// 
	
	printf("Sorting in progress...\n");
int i;
	for(i = 1; i <= AMOUNT_OF_SORT; i++)	//different types of sorting
	{	
	int time = clock();
	switch( i )
	{
		case 1:		
		{
			qsort(myArray, size, sizeof(char), compare);
			strcpy(name_of_sort, "Qsort_Standart");
			break;
		}
		case 2:
		{
			shell_sort(size, myArray);
			strcpy(name_of_sort, "Shell_sort");
			break;
		}
		case 3:		
		{
			insertion_sort(myArray, size);
			strcpy(name_of_sort, "Insertion_sort");
			break;
		}
		case 4:		
		{
			selection_sort(size, myArray);
			strcpy(name_of_sort, "Selection_sort");
			break;
		}
		case 5:		
		{
			bubble_sort(size, myArray);
			strcpy(name_of_sort, "Bubble_sort");
			break;
		}
		case 6:		
		{
//			quick_sort(size, myArray);
			strcpy(name_of_sort, "Quick_sort");
			break;
		}
	}   
	fprintf(theFile, "%d), %i, %s\n", i, (clock() - time), name_of_sort );  //results of sorting  
	fileWrite(name_of_sort, size, myArray);			//Sorted array write into the file
	memmove(myArray, temp, sizeof(char) * size); // copy array from temp
	}

	printf("Complete!");

	free(myArray);
	free(temp);
	free(path);
	free(name_of_sort);
	free(inputFile);

return 0;	                      
}

