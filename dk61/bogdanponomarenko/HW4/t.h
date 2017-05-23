
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef t_h
#define t_h




typedef struct Coordinate
{
    int x;
    int y;
}  RectanglePoint;


typedef struct describe_1_rectangle
{
    RectanglePoint * Point;

} Rectangle;


typedef struct RectangleList
{
    Rectangle *Rectangles;
    int size;
    int current_size;
} ListFigures;


ListFigures *CreateListFigure (int aSize);

void DestroyList (ListFigures * AFigures);



int AddRectangle(ListFigures * AFigures);

int printRectangle(Rectangle*theRectangle);

void printRectangleList(ListFigures *aRectangleList);


double Square(Rectangle * Figures);


int num_scanf(void);



void swap(Rectangle *var1, Rectangle *var2);

void writeList(FILE *aFile, ListFigures *AFigures);

void writeRectangle(FILE *aFile, Rectangle*theRectangle);
#endif





