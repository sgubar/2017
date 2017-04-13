#include <stdio.h>

int enter_value()
{
int l;
do{
scanf("%i", &l);
}while(l < 2);

return l;
}

//-----------------------------------------------------------------------------------------------------------

void write_matrix(int lines, int columns, float **matrix)
{
int i, j;
for(i = 0; i < lines; i++)
	for(j = 0; j < columns; j++)
		{
		printf("Enter variable[%i][%i]: ", i, j); //[i][j] for better meaning position of elements
		scanf("%f", &matrix[i][j]);
		}
}

//-----------------------------------------------------------------------------------------------------------

void mnoj_matrix(float coef, int lines, int columns, float **matrix)
{
printf("Enter coefficient of result matrix: ");
scanf("%f", &coef);
int i, j;

for(i = 0; i < lines; i++)
	for(j = 0; j < columns; j++)
		matrix[i][j] *= coef;
}

//-----------------------------------------------------------------------------------------------------------

void read_matrix(int lines, int columns, float **matrix)
{
int i, j;
for(i = 0; i < lines; i++)
	{
	for(j = 0; j < columns; j++)
		printf("%.3f ", matrix[i][j]);
	printf("\n");
	}
printf("\n");
}

//-----------------------------------------------------------------------------------------------------------
