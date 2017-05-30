#ifndef FIGURA_FIGURE_H
#define FIGURA_FIGURE_H
#include <stdbool.h>
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    point a;
    int side[2];
    int square;
} square;
void MakeSquare(square *ptr);
int Squareof(square s);
//void destroyFigure(square *s);
void PrintFigures(square ptr[],int k);
bool JSON(square *ptr, int n, char *filename);
#endif //FIGURA_FIGURE_H
