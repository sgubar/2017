//
// Created by maksi on 3/28/2017.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "Write.h"



void make_heder_file(FILE *d_f_save)
{
    fprintf(d_f_save, "ID;P\n");
    fprintf(d_f_save, "C;Y1;X2;K\"Start array\"\n");
    fprintf(d_f_save, "C;Y1;X3;K\"sort Quick Sort\"\n");
    fprintf(d_f_save, "C;Y2;X1;K\"Time\"\n");
    return;
}

void Write_time(FILE *d_f_save, int x, int time)
{
    fprintf(d_f_save, "C;Y2;X%x;K%i\n", x, time);
    return;
}

void make_futter_file(FILE *d_f_save)
{
    fprintf(d_f_save, "E\n");
    return;
}

void Write_in_file(FILE *d_f_save, int x, int dsize, int *d_array)
{
    //C;Y1;X1;K"Row 1"

    int y=3; //line pass for the column names
    for (int i = 0; i < dsize; ++i, ++y) {
        fprintf(d_f_save, "C;Y%i;X%i;K%i\n", y, x, *(d_array+i));
    }
    return;
}