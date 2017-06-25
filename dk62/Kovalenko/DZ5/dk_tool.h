#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>
#include <string.h>

typedef struct place
{
    int X;
    int Y;
}point;
typedef struct points
{
    point *A;
    point *B;
    point *C;
}triangle;

typedef struct Ttriangle
{
    triangle *Ttriangle;
    int CurrentTtriangle;
    int mtriangle;
}list;
list *create(int size);
int data(list *Tlist, int X1, int Y1, int X2, int Y2, int X3, int Y3);
void space_size(list *Tlist);
int area(triangle *Ttriangle);
void Print(list *Tlist);
void filespace (FILE *file, list *Tlist);
void trianglespace(FILE *file,triangle *Ttriangle);
void InsertionSorT(list *Tlist);
void shellSort(list *Tlist);
int linefind(list *Tlist, int aKey);

#endif
