/*
Практично визначити час сортування, 
що затрачений кожним з алгоритмів 
для сортування масиву та пошуку елемента в масиві.
Кожен з алгоритмів реалізувати у вигляді окремої функції

1. QuickSort + лінійний пошук. 
Масив заповнити випадковими числами (0-10000).
Заповнення організувати у вигляді окремої функції. 
Результат записати до файлу.
*/
#include <stdio.h>
#include <stdlib.h> //malloc
#include <memory.h> //memset
#include <string.h>
#include <time.h>	
#include <unistd.h> //getcwd()
#include "tool.h"
#include "sort.h"

#define SIZE_OF_BUFFER 200

int main()
{
	unsigned int size_of_array = 100;
	int size;
	char *path  = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER);
	memset(path, '\0', sizeof(char) * SIZE_OF_BUFFER); 
	getcwd(path, 100);
	strcat(path, "\\Sorted_Arrays\\"); // directory for the results
	mkdir(path);

	char *inputFile  = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER); 
	memset(inputFile, '\0', sizeof(char) * SIZE_OF_BUFFER);
	char *name_of_sort = (char *) malloc(sizeof(char) * SIZE_OF_BUFFER);
	memset(name_of_sort, '\0', sizeof(char) * SIZE_OF_BUFFER);
	int *myArray;
	
	printf("\tChoose the type:\n (r)andom integers or filling numbers from (f)ile:");
	char option = '\0';
	while( option != 'r' && option != 'f')
	{
		int result;
		option = getch();
		if (option == 'r')	
		{ 	
			srand(time(0)); 
			size = size_of_array;
			myArray = (int *) malloc( sizeof(int) * size + 1);
			memset(myArray, 0, sizeof(int) * size);
			fillArrayInt(0, 10000, size, myArray);	
		}
		if (option == 'f')
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
			
			myArray = read_num(&size_of_array, inputFile); 	// fill array with text from file
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
			//size modify inside function (&)
			size = size_of_array;
		} 							// ending work with file
	}
	
	fileWrite("Original_array", size, myArray);
	printf("\n\nAmount of elements = %i", size);
	printf("\nSize of array = %.3f Kb\n", (float) (size * sizeof(int))/1024 );   

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
	fprintf(theFile, "Size of array = %i bytes\n", size * sizeof(int));
 

	printf("Choose a type of the sort:\n");
	printf("(q)uick, s(h)ell, (i)nsertion, (s)election, (b)ubble:\n");
	option = '\0';
	while  ( 
			option != 'q' &&
			option != 'b' &&
			option != 's' &&
			option != 'h' &&
			option != 'i' )
	{
		option = getch();
	}
	
	//for nice debug with few (<=20) elements
	size_of_array <= 20? printArray(myArray, size)
					   : printf("\nArray will be write in the file\n");
		
	printf("Sorting in progress...\n");
		float time = clock();
		switch( option )
		{
			case 'q':		
			{
				quick_sort(myArray, 0, size - 1);
				strcpy(name_of_sort, "Quick_sort");
				break;
			}
			case 'h':
			{
				shell_sort(size, myArray);
				strcpy(name_of_sort, "Shell_sort");
				break;
			}
			case 'i':		
			{
				insertion_sort(size, myArray);
				strcpy(name_of_sort, "Insertion_sort");
				break;
			}
			case 's':		
			{
				selection_sort(size, myArray);
				strcpy(name_of_sort, "Selection_sort");
				break;
			}
			case 'b':		
			{
				bubble_sort(size, myArray);
				strcpy(name_of_sort, "Bubble_sort");
				break;
			}
		}   
	fprintf(theFile, "1), %f, %s\n", (clock() - time), name_of_sort );  //results of sorting  
	fileWrite(name_of_sort, size, myArray);			//Sorted array write into the file

	printf("Sort Complete\n");
	
		//for nice debug with few (<20) elements
	size_of_array < 20?	printArray(myArray, size)
					  : printf("\nSee file %s.txt\n", name_of_sort);
		
	printf("Type number which you want to search: ");
	int key = num_scan();
	time = clock();
	int proof = line_search(key, size, myArray); 
	time = (clock() - time);
	char * state = proof == 0 ? "Found": "Not Exist";
	printf("\nState:  %s", state);
	printf("\nTime for line_search: %.0f msec \n", time);

	time = clock();
	proof = binary_search(key, size, myArray); 
	time = (clock() - time);
	state = proof == 0 ? "Found": "Not Exist";
	printf("\nState:  %s\n", state);
	printf("Time for binary_search: %.0f msec \n", time);


	free(myArray);
	free(path);
	free(name_of_sort);
	free(inputFile);
	
	//	easy way to open output files fast
	system("pause");
	system("start \Sorted_Arrays\\Original_Array.txt");
	system("start \Sorted_Arrays\\Quick_sort.txt");
	
	system("pause");
	
return 0;	                      
}

