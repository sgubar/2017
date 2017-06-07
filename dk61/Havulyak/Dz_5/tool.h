#ifndef tool_h
#define tool_h
#include <stdio.h>
#include <stdlib.h>


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
void writeList(FILE *aFile, FigureList *aFigure); //write List in JSON;
void writeFigure(FILE *aFile, Figure *aFigure); //Auxiliary funcion to write points;
void BubbleSort(FigureList *aFigure); //function of bubble sorting;
int BinarySearch(FigureList *aFigure); //function of binary searching;
void swap(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int mediana(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int m_partitionIt(FigureList *aFigure, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort2(FigureList *aFigure, int aLeftIndex, int aRightIndex);
void m_manualSort(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int scan_f(void);
	

#endif
