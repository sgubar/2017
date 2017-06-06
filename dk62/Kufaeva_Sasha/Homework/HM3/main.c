#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include "sort.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int theResult = 0;
	ParpipedList * theParpiped = createParpipedList(6);
	
	addParpipedCoordinates(theParpiped);
	addParpipedCoordinates(theParpiped);
	addParpipedCoordinates(theParpiped);
	addParpipedCoordinates(theParpiped);
	addParpipedCoordinates(theParpiped);


	FILE *theFile = fopen("json2.txt", "w");
	printf("Before sorting....\n");
	printParpipedList(theParpiped);
	writeParpipedList(theFile, theParpiped);

	//  bubbleSort(theParpiped);
	// selectionSort(theParpiped);
	// insertionSort(theParpiped); 


	printf("After sorting....\n");
	//bubbleSort(theParpiped);
	//selectionSort(theParpiped);
	//insertionSort(theParpiped);
	quickSort2(theParpiped,0, theParpiped->current_size - 1);
	printParpipedList(theParpiped);
	printf("Print the square of the parpiped which you want to find : \n");
	
	scanf("%d", &theResult);
	theResult = BinarySearch(theParpiped,theResult);
	if (theResult == -1)
		printf("There are no parpiped with such square");
	
	



	destroyParpipedList(theParpiped);
	getch();
	return 0;
}
