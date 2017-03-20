//  main.c
//  dz3
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tool.h"
#include "sort.h"
	
unsigned const int size = 4;

int main() 
{
	float container = 0;
	FILE *theFile = fopen("Database.json", "w+");
	
	FigureList *theList = createFigureList( abs(size) ); 
	addCircle(theList, 1, 2, 3);
	addCircle(theList, 3, 23, 14);
	addCircle(theList, 4, 23, 43);
	addCircle(theList, 12, 2, 11);
	addCircle(theList, 123, 2, 12);

	
//	Circle *aCircle = &(theList->circles[1]); 
//	container = Square(aCircle);
//	printf("\nSquare = %i\n", container);

	printf("\n         .........................Before Sorting.........................\n");
	printFigureList(theList);
	Bubble_Sort_List(theList);
//	Selection_Sort_List(theList);
//	Insertion_Sort_List(theList);
	printf("\n         .........................After Sorting.........................\n");
	printFigureList(theList);
	
	fileWrite(theFile, theList);

	destroyFigureList( theList );
	fflush(theFile);
	fclose(theFile);	
	return 0;
}
