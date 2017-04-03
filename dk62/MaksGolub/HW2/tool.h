#include <stdio.h>
#include <stdlib.h>

#define tool_h

typedef struct coordinate
{
	int x;
	int y; 
	int z;
	
}Point;

typedef struct Points
{
	Point *points;
}Figure;

typedef struct List
{
	Figure *paralel;
	int size;
	int current_size;
	
}FigureList;

FigureList *createFigureList(int size);
int addCoor(FigureList *aFigure);
int printFigure(FigureList *aFigure);
void destroyFigureList(FigureList *aFigure);
int scan_f(void);
