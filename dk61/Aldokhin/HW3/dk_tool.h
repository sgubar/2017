#include <stdio.h>
#include <malloc.h>


typedef struct coordinates
{
    float x_coor;
    float y_coor;
}DK_coor;

typedef struct st_triangle
{
    DK_coor A_Vertex;
    DK_coor B_Vertex;
    DK_coor C_Vertex;
}triangle_str;

float calculate(DK_coor RCTriangle0, DK_coor RCTriangle1, DK_coor RCTriangle2);

void read_coor(DK_coor *rTriangle, char index, int i);
//void read_coor(triangle_str *rTriangle, char dindex, int i);

void print_triangl(DK_coor *rTriangle, char dindex, int dnumber);

void write_dot(FILE *aFile, DK_coor dArray, char index);

void write_triangle(FILE *aFile, triangle_str dTriangle, int index, int allsize);

void Write_all(FILE *File_main, int long_array, triangle_str *Triangle);