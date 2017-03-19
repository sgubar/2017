//
// Created by maksi on 3/19/2017.
//

#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

void swap(Square_Triangle *a, Square_Triangle *b);

void sort_bubble(Square_Triangle *darray, int dsize)
{
    for (int i = 0; i < dsize-1; ++i) {
        //comper two adjacent slement
        for (int j = 0; j < dsize-i-1; ++j) {
            //if they are in the wrong arder, rearrange them
            if((darray+j)->Square>(darray+j+1)->Square)
            {
                swap((darray+j),(darray+j+1));
            }
        }
    }
    return;
}

void sort_selection(Square_Triangle *darray, int dsize)
{
    int temp; //variable for min's
    for (int i = 0; i < dsize-1; i++) {
        temp=i; //save position
        for (int j = i+1; j < dsize; j++) {
            if ((darray+j)->Square<(darray+temp)->Square)
            {
                temp=j; //save position
            }
        }
        swap((darray+temp), (darray+i));
    }
    return;
}

void sort_insert(Square_Triangle *darray, int dsize)
{
    float temp; // save temporary data
    int ind_temp; // save temporary index
    int prev_ind; //previous index
    for (int i = 1; i < dsize; ++i) {
        temp=(darray+i)->Square;
        ind_temp=(darray+i)->index;
        prev_ind=i-1;
        while(prev_ind>=0 && (darray+prev_ind)->Square >temp)
        {
            *(darray+prev_ind+1) = *(darray+prev_ind);
            (darray+prev_ind)->Square = temp;
            (darray+prev_ind)->index = ind_temp;
            prev_ind--;
        }
    }
    return;
}


void swap(Square_Triangle *a, Square_Triangle *b)
{
    Square_Triangle c=*a;
    *a=*b;
    *b=c;
}

void sort_Shell(Square_Triangle *darray, int dsize)
{   int i, j;
    for (int devis = dsize/2; devis > 0; devis/=2) {
        for (i = devis; i < dsize; ++i) {
            for (j = i; j >= devis && (darray+j)->Square<=(darray+j-devis)->Square; j-=devis) {
                //в обратную сторону for (j = i; j >= devis && *(darray+j)>=*(darray+j-devis); j-=devis)
                swap((darray+j),(darray+j-devis));
            }
        }
    }
    return;
}

void sort_QuickSort(Square_Triangle *darray, int dfirst, int dlast)
{
    int i=dfirst, j=dlast, t=(dfirst+dlast)/2, x=(darray+t)->Square;
    do{
        while ((darray+i)->Square<x) i++;
        while ((darray+j)->Square>x) j--;

        if (i<=j)
        {
            if ((darray+i)->Square>(darray+j)->Square) swap((darray+i),(darray+j));
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