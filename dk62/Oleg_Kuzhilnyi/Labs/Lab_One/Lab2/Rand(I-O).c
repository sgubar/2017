//
//  Random.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

void Random(int *MassOfNumbers,int aSize)
{
    for(int i = 0; i < aSize; i++)
    {
        MassOfNumbers[i] = rand() %100;
    }
}

void Input(FILE *aFileWrite,int *MassOfNumbers,int aSize)
{
    for(int i = 0; i < aSize; i++)
    {
        fprintf(aFileWrite,"%i ",MassOfNumbers[i]);
    }

    fflush(aFileWrite);
    fclose(aFileWrite);
}

void Output(FILE *aFileRead,int *MassOfNumbers,int aSize)
{
   if(aFileRead != NULL)
   {
    for(int i = 0; i < aSize; i++)
    {
        fscanf(aFileRead,"%i ",&MassOfNumbers[i]);
    }
   }
    fflush(aFileRead);
    fclose(aFileRead);
}
