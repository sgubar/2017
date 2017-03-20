#include <stdio.h>
#include "dk_tool.h"
int main(int argc, char *argv[])
{
int row;
int col;
int i;
int j;
static int first_matrix[10][10];
static int second_matrix[20][20];

printf("Dimension of matrix:\n");
scanf("%i %i", &row, &col);

if (row < 0 || col <= 0) {
printf("Error\n");
}

display_first_matrix(row, col, first_matrix);

display_second_matrix(row, col, second_matrix);

sum(row, col, first_matrix, second_matrix);

}
