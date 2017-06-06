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
	
}List_of_Figure;

List_of_Figure *createList_of_Figure(int size);
int addCoor(List_of_Figure *aFigure);
void printFigure(List_of_Figure *aFigure);
void destroyFigureList(List_of_Figure *aFigure);
void writeList(FILE *aFile, List_of_Figure *aFigure); //write List in JSON;
void writeFigure(FILE *aFile, Figure *aFigure); //Auxiliary funcion to write points;
void selectionSort(List_of_Figure *aFigure);
int scan_f(void);
