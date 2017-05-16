#ifndef t_h
#define t_h


typedef struct Coordinate
{
    int x;
    int y;
} RectanglePoint;

typedef struct describe_1_rectangle
{
    RectanglePoint * PointA;
    RectanglePoint * PointB;
    RectanglePoint * PointC;
    RectanglePoint * PointD;
  } Rectangle;

typedef struct RectangleList
{
    Rectangle* Rectangles;
    int size;
    int current_size;
} ListFigures;

ListFigures *CreateListFigure (int aSize);

int AddRectangle(ListFigures * AFigures);

double Square(Rectangle * rectangle);

void PrintSquare(ListFigures *FiguresNumber);

void DestroyList(ListFigures * AFigures);

void Coordinates(RectanglePoint*PointA, RectanglePoint*PointB, RectanglePoint*PointC, RectanglePoint*PointD);

void writeRectangle(FILE *aFile, Rectangle *aNote);

void writeList(FILE *aFile, ListFigures * AFigures);

#endif
