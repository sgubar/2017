#include "dk_tool.h"

int Transponuvannya_Matrici(int a, int b, int matr[a][b])
{
    printf("Transponovana matricya:\n");
    for(int j=0; j<b; j++)
    {
        for(int i=0; i<a; i++)
        {
            printf("%i", matr[i][j]);                       //вивід транспонованої матриці на екран
        }
        printf("\n");
    }
}
