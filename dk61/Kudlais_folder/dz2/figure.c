#include <stdio.h>
#include <stdlib.h>
#include "figure.h"
void MakeSquare(square *ptr, int n){
    printf("Please teke the coordinates of A (lower left point)\nX:\n");
    scanf("%d",&ptr->a.x);
    printf("Y:\n");
    scanf("%d",&ptr->a.y);
    printf("side a (AB or CD)  = \n");
    scanf("%d",&ptr->side[0]);
    while(ptr->side[0] < 0){
        printf("side can not be less than 0\n");
        scanf("%d",&ptr->side[0]);
    }
    printf("side b (BC or AD) = \n");
    scanf("%d",&ptr->side[1]);
    while(ptr->side[1] < 0){
        printf("side can not be less than 0\n");
        scanf("%d",&ptr->side[1]);
    }
}
int Squareof(square s){
    return s.side[0]*s.side[1];
}
void destroyFigure(square *s){
    if(s != NULL){
        free(s);
    }
}
void PrintFigures(square ptr[],int n) {
    for (int k = 0; k < n; ++k) {
        printf("Square %i with starting point(%i,%i), sides %i, %i and square %i\n",k+1,ptr[k].a.x,ptr[k].a.y,ptr[k].side[0],ptr[k].side[1],ptr[k].square);
    }
}
