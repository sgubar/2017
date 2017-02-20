#include "dk_tool.h"

 
int fact(int number)
{
    if (number < 0) return -1;
    int theResult = 1;
    while (number > 1)
    {
        theResult *= number;
        number--;
    }
    return theResult;
}


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


int power (int number, int power)
{
    int theResult = 1;
    while (power > 0)
    {
        theResult = theResult * number;
        power--;
    }
    return	theResult;
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

