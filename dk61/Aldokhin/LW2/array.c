//
// Created by maksi on 3/1/2017.
//

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

void swap(int *a, int *b);

void generation(int *darray, int dsize)
{
    for (int i = 0; i < dsize ; ++i)
    {
        *(darray+i)=rand() % 10000;
    }
    return;
}

void sort_bubble(int *darray, int dsize)
{
    for (int i = 0; i < dsize-1; ++i) {
        //comper two adjacent slement
        for (int j = 0; j < dsize-i-1; ++j) {
            //if they are in the wrong arder, rearrange them
            if(*(darray+j)>*(darray+j+1))
            {
                swap((darray+j),(darray+j+1));
            }
        }
    }
    return;
}

void sort_selection(int *darray, int dsize)
{
    int temp; //variable for min's
    for (int i = 0; i < dsize-1; i++) {
        temp=i; //save position
        for (int j = i+1; j < dsize; j++) {
            if (*(darray+j)<*(darray+temp))
            {
                temp=j; //save position
            }
        }
        swap((darray+temp), (darray+i));
    }
    return;
}

void sort_insert(int *darray, int dsize)
{
    int temp; // save temporary data
    int prev_ind; //previous index
    for (int i = 1; i < dsize; ++i) {
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

void sort_Shell(int *darray, int dsize)
{   int i, j;
    for (int devis = dsize/2; devis > 0; devis/=2) {
        for (i = devis; i < dsize; ++i) {
            for (j = i; j >= devis && *(darray+j)<=*(darray+j-devis); j-=devis) {
            //в обратную сторону for (j = i; j >= devis && *(darray+j)>=*(darray+j-devis); j-=devis)
                swap((darray+j),(darray+j-devis));
            }
        }
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

int scan_size()
{
    int sc_sym, t;
    printf("Please, enter the size of the array(0;10^5):\n");
    do
    {
        t=scanf("%d",&sc_sym);
        fflush(stdin);
        if(!(t!=1 || sc_sym<0 || sc_sym>1000000)) break;
        printf("%s","Invalid input. Try again.\n");
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

void overstore_array(int *array_A, int *array_B, int dsize)
{
    for (int i = 0; i < dsize; ++i) {
        *(array_B+i)=*(array_A+i);
    }
}