#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "figure.h"
void MakeSquare(square *ptr){
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
/*void destroyFigure(square *s){
    if(s != NULL){
        free((void*)s->square);
        free((void*)s->a.x);
        free((void*)s->a.y);
        free((void*)s->side[0]);
        free((void*)s->side[1]);

    }
}*/
void PrintFigures(square ptr[],int n) {
    for (int k = 0; k < n; ++k) {
        printf("Square %i with starting point(%i,%i), sides %i, %i and square %i\n",k+1,ptr[k].a.x,ptr[k].a.y,ptr[k].side[0],ptr[k].side[1],ptr[k].square);
    }
}
bool JSON(square *ptr, int n, char *filename){
    FILE *file = fopen(filename,"a+");
    if(file != NULL) {
        fprintf(file,"{\n \"Number_of_figures\" : %i\n \"Squares\":\n\t[\n",n);
        fflush(file);
        for (int i = 0; i < n; ++i) {
            fprintf(file,"\t {\n\t \"NumberOfFigure\" : %i,\n\t \"Square\" : %i,\n\t \"StartPoint\" : {\"X\" : %i,\"Y\" : %i},\n\t \"SideA\" : %i,\n\t \"SideB\" : %i,\n\t}\n",i+1,ptr[i].square,ptr[i].a.x,ptr[i].a.y,ptr[i].side[0],ptr[i].side[1]);
            if(i == n - 1)
                fprintf(file,",");
            fflush(file);
        }
        fprintf(file, "\t]\n}");
        fflush(file);
    } else
        return false;
    fclose(file);
    return true;
}