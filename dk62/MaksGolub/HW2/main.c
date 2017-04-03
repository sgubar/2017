#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int main(void)
{
	FigureList *List=createFigureList(4);
	addCoor(List);
	printFigure(List);
	destroyFigureList(List);
	
}
