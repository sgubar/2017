#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "dk_tool.h"

void swap(int *a, int *b);

void generation(int *darray, int dsize)
{
    int i;

    for (i = 0; i < dsize ; ++i)
    {
        *(darray+i)=rand() % 10000;
    }
    return;
}

void bubbleSort(int *darray, int dsize)
{
    int i,j;

    for (i = 0; i < dsize-1; ++i) {

        for (j = 0; j < dsize-i-1; ++j) {

            if(*(darray+j)>*(darray+j+1))
            {
                swap((darray+j),(darray+j+1));
            }
        }
    }
    return;
}

void selectionSort(int *darray, int dsize)
{
    int temp;
    int i,j;
    for (i = 0; i < dsize-1; i++) {
        temp=i;
        for (j = i+1; j < dsize; j++) {
            if (*(darray+j)<*(darray+temp))
            {
                temp=j;
            }
        }
        swap((darray+temp), (darray+i));
    }
    return;
}

void insertSort(int *darray, int dsize)
{
    int temp;
    int prev_ind;
    int i;
    for (i = 1; i < dsize; ++i) {
        temp=*(darray+i);
        prev_ind=i-1;
        while(prev_ind>=0 && *(darray+prev_ind) >temp)
        {
            *(darray+prev_ind+1) = *(darray+prev_ind);
            *(darray+prev_ind) = temp;
            prev_ind--;
        }
    }
    return;
}

void shellSort(int *darray, int dsize)
{   int i, j,x;
    for (x = dsize/2; x > 0; x/=2) {
        for (i = x; i < dsize; ++i) {
            for (j = i; j >= x && *(darray+j)<=*(darray+j-x); j-=x) {
                swap((darray+j),(darray+j-x));
            }
        }
    }
    return;
}

void quickSort(int *darray, int dfirst, int dlast)
{
    int i=dfirst, j=dlast, t=(dfirst+dlast)/2, x=*(darray+t);
    do{
        while (*(darray+i)<x) i++;
        while (*(darray+j)>x) j--;

        if (i<=j)
        {
            if (*(darray+i)>*(darray+j)) swap((darray+i),(darray+j));
            i++;
            j--;
        }
    }
    while (i<=j);
    if (i < dlast)
        quickSort(darray, i, dlast);
    if (dfirst < j)
        quickSort(darray, dfirst, j);
    return;
}

int scanSize()
{
    int sc_sym, t;
    printf("Введите размер массива(0-10000):\n");
    do
    {
        t=scanf("%d",&sc_sym);
        fflush(stdin);
        if(!(t!=1 || sc_sym<0 || sc_sym>100000000)) break;
        printf("%s","Неправильный ввод. Попробуйте еще раз.\n");
    }
    while(1);
    return sc_sym;
}

void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

void overstoreArray(int *array_A, int *array_B, int dsize)
{
    int i;
    for (i = 0; i < dsize; ++i) {
        *(array_B+i)=*(array_A+i);
    }
}

void makeHeaderFile(FILE *d_f_save)
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

void writeTime(FILE *d_f_save, int x, int time)
{
    fprintf(d_f_save, "C;Y2;X%x;K%i\n", x, time);
    return;
}

void makeFutterFile(FILE *d_f_save)
{
    fprintf(d_f_save, "E\n");
    return;
}

void writeInFile(FILE *d_f_save, int x, int dsize, int *d_array)
{
    int y=3;
    int i;
    for (i = 0; i < dsize; ++i, ++y) {
        fprintf(d_f_save, "C;Y%i;X%i;K%i\n", y, x, *(d_array+i));
    }
    return;
}
