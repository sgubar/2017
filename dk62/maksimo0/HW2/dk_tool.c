//
// Created by Max on 28.03.2017.
//

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

SpskOfTrK *StvorennyaSpsK(int RzmR)
{
    SpskOfTrK *TagSpskOfTrK=(SpskOfTrK *)malloc(sizeof(SpskOfTrK));      //Резервування памяті під трикутники
    if(TagSpskOfTrK!=NULL)                                           
    {
        TagSpskOfTrK->TrK=(Trykutnyk *)malloc(RzmR*(sizeof(Trykutnyk))); //Резервування памяті під точки
        TagSpskOfTrK->CurrentTrK=0;
        TagSpskOfTrK->MaxKilkTrK=RzmR;
    }
    return TagSpskOfTrK;
}

int addDani(SpskOfTrK *TagSpskOfTrK, int X1, int Y1, int X2, int Y2, int X3, int Y3)  //Функція введення даних
{
    if(TagSpskOfTrK->CurrentTrK<TagSpskOfTrK->MaxKilkTrK)
    {
        Trykutnyk *TrK=&(TagSpskOfTrK->TrK[TagSpskOfTrK->CurrentTrK]);  
        if (TrK!=NULL)
        {
            TrK->Tochka_A=(Tochka *)malloc(sizeof(Tochka));
            TrK->Tochka_B=(Tochka *)malloc(sizeof(Tochka));             //Резервування памяті під координати
            TrK->Tochka_C=(Tochka *)malloc(sizeof(Tochka));
            TrK->Tochka_A->Koordinata_X=X1;
            TrK->Tochka_A->Koordinata_Y=Y1;
            TrK->Tochka_B->Koordinata_X=X2;
            TrK->Tochka_B->Koordinata_Y=Y2;
            TrK->Tochka_C->Koordinata_X=X3;
            TrK->Tochka_C->Koordinata_Y=Y3;
            TrK->Ploscha=ObchislennyaPloschi(TrK);
            TagSpskOfTrK->CurrentTrK++;

        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

void Vidalennya(SpskOfTrK *TagSpskOfTrK)  //Функція очищення виділеної памяті
{
    if(TagSpskOfTrK!=NULL)
    {
        if(TagSpskOfTrK->TrK!=NULL)
        {
            for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
            {
                Trykutnyk *TrK=&(TagSpskOfTrK->TrK[i]);
                if (TrK->Tochka_A!=NULL&&TrK->Tochka_B!=NULL&&TrK->Tochka_C!= NULL)
                {
                    free(TrK->Tochka_A);
                    free(TrK->Tochka_B);
                    free(TrK->Tochka_C);
                }
            }
            free(TagSpskOfTrK->TrK);
        }
        free(TagSpskOfTrK);
    }
}


int ObchislennyaPloschi(Trykutnyk *TrK)  //Функція обчислення площі трикутника
{
    int ploscha=abs((TrK->Tochka_A->Koordinata_X-TrK->Tochka_C->Koordinata_X)*(TrK->Tochka_B->Koordinata_Y-TrK->Tochka_C->Koordinata_Y)-(TrK->Tochka_B->Koordinata_X-TrK->Tochka_C->Koordinata_X)*(TrK->Tochka_A->Koordinata_Y-TrK->Tochka_C->Koordinata_Y));
    return ploscha;
}

void Print(SpskOfTrK *TagSpskOfTrK)   //Функція виведення списку трикутників
{
    for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
    {
    Trykutnyk *TrK=&(TagSpskOfTrK->TrK[i]);
        printf("Trykutnuk #%d:\n", i);
        printf("Tochka A={%d,%d}\n", TrK->Tochka_A->Koordinata_X, TrK->Tochka_A->Koordinata_Y);
        printf("Tochka B={%d,%d}\n", TrK->Tochka_B->Koordinata_X, TrK->Tochka_B->Koordinata_Y);
        printf("Tochka C={%d,%d}\n", TrK->Tochka_C->Koordinata_X, TrK->Tochka_C->Koordinata_Y);
        printf("Ploscha=%d\n", TrK->Ploscha);
    }
}
