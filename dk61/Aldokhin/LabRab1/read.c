//
// Created by maksi on 2/20/2017.
//
#include "stdio.h"
#include "malloc.h"

#include "tools.h"

int read_tru(int min_s, int max_s)
{
    int sc_sym, t;
    do
    {
        t=scanf("%d",&sc_sym);
        fflush(stdin);
        if(t!=1 || sc_sym<min_s || sc_sym>max_s) printf("%s","Invalid input. Try again.\n");
    }
    while(t!=1 || sc_sym<min_s || sc_sym>max_s);
    return sc_sym;
}

int* scan_data()
{
    int *id;
    id=(int*) malloc (3* sizeof(int));
    printf("Read A(-2000, 2000):\n");
    *(id)=read_tru(-2000, 2000);
    printf("Read B(0, 100):\n");
    *(id+1)=read_tru(0, 100);
    printf("Read C(-2000, 2000):\n");
    *(id+2)=read_tru(-2000, 2000);
    return id;
}

