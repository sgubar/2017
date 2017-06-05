#include <stdio.h>
#include <stdlib.h>

#define dk_tool_h

typedef struct coordinat
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
	Figure *chotirikytnik; //pointer on points;
	int size;
	int current_size;
	
}FigureList;

FigureList *createFigureList(int size);
int addCoor(FigureList *aFigure);
void printFigure(FigureList *aFigure);
void destroyFigureList(FigureList *aFigure);
int scan_f(void);
