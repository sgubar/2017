#ifndef FIGURA_FIGURE_H
#define FIGURA_FIGURE_H
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    point a;
    int side[2];
    double square;
} square;
void MakeSquare(square *ptr, int n);
void squareof(square *s);
void destroyFigure(square *s);
#endif //FIGURA_FIGURE_H
