#include <stdio.h>
#include <malloc.h>


typedef struct coordinates
{
    float x_coor;
    float y_coor;
}DK_coor;

float calculate(DK_coor *RCTriangle);

void read_coor(DK_coor *rTriangle);

void write_Triangl(FILE *aFile, DK_coor *dArray, float S);