#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
void MakeSquare(square *ptr, int n){
    printf("Please teke the coordinates of A (lower left point)\nX:");
    scanf("%d",&ptr->a.x);
    printf("Y:\n");
    scanf("%d",&ptr->a.y);
    printf("side a (AB or CD)  = ");
    scanf("%d",&ptr->side[1]);
    while(ptr.side[1] < 0){
        printf("side can not be less than 0\n");
        scanf("%d",&ptr->side[1]);
    }
    printf("side b (BC or AD) = ");
    scnaf("%d",&ptr->side[2]);
    while(ptr.side[2] < 0){
        printf("side can not be less than 0\n");
        scanf("%d",&ptr->side[2]);
    }
}
int Squareof(int a, int b){
    return a*b;
}
void destroyFigure(square *s){
    if(s != NULL){
        free(s->a.x);
        free(s->a.y);
        free(s->side[1]);
        free(s->side[2]);
        free(s->square);
    }
}
