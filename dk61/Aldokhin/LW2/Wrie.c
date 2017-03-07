//
// Created by maksi on 2/27/2017.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "Write.h"

void makefile(FILE *tabl)
{
//    printf("Please enter a name file(max long 50 elements):");
//    char *name;
//    name = malloc(56*sizeof(char));
//    fgets(*name, 51, stdin);
//    strcat(*name, ".json");
      tabl=fopen("11.json", "w+");
//    free(*name);
    return;
}

void closefile(FILE *d_f_save)
{
    fclose(d_f_save);
    return;
}

void make_heder_file(FILE *d_f_save)
{
    fprintf(d_f_save, "ID;P\n");
    fprintf(d_f_save, "C;Y1;X2;K\"initial mass\"\n");
    fprintf(d_f_save, "C;Y1;X3;K\"sort_bubble\"\n");
    fprintf(d_f_save, "C;Y1;X4;K\"sort selection\"\n");
    fprintf(d_f_save, "C;Y1;X5;K\"sort insert\"\n");
    fprintf(d_f_save, "C;Y1;X6;K\"sort Shell\"\n");
    fprintf(d_f_save, "C;Y1;X7;K\"sort Quick Sort\"\n");
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