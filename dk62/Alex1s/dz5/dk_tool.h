#ifndef dk_tool_h
#define dk_tool_h

typedef struct aDot
{
	float X;
	float Y;
}Dot;

typedef struct aFigure
{
	Dot *A;
	Dot *B;
	Dot *C;
}Figure;

typedef struct aTriangles
{
	Figure *place[5];		//array of pointers
	int currentSize;
	int maxSize;
}Triangles;

Triangles *createList();
int createTriangle(Triangles *Element);

void enterCoor(Figure *aCurrent);
double calcArea(Figure *aCurrent);

void deleteList(Triangles *Element);
void deleteTriangle(Triangles *Element, int i);

void printTriangles(Triangles *Element);
void printTriangle(Triangles *Element, int i);

void shellSort(Triangles *Element);
int lineSearch(Triangles *Element, double Val);

#endif
