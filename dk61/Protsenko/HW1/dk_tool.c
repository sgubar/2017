#include "dk_tool.h"

int GetValueWithCheck() //checking for symbols and negative values (for X (columns) and Y (rows))
{
	int check; int value;
	check = scanf("%i", &value);
	if (check != 0 & value > 0)
	{
		return value;
		
	}
	else
	{
	 fflush(stdin);	
	 printf("Error. Try again please : ");
	 check = scanf("%i", &value);
	}
}

int GetValueWithSymbolCheck() //cheking for symbols (for fill the array)
{
	int check; int value;
	check = scanf("%i", &value);
	if (check != 0)
	{
		return value;
		
	}
	else
	{
	 fflush(stdin);	
	 printf("Error. Try again please : ");
	 check = scanf("%i", &value);
	}
}

void CreateMatrix(int x, int y, int arr[x][y]) //creating and filling array //x - columns //y - rows
{
	printf("\nFill the matrix please \n");
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("Coord [%i][%i] : ", i+1, j+1);	
			arr[i][j] = GetValueWithSymbolCheck();	
		}	
	}
}


void PrintMatrix(int x, int y, int arr[x][y]) //print array //x - columns //y - rows
{
	printf("\nPrinting a matrix... \n");
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("[%2i]", arr[i][j]);
		}
	printf("\n");
	}
}

void SubstractMatrix(int x, int y, int arr[x][y], int arr2[x][y]) //determine a substaction of matrix 
{
	printf("The substraction of matrix \n");
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("[%2i]", arr[i][j]-arr2[i][j]);
		}
	printf("\n");
	}	
}
