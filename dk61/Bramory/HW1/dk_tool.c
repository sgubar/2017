#include "dk_tool.h"
#include <stdio.h>
 
void transp(int x, int y, int transp_matr[y][x], int matr[x][y] )
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			{
				transp_matr[j][i] = matr[i][j];
			}
	}
}

int num_scan( void )
{
	int num = 0, proof = 0;
    do
    {
        proof = scanf("%d", &num);
        fflush(stdin);
      if(proof != 1)  printf("Incorrect input, try again");
    }
    while (proof != 1);
return num;
}

void read_matr(int x, int y, int matr[x][y])
{
	int i, j;
	  for(i = 0; i < x ; i++)
    {
        for(j = 0; j < y ; j++)
        {
            matr[i][j] = num_scan();
        }
    }
}


void print_matr(int x, int y, int matr[x][y])
{
	int i, j;
    for(i = 0; i < x ; i++)
    {
        for(j = 0; j < y ; j++)
        {
            printf("%i ", matr[i][j]);
        }
        printf("\n");
    }
}

