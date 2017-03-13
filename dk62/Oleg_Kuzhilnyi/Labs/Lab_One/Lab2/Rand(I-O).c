//
//  Random.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

void Random(int *MassOfNumber)
{
    for(int i = 0; i < ELEMENTS; i++)
    {
        MassOfNumber[i] = rand() %100;
    }
}

void Input(FILE *aFileWrite,int *MassOfNumber)
{
    for(int i = 0; i < ELEMENTS; i++)
    {
        fprintf(aFileWrite,"%i ",MassOfNumber[i]);
    }

    fflush(aFileWrite);
    fclose(aFileWrite);
}

void Output(FILE *aFileRead,int *MassOfNumber)
{
   if(aFileRead != NULL)
   {
    for(int i = 0; i < ELEMENTS; i++)
    {
        fscanf(aFileRead,"%i ",&MassOfNumber[i]);
    }
   }
    fflush(aFileRead);
    fclose(aFileRead);
}
