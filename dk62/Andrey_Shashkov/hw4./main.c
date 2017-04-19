#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    FILE *aFile=fopen("data.json", "w");
    printf("Enter a nomber of Figure :");
	int Size = scan();
	mylist *List=createMyList(Size);
	int i;
	for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
	printMyFigure(List);
	//BubbleSort(List); 
    selectionSort(List);
	printMyFigure(List);
	writeMyList(aFile, List);
	destroyMyList(List);
	fflush(aFile);
	fclose(aFile);
}
