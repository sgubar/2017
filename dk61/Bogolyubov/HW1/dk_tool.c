
#include <stdio.h>

int rows_write()
{
int rows = 0;
do{
	printf("Write the number of rows here: ");
	scanf("%i", &rows);
}while(rows<2);
return rows;
}

int columns_write()
{
int columns = 0;
do{
	printf("Write the number of columns here: ");
	scanf("%i", &columns);
}while(columns<2);
return columns;
}

int matrix1_fill(int rows, int columns, int matrix_1[rows][columns])
{
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){ 
printf("Please, fill the first matrix: ");
scanf("%i", &matrix_1[row1][col1]);}
}
}

int matrix1_print(int rows, int columns, int matrix_1[rows][columns]){
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){
printf("%i ", matrix_1[row1][col1]);
}
printf("\n");
}
}

int matrix2_fill(int rows, int columns, int matrix_2[rows][columns])
{
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){ 
printf("Please, fill the second matrix: ");
scanf("%i", &matrix_2[row1][col1]);}
}
}

int matrix2_print(int rows, int columns, int matrix_2[rows][columns]){
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){
printf("%i ", matrix_2[row1][col1]);
}
printf("\n");
}
}

void summ(int rows, int columns, int matrix_1[rows][columns], int matrix_2[rows][columns])
{
	printf("The result of the sum\n");
	int row = 0, col = 0;
	int sum[row][col];
for (row=0; row<rows; row++) {
for (col=0; col<columns; col++) {
sum[row][col] = matrix_1[row][col] + matrix_2[row][col];
printf("[%d]", sum[row][col]);
}
printf ("\n");
}
}
