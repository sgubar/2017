#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int main(void)
{   
    printf("Enter a quantity of Figure:");
	int aSize;
    scanf("%d", &aSize);
	FigureList *List=createFigureList(aSize);
	int i;
	for(i=0; i<aSize; i++)
    {
    addCoor(List);
    }
	printFigure(List);
	destroyFigureList(List);
	
}
