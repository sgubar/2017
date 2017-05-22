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
	Point *points; //pointer on coordinate;
}Figure;

typedef struct List
{
	Figure *paralel; //pointer on points;
	int size;
	int current_size;
	
}FigureList;

FigureList *createFigureList(int size);
int addCoor(FigureList *aFigure);
void printFigure(FigureList *aFigure);
void destroyFigureList(FigureList *aFigure);
void writeList(FILE *aFile, FigureList *aFigure); //write List in JSON;
void writeFigure(FILE *aFile, Figure *aFigure); 
void BubbleSorT(FigureList *aFigure); //function of bubble sorting;
/*void selectionSort(FigureList *aFigure); */
int scan_f(void);
