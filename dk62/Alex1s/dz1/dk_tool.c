#include <stdio.h>

int enter_value()
{
int lines = 0;
do{
	scanf("%i", &lines);
}while(lines<2);
return lines;
}


//--------------------------------------------------------------------------------------------------------------------------------


void write_matrix(int lines, int columns, float matrix[lines][columns])
{
int i = 0, j = 0;
for(i = 0; i < lines; i++)
for(j = 0; j < columns; j++) {
printf("Enter variable[%i][%i]: ", i, j);   //[i][j] for better meaning position of elements
scanf("%f", &matrix[i][j]);}
}


//--------------------------------------------------------------------------------------------------------------------------------


void mnoj_matrix(float coef, int lines, int columns, float matrix[lines][columns])
{
printf("Enter coefficient of result matrix: ");
scanf("%f", &coef);
int i = 0, j = 0;
for(i = 0; i < lines; i++)
for(j = 0; j < columns; j++)
matrix[i][j] *= coef;        //matrix[i][j] = matrix[i][j]*coef;
}


//--------------------------------------------------------------------------------------------------------------------------------


void read_matrix(int lines, int columns, float matrix[lines][columns])
{
int i = 0, j = 0;
for(i = 0; i < lines; i++){
for(j = 0; j < columns; j++)
printf("%.3f ", matrix[i][j]);
printf("\n");}
printf("\n");
}


//--------------------------------------------------------------------------------------------------------------------------------


