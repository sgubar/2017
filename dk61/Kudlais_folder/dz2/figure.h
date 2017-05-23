#ifndef FIGURA_FIGURE_H
#define FIGURA_FIGURE_H
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    point a;
    int side[2];
    int square;
} square;
void MakeSquare(square *ptr, int n);
int Squareof(square s);
void destroyFigure(square *s);
void PrintFigures(square ptr[],int k);
#endif //FIGURA_FIGURE_H
