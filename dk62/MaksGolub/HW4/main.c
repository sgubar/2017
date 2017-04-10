#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int main(void)
{   
    FILE *aFile=fopen("data.json", "w");
    printf("Enter a quantity of Figure (not more 10):");
	int Size=scan_f();
	FigureList *List=createFigureList(10);
	int i;
	for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
    printFigure(List); //print figures before sorting;
    BubbleSort(List); 
    //selectionSort(List);
	printFigure(List); //print figures after sorting;
	writeList(aFile, List);
	
	destroyFigureList(List);
	
}
