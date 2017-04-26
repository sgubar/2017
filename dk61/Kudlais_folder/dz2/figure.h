#ifndef FIGURA_FIGURE_H
#define FIGURA_FIGURE_H
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    point a [4];
    int side[4];
    double square;
} square;
double sideof(point A,point B);
void MakeSquare(square *ptr, int n);
void squareof(square *s);
void destroyFigure(square *s);
#endif //FIGURA_FIGURE_H
