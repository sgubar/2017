//  dk_tool.c
//  dz1
//  Created by Stanislav Havulyak on 13/3/17.

#include "dk_tool.h"

void create_matrix(int x, int y, int matr1[x][y], int matr2[x][y], int matr_otvet[x][y])
{	
	do{
		printf("Vvedite kolichestvo strok: ");
		scanf("%i", &x);
	}while(x<1);
	do{
		printf("Vvedite kolichestvo stolbtsov: ");
		scanf("%i", &y);
	}while(y<1);
	int i=0;
	int j=0;
	for (i=0; i<x; i++)
	{  																							
		for (j=0; j<y; j++)
		{ 
			printf("Element matr1 [%i][%i]: ", i+1, j+1);	   
			scanf("%i", &matr1[i][j]);				            
		}
	}
	for (i = 0; i < x; i++)
	{        				  
		for(j = 0; j < y; j++)
		{			   
			printf("Element matr2 [%i][%i]: ", i+1, j+1);	  
			scanf("%i", &matr2[i][j]);	
		}
	}
	for (i = 0; i < x; i++){       
		for(j = 0; j < y; j++){	 
		   matr_otvet[i][j]=matr1[i][j]-matr2[i][j];
		   printf("[%2i]", matr_otvet[i][j]);				      
		}
	}
}
