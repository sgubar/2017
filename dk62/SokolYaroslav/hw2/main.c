#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    srand(time(NULL));
    printf("Vvedite kolichestvo figur:");
	int Size=scan_f();
	FigureList *List=createFigureList(9999);
	int i;
	for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
	printFigure(List);
	destroyFigureList(List);
	
}
