//
// Created by maksi on 4/9/2017.
//

//
// Created by maksi on 3/5/2017.
//


#include <dshow.h>
#include <stdio.h>
#include "dk_tool.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

float read_tru(float min_s, float max_s);

float read_tru(float min_s, float max_s)
{
    float sc_sym;
    int t;
    do
    {
        t=scanf("%f",&sc_sym);
        fflush(stdin);
        if(t!=1 || sc_sym<min_s || sc_sym>max_s) printf("%s","Invalid input. Try again.\n");
            else return sc_sym;
    }
    while(1);
}

void read_coor(DK_coor *rTriangle, char dindex, int i)
{
    printf("Please enter tgiangle number %i dot %c  (-100000.000; 100000.000)\n", i+1, dindex);
    rTriangle->x_coor = read_tru(-100000.000, 100000.000);
    rTriangle->y_coor = read_tru(-100000.000, 100000.000);
    return;
}

void print_triangl(DK_coor *rTriangle, char dindex, int dnumber)
{
    printf("Triangl: %i Vertex: %c (%f ; %f)\n",dnumber+1,dindex, rTriangle->x_coor, rTriangle->y_coor);
    return;
}


//calculate area triangl
float calculate(DK_coor RCTriangle0, DK_coor RCTriangle1, DK_coor RCTriangle2)
{
    float rez=((RCTriangle0.x_coor-RCTriangle2.x_coor)*(RCTriangle1.y_coor - RCTriangle2.y_coor) - (RCTriangle1.x_coor - RCTriangle2.x_coor) * (RCTriangle1.y_coor - RCTriangle2.y_coor))/(float)2;
    if(rez<0)rez = rez * (-1);
    return rez;
}
/*"Triangl" : {
"Area" : 1.500000,
"A" : {
{
"X" : 2.000000,
"Y" : 5.000000,
},
},
"B" : {
{
"X" : 2.000000,
"Y" : 5.000000,
},
},
"C" : {
{
"X" : 2.000000,
"Y" : 5.000000,
},
},
}*/
void write_dot(FILE *aFile, DK_coor dArray, char index)
{
    fprintf(aFile, "\"%c\" : {\n", index);

    fprintf(aFile, "\"X\" : %f,\n", dArray.x_coor);

    fprintf(aFile, "\"Y\" : %f\n", dArray.y_coor);

    if (index=='C')  fprintf (aFile, "}\n");
    else fprintf (aFile, "},\n");
    //fprintf (aFile, "}\n");
}

void write_triangle(FILE *aFile, triangle_str dTriangle, int index, int allsize)
{
    fprintf(aFile, "\"Triangle number %i\" : ", index+1);
    fprintf(aFile, "{\n");

    write_dot(aFile, dTriangle.A_Vertex, 'A');
    write_dot(aFile, dTriangle.B_Vertex, 'B');
    write_dot(aFile, dTriangle.C_Vertex, 'C');

    if (index==(allsize-1))  fprintf (aFile, "}\n");
    else fprintf (aFile, "},\n");
}


void Write_all(FILE *File_main, int long_array, triangle_str *Triangle)
{
    fprintf (File_main, "{\n");
    fprintf(File_main, "\"Triangls\" : [\n");
    for (int i = 0; i < long_array; ++i) {
        write_triangle(File_main, Triangle[i], i, long_array);
    }

    fprintf (File_main, "]\n}\n");
}

void overstore_array(Square_Triangle *array_A, Square_Triangle *array_B, int dsize)
{
    for (int i = 0; i < dsize; ++i) {
        *(array_B+i)=*(array_A+i);
    }
}

void lion_search(Square_Triangle *darray, float elem_sercth, int dsize, triangle_str *dTriangle)
{
    for (int i = 0; i < dsize || darray[i].Square>elem_sercth; ++i) {
        if (darray[i].Square == elem_sercth)
        {
            printf("Element search: %i\n", i);
            print_triangl(&dTriangle[i].A_Vertex, 'A', i);
            print_triangl(&dTriangle[i].B_Vertex, 'B', i);
            print_triangl(&dTriangle[i].C_Vertex, 'C', i);
            return;
        }
    }
    printf("No have element\n");
    return;
}

char scanf_char()
{
    char sc_char;
    int t;
    do
    {
        t=scanf("%c",&sc_char);
        fflush(stdin);
//        printf("%i %c\n", t, sc_char);
//        if(sc_char != 'N' || sc_char != 'Y') printf("%s","Invalid input. Try again.\n");
//        else return sc_char;
        switch (sc_char)
        {
            case 'N': return sc_char;
            case 'Y': return sc_char;
        }
        printf("%s","Invalid input. Try again.\n");
    }
    while(1);
}