#include <stdio.h>

#include "dk_tool.h"

int main() {
    int x, y, k;
    printf("Matrix size(x, y)");
    scanf("%i", &x);
    scanf("%i", &y);
    printf("Matrix size (%i, %i)\n Enter the matrix:\n", x, y);
    int mas[x][y];
    read_mas(x, y, mas);
    print_mas(x, y, mas);
    int mas_n[x][y];
    save_mas(x, y, mas, mas_n);
    printf("Enter multiplier: ");
    scanf("%i", &k);
    multi_mas(x, y, mas_n, k);
    print_mas(x, y, mas_n);
}