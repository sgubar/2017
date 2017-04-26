#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
double sideof(point A,point B){
    int dx;
    int dy;
    if(A.x >= B.x){
        dx = A.x - B.x;
    }
    else{
        dx = B.x - A.x;
    }
    if(A.y >= B.y){
        dy = A.y - B.y;
    }
    else{
        dy = B.y - A.y;
    }
    double side = sqrt((pow(dx,2)+pow(dy,2)));
    return side;
}
void MakeSquare(square *ptr, int n){
    for (int i = 0; i < 3; ++i) {
        printf("Please give coordinates of dot, axis:\nx: ");
        scanf("%i", &ptr->->x);
        printf("y: ");
        scanf("%i", &ptr->->->y);
    }
    for (int k = 0; k < 3; ++k) {
        ptr->side[k] = sideof(ptr->a[k], ptr->a[k+1]);
    }
    ptr->side[3] = sideof(ptr->a[3], ptr->a[0]);
}
void squareof(square *s){
    double sp = (s->side[0]+s->side[1]+s->side[2]+s->side[3])/2;
    double sqr = sqrt((sp-s->side[0])*(sp-s->side[1])*(sp-s->side[2])*(sp-s->side[3]));
    s->square = sqr;
}
void destroyFigure(square *s){
    if(s != NULL){
        free(s);
    }
}