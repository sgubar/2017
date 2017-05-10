//  dk_tool.c
//  dz1
//  Created by Stanislav Havulyak on 13/3/17.

#include "dk_tool.h"

int create_matrix(int *d, int *f)
{	
	int i=0;
	int j=0;
	for (i=0; i<*d; i++)
	{  																							
		for (j=0; j<*f; j++)
		{   
		    int matr1[i][j];
			printf("Element matr1 [%i][%i]: ", i+1, j+1);	   
			scanf("%i", &matr1[i][j]);				            
		}
	}
	for (i = 0; i < *d; i++)
	{        				  
		for(j = 0; j < *f; j++)
		{	
			int matr2[i][j];	   
			printf("Element matr2 [%i][%i]: ", i+1, j+1);	  
			scanf("%i", &matr2[i][j]);	
		}
	}
	int *matrx1, *matrx2;
	matrx1=matr1;
	matrx2=matr2;
}


int substraction_matrix(int *matr1, int *matr2, int *d, int *f)
{
	
	int i,j;
	int matr_otvet[i][j];
	for (i = 0; i < *d; i++){       
		for(j = 0; j < *f; j++){	 
		   matr_otvet[i][j]=(*matrx1)-(*matrx2);
		   printf("[%2i]", matr_otvet[i][j]);			
        }
    }
}
