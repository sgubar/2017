#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    FILE *aFile=fopen("data.json", "w");
    printf("Enter a nomber of Figure :");
	int Size=scan();
	FigureList *List=createFigureList(Size);
	int i;
    for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
    printFigure(List);
    quickSort2(List, 0, List->current_size - 1);
    printf("After sorting \n");
	printFigure(List); 
	printf("Enter square for searching: ");
	int result = BinarySearch(List);
	printf("Position of figure: %d", result);
	destroyFigureList(List);
	
}
