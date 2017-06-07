#include <stdio.h>
#include <stdlib.h>
#ifndef dk_tool_h
#define dk_tool_h

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
int addCoordinate();
void printFigure(FigureList *aFigure);
void destroyFigureList(FigureList *aFigure);
int BinarySearch(FigureList *aFigure);
void swap(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int mediana(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int m_partitionIt(FigureList *aFigure, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(FigureList *aFigure, int aLeftIndex, int aRightIndex);
void m_manualSort(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int scan(void);

#endif 
