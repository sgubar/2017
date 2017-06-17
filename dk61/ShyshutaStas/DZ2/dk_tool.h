#include <stdio.h>
#include <stdlib.h>
#ifndef dk_tool_h
#define dk_tool_h

typedef struct coordinate
{
	int x,y,z;	
}Point;

typedef struct Points
{
	Point *points;
}Figure;

typedef struct List
{
	Figure *paralel; 
	int size,current_size;
}mylist;

mylist *createMyList(int size);
int addCoor(mylist *aFigure);
void printMyFigure(mylist *aFigure);
void destroyMyList(mylist *aFigure);
int scan(void);

#endif 
