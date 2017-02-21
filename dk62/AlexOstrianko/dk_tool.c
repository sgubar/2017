#include "dk_tool.h"
#include <stdio.h>

void printfunction(int height, int width,int matr[height][width])
{
	int i,n;
    for( i=0;i<height;i++)
    {
        for( n=0;n<width;n++)
        {
            printf("%i",matr[i][n]);
        }
        printf("\n");
    }
}

void minus(int height, int width,int matr1[height][width],int matr2[height][width],int minusmatr[height][width])
{
	int i,n;
    for( i=0;i<height;i++)
    {
        for( n=0;n<width;n++)
        {
            minusmatr[i][n]=matr1[i][n]-matr2[i][n];
        }
    }
}
