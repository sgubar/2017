#ifndef tool_h
#define tool_h

typedef struct pyramidVertex				//вершина
{
	int x;
	int y;
	int z;	
}vertex;

typedef struct pyramidFigure			//пирамида
{
	vertex *vertices;	
}pyramid;

typedef struct figuresList					//комната
{
	pyramid *pyramids;
	int maxSize;
	int pyramidsCounter;
}pyramidsList;

pyramidsList *createPyramidsList (int aSize);				//создали комнату для пирамид
void destroyAPyramidsList(pyramidsList *aPyramidsList);		//удалили комнату с пирамидами

int addPyramid (pyramidsList *aPyramidsList);				//добавление пирамиды в комнату

void printPyramidsList(pyramidsList *aPyramidsList);
int printPyramid(pyramid *aPyramid);	

void printSquare(pyramidsList *aPyramidsList);
float pyramidSquare(pyramid *aPyramid);

int NumInput(void);

#endif
