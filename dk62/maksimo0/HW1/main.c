//
//  main.c
//  HW1
//
//  Created by Maxim Salim on 06.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#include <stdio.h>
#include "dk_tool.h"

int main(int argc, const char * argv[])
{
    printf("Vvedit rozmiru matrici:\n");
    int a,b;
    scanf("%i%i", &a, &b);                        //зчитування кількості рядків та стовпців матриці
    int matr[a][b];
    printf("Vvedit elementi matrici:\n");
    for(int i=0; i<a; i++)
    {
        for (int j=0; j<b ; j++)
        {
            scanf("%i", &matr[i][j]);             //зчитування елементів матриці
        }
    }
    
    Transponuvannya_Matrici(a, b, matr);         //виклик функції для транспонування матриці та виводу її  на екран
    
    return 0;
}


