#include <stdio.h>
#include <stdlib.h>

#define dk_tool_h

typedef struct coordinate
{
	int x;
	int y; 	
}Coord;

typedef struct Coords
{
	Coord *coords; //coorder on coordinate;
	
}Pts;

typedef struct List
{
	Pts *triangle; //coorder on coords;
	int size;
	int current_size;
	
}PtsList;

PtsList *createPtsList(int size);
int fillList(PtsList *aPts);
void printPts(PtsList *aPts);
