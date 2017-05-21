#ifndef tool_h
#define tool_h

typedef struct pyramidVertex				
{
	int x;
	int y;
	int z;	
}vertex;

typedef struct pyramidFigure			
{
	vertex *vertices;	
}pyramid;

typedef struct figuresList					
{
	pyramid *pyramids;
	int maxSize;
	int pyramidsCounter;
}pyramidsList;

pyramidsList *createPyramidsList (int aSize);				
void destroyAPyramidsList(pyramidsList *aPyramidsList);		

int addPyramid (pyramidsList *aPyramidsList);				

void printPyramidsList(pyramidsList *aPyramidsList);
int printPyramid(pyramid *aPyramid);	

void printSquare(pyramidsList *aPyramidsList);
float pyramidSquare(pyramid *aPyramid);

int NumInput(void);

#endif
