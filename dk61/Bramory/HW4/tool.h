//  tool.h
//  dz3
//
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

//interface
int addCircle (FigureList *theList, int x, int y, int radius);
FigureList *createFigureList ( int aSize);
void destroyFigureList(FigureList *aList);
float Square (Circle *aCircle);


//	Put structure FigureList in the *.JSON
int fileWrite(FILE *aFile, FigureList *aList);
int writeCircle( FILE *aFile, Circle *aCircle);

//	Print List on the screen
int printFigureList(FigureList *aList);
int printCircle(Circle *aCircle);	//mb index?

void Bubble_Sort_List(FigureList *aList);
void Insertion_Sort_List(FigureList *aList);
void Selection_Sort_List(FigureList *aList);

//sound - error for user
void sad(void);

//changing two structures
void swap (Circle *var1, Circle *var2);

#endif
