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
	Coord *coords; 
	
}Pts;

typedef struct List
{
	Pts *squares; 
	int size;
	int current_size;
	
}PtsList;

PtsList *createPtsList(int size);
int fillList(PtsList *aPts);
void printPts(PtsList *aPts);





