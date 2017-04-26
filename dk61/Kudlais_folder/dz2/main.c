#include <stdio.h>
#include <stdlib.h>
#include "figure.h"
int main() {
    int n;
    printf("Quantity of figures\n");
    square *ptr = (square*) malloc(sizeof(square)*n);
    MakeSquare(ptr,n);
    for (int i = 0; i < n; ++i) {
        squareof(&ptr[i]);
        printf("%.2f",ptr[i].square);
    }
    printf("Let's clean it!");
    for (int j = 0; j < n; ++j) {
        destroyFigure(&ptr[j]);
    }
    return 0;
}