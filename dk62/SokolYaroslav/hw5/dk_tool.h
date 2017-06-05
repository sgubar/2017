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
void writeList(FILE *aFile, FigureList *aFigure); 
void writeFigure(FILE *aFile, Figure *aFigure); 
int scan_f(void);

void swap(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int mediana(FigureList *aFigure, int aLeftIndex, int aRightIndex);
int m_partitionIt(FigureList *aFigure, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort2(FigureList *aFigure, int aLeftIndex, int aRightIndex);
void m_manualSort(FigureList *aFigure, int aLeftIndex, int aRightIndex);

int line_find(FigureList *aFigure);
