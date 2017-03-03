#ifndef tool_h
#define tool_h

typedef struct circleFigure
{
int x;
int y;
int radius;	
}Circle;

typedef struct List
{
	Circle *circles;
	int size;
	int current_size;
}FigureList;

int addCircle (FigureList *theList, int x, int y, int radius);
float Square (Circle *aCircle);

FigureList *createFigureList ( int aSize);
void destroyFigureList(FigureList *aList);

#endif
