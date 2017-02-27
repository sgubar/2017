#include <stdio.h>

#include "dk_tool.h"

int main() {
    int x, y, k;
    printf("Matrix size(x(0, 100), y(0, 100))");
    x=read_tru(0,100);
    y=read_tru(0,100);
    printf("Matrix size (%i, %i)\n Enter the matrix (-1000, 1000):\n", x, y);
    int mas[x][y];
    read_mas(x, y, mas);
    print_mas(x, y, mas);
    int mas_n[x][y];
    save_mas(x, y, mas, mas_n);
    printf("Enter multiplier(-1000,1000): ");
    k=read_tru(-1000,1000);
    //scanf("%i", &k);
    multi_mas(x, y, mas_n, k);
    print_mas(x, y, mas_n);
}