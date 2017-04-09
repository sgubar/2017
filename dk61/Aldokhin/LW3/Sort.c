//
// Created by maksi on 4/9/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b);

void generation(int *darray, int dsize)
{
    srand (time(NULL));
    for (int i = 0; i < dsize ; ++i)
    {
        *(darray+i)=rand() % 10000;
    }
    return;
}

void sort_QuickSort(int *darray, int dfirst, int dlast)
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
        sort_QuickSort(darray, i, dlast);
    if (dfirst < j)
        sort_QuickSort(darray, dfirst, j);
    return;
}

void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

int scan_size(char index[100])
{
    int sc_sym, t;
    printf("Please, enter %s(0;10^5):\n", index);
    do
    {
        t=scanf("%d",&sc_sym);
        fflush(stdin);
        if(!(t!=1 || sc_sym<0 || sc_sym>100000000)) break;
        printf("%s","Invalid input. Try again.\n");
    }
    while(1);
    return sc_sym;
}