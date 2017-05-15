#include <stdio.h>
#include <stdlib.h>
#include "figure.h"
int main() {
    int n;
    printf("Quantity of figures\n");
    square *ptr = (square*) malloc(sizeof(square)*n);
    MakeSquare(ptr,n);
    for (int i = 0; i < n; ++i) {
        &ptr[i]->square = Squareof(ptr[i].side[1],ptr[i].side[2]);
    }
    for (int k = 0; k < n; ++k) {
        printf("Square %i with starting point(%i,%i), sides %i, %i and square %i",k,ptr[k]->a.x,ptr[k]->a.y,ptr[k].side[1],ptr[k].side[2],ptr[k].square);
    }
    printf("Let's clean it!");
    for (int j = 0; j < n; ++j) {
        destroyFigure(&ptr[j]);
    }
    return 0;
}