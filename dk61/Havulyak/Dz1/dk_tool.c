//  dk_tool.c
//  dz1
//  Created by Stanislav Havulyak on 13/3/17.

#include "dk_tool.h"

void create_matrix(int d, int f, int **matrix1, int **matrix2)
{	
	int i=0;
	int j=0;
	for (i=0; i<d; i++)
	{  																							
		for (j=0; j<f; j++)
		{   
			printf("Element matr1 [%i][%i]: ", i+1, j+1);
			scanf("%i", &matrix1[i][j]);
		}
	}
	for (i = 0; i < d; i++)
	{        				  
		for(j = 0; j < f; j++)
		{	
			int matr2[i][j];	   
			printf("Element matr2 [%i][%i]: ", i+1, j+1);	  
			scanf("%i", &matrix2[i][j]);
		}
	}
}


void substraction_matrix(int **matrx1, int **matrx2, int **result, int d, int f)
{
	
	int i,j;
	
	for (i = 0; i < d; i++){
		for(j = 0; j < f; j++){
		   result[i][j]=matrx1[i][j]-matrx2[i][j];
		   printf("[%2i]", result[i][j]);
        }
    }
}
