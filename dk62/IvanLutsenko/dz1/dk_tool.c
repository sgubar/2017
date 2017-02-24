#include "dk_tool.h"

void init(const int n, const int m) 
{
	matr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int)*m);
}

void fill(const int n, const int m) 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = (i + 1) * (j + 2);
}

void product(const int n, const int m, const int p) 
{
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			matr[i][j] *= p;
}

void delete(const int n, const int m) 
{
	for (int i = 0; i < n; i++)
		free(matr[i]);
	free(matr);
}

void show(const int n, const int m) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
			printf("%i ", matr[i][j]);
		printf("\n");
	}
}
