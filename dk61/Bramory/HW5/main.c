//  main.c
//  dz3
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tool.h"
#include "sort.h"

#define SIZE_OF_BUFFER 100	
unsigned const int size = 7;

int main() 
{
	
	FILE *theFile = fopen("Structure of objects.json", "w+");
	if (NULL == theFile)
	{
		printf("Can\'t create output file");
		return -1;
	}
	else
	{
		FigureList *theList = createFigureList( size ); 
		addCircle(theList, 1, 2, 3);
		addCircle(theList, 3, 23, 5);
		addCircle(theList, 4, 23, 9);
		addCircle(theList, 4, 23, 1);
		addCircle(theList, 4, 23, 7);
	
		printf("\n     .........................Before Sort.........................\n");
		
		printFigureList(theList);
		
		printf("\n\nChoose type of sort:\n");
		printf("(b)ubble, (s)election, (i)nsertion, S(h)ell sort:\n");
		char option = '\0';
		char *name_of_sort = (char *)malloc (sizeof(char) * SIZE_OF_BUFFER);
		while  ( option != 'b' &&
			     option != 's' &&
			 	 option != 'i' &&
				 option != 'h' )
		{
			option = getch();
		}
		switch(option)
		{
			case 'b': name_of_sort = "Bubble";    Bubble_Sort_List(theList);    break;
			case 's': name_of_sort = "Selection"; Selection_Sort_List(theList); break;
			case 'i': name_of_sort = "Insertion"; Insertion_Sort_List(theList); break;
			case 'h': name_of_sort = "Shell";	  Shell_Sort_List(theList);     break;
		}
		
		printf("\n     .........................After %s Sort.........................\n", name_of_sort);
		printFigureList(theList);
		
		fileWrite(theFile, theList);
	
		printf("\n\nType the radius which do you want to find ");
		int key = num_scan();
		int index = linear_search(key, theList);
		printf("\n Linear_search: \n" );
		if ( index != -1)
		{
			printf("\n Found in object #%d:\n", index );	
			printCircle(&theList -> circles[index]);	
		}
		
		else 
			printf("Error 404. Not found object");
			
		index = 0;
		printf("\n\n Binary_search:" );
		index = binary_search(key, theList);
		if ( index != -1)
		{
			printf("\n Found in object #%d:\n", index );	
			printCircle(&theList -> circles[index]);	
		}
		else 
			printf("\nError 404. Not found object");	
	
		destroyFigureList( theList );
		fflush(theFile);
		fclose(theFile);	
//		free(name_of_sort);
	}
return 0;
}
