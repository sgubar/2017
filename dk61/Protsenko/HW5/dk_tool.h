#ifndef dk_tool_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define dk_tool_h

typedef struct coordinate
{
	int x;
	int y; 	
}Point;

typedef struct Points
{
	Point * Coordinates; //pointer on coordinate;
	
}Figure;

typedef struct List
{
	Figure *triangle; //pointer on points;
	int size;
	int current_size;
	
}FigureList;

FigureList *createFigureList(int size);
int FillCoord(FigureList *aFigure);
void PrintTriangle(Figure *aFigure);
void PrintList(FigureList *aFigure);
void ShellSort(FigureList *aFigure);
int BinarySearch(FigureList *aFigure, int key);

#endif
