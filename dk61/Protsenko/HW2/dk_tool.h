#include <stdio.h>
#include <stdlib.h>

#define dk_tool_h

typedef struct coordinate
{
	int x;
	int y; 	
}Point;

typedef struct Points
{
	Point *points; //pointer on coordinate;
	
}Figure;

typedef struct List
{
	Figure *triangle; //pointer on points;
	int size;
	int current_size;
	
}FigureList;

FigureList *createFigureList(int size);
int addCoor(FigureList *aFigure);
void printFigure(FigureList *aFigure);
