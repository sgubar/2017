
#include <stdio.h>

//vvodi kolichestva strok
int rows_write()
{
int rows = 0;
do{
	printf("Write the number of rows here: ");
	scanf("%i", &rows);
}while(rows<2);
return rows;
}

//vvodi kolichestva stplbcov
int columns_write()
{
int columns = 0;
do{
	printf("Write the number of columns here: ");
	scanf("%i", &columns);
}while(columns<2);
return columns;
}

//zapolnenie matrici 1
int matrix1_fill(int rows, int columns, int matrix_1[rows][columns])
{
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){ 
printf("Please, fill the first matrix: ");
scanf("%i", &matrix_1[row1][col1]);}
}
}
//vivod na ekran matrici 1
int matrix1_print(int rows, int columns, int matrix_1[rows][columns]){
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){
printf("%i ", matrix_1[row1][col1]);
}
printf("\n");
}
}

//zapolnenie matrici 2
int matrix2_fill(int rows, int columns, int matrix_2[rows][columns])
{
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){ 
printf("Please, fill the second matrix: ");
scanf("%i", &matrix_2[row1][col1]);}
}
}

//vivod na ekran matrici 2
int matrix2_print(int rows, int columns, int matrix_2[rows][columns]){
int row1 = 0, col1 = 0;
for(row1 = 0; row1 < rows; row1++){
for(col1 = 0; col1 < columns; col1++){ 
printf("%i ", matrix_2[row1][col1]);
}
printf("\n");
}
}

//summa dvuh matric
void summ(int rows, int columns, int matrix_1[rows][columns], int matrix_2[rows][columns])
{
	printf("The result of the sum\n");
	int row = 0, col = 0;
	int sum[row][col];
for (row=0; row<rows; row++) {
for (col=0; col<columns; col++) {
sum[row][col] = matrix_1[row][col] + matrix_2[row][col]; //summa kashdogo elementa
printf("[%d]", sum[row][col]);
}
printf ("\n");
}
}
