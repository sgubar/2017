#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int main(void)
{   
    printf("Enter a quantity of Figure (not more 10):");
	int Size=scan_f();
	FigureList *List=createFigureList(10);
	int i;
    for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
    printFigure(List); //print figures before sorting;
    //BubbleSort(List); 
    quickSort2(List, 0, List->current_size - 1);
    printf("After sorting\n");
	printFigure(List); //print figures after sorting;
	printf("Enter square for searching: ");
	int result = BinarySearch(List);
	printf("Position of figure: %d", result);
	//writeList(aFile, List);
	destroyFigureList(List);
	
}
