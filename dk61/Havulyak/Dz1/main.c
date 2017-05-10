//  main.c
//  dz1 
//  Created by Stanislav Havulyak on 13/3/17.


#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(void)
{
	int x, y;

	printf("Write lines and colums");
	scanf("%i""%i", &x, &y);
	
	int **matrix1 = (int **)malloc(x*y*sizeof(int));
	int **matrix2 = (int **)malloc(x*y*sizeof(int));
	int **result = (int **)malloc(x*y*sizeof(int));
	
	create_matrixt(x, y, matrix1, matrix2);//Create matr1 and matr2;

	substraction_matrix(matrix1, matrix2, result, x, y); //matr1-matr2;
	
	free (matrix2);
	free (matrix1);
	free (result);
	
	return 0;
}

	

