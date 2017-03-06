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
    }
    while(t!=1 || sc_sym<min_s || sc_sym>max_s);
    return sc_sym;
}

void read_coor(DK_coor *rTriangle)
{
    if (NULL != rTriangle) {
        char mas[3] = {'A', 'B', 'C'};
        for (int i = 0; i < 3; ++i) {
            printf("Please enter dot %c (-100000.000; 100000.000)\n", mas[i]);
            rTriangle[i].x_coor = read_tru(-100000.000, 100000.000);
            rTriangle[i].y_coor = read_tru(-100000.000, 100000.000);
        }
    }
}
//calculate area triangl
float calculate(DK_coor *RCTriangle)
{
    char mas[3] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; ++i) {
        printf("%c (%f ; %f)\n",mas[i], RCTriangle[i].x_coor, RCTriangle[i].y_coor);
    }
    float rez=(((RCTriangle+0)->x_coor-(RCTriangle+2)->x_coor)*((RCTriangle+1)->y_coor - (RCTriangle+2)->y_coor) - ((RCTriangle+1)->x_coor - (RCTriangle+2)->x_coor) * ((RCTriangle+1)->y_coor - (RCTriangle+2)->y_coor))/(float)2;
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
void write_Triangl(FILE *aFile, DK_coor *dArray, float S)
{
    char index[3] = {'A', 'B', 'C'};


    fprintf(aFile, "\"Triangl\" : ");

    fprintf(aFile, "{\n");

    fprintf(aFile, "\"Area\" : %f,\n", S);

    for (int i = 0; i < 3; ++i) {
        fprintf(aFile, "\"%c\" : {\n", index[i]);


        fprintf(aFile, "{\n");

        fprintf(aFile, "\"X\" : %f,\n", dArray[1].x_coor);

        fprintf(aFile, "\"Y\" : %f,\n", dArray[1].y_coor);

        fprintf(aFile, "},\n");

        fprintf(aFile, "},\n");
    }

    fprintf (aFile, "}");
}