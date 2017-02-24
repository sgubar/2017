//
// Created by maksi on 2/24/2017.
//

#include <dshow.h>
#include "stdio.h"
#include "dk_tool.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"
#include "memory.h"

DK_coor *CreateCoor(int Size_c)
{
    DK_coor *Triangle = (DK_coor *) malloc(Size_c * sizeof(DK_coor));
    if(NULL != Triangle)
    {
        memset(Triangle, 0, Size_c * sizeof(DK_coor));


    }

    return Triangle;
}


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

void import(DK_coor *rTriangle)
{
    if (NULL != rTriangle) {
        char mas[3] = {'A', 'B', 'C'};
        for (int i = 0; i < 3; ++i) {
            printf("Please enter dot %c (-100000.000; 100000.000)", mas[i]);
            rTriangle[i].x_coor = read_tru(-100000.000, 100000.000);
            rTriangle[i].y_coor = read_tru(-100000.000, 100000.000);
        }
    }
}

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