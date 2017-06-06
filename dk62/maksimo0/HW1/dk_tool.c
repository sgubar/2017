//
//  dk_tool.c
//  HW1
//
//  Created by Maxim Salim on 06.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#include "dk_tool.h"

int Transponuvannya_Matrici(int a, int b, int matr[a][b])
{
    int aMatr[a][b];
    for(int j=0; j<b; j++)
    {
        for(int i=0; i<a; i++)
        {
            aMatr[j][i]=matr[i][j];
            printf("%d", aMatr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
