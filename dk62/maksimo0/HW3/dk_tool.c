//
// Created by Max on 04.04.2017.
//

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

SpskOfTrK *StvorennyaSpsK(int RzmR)
{
    SpskOfTrK *TagSpskOfTrK=(SpskOfTrK *)malloc(sizeof(SpskOfTrK));
    if(TagSpskOfTrK!=NULL)
    {
        TagSpskOfTrK->TrK=(Trykutnyk *)malloc(RzmR*(sizeof(Trykutnyk)));
        TagSpskOfTrK->CurrentTrK=0;
        TagSpskOfTrK->MaxKilkTrK=RzmR;
    }
    return TagSpskOfTrK;
}

int addDani(SpskOfTrK *TagSpskOfTrK, int X1, int Y1, int X2, int Y2, int X3, int Y3)
{
    if(TagSpskOfTrK->CurrentTrK<TagSpskOfTrK->MaxKilkTrK)
    {
        Trykutnyk *TrK=&(TagSpskOfTrK->TrK[TagSpskOfTrK->CurrentTrK]);
        if (TrK!=NULL)
        {
            TrK->Tochka_A=(Tochka *)malloc(sizeof(Tochka));
            TrK->Tochka_B=(Tochka *)malloc(sizeof(Tochka));
            TrK->Tochka_C=(Tochka *)malloc(sizeof(Tochka));
            TrK->Tochka_A->Koordinata_X=X1;
            TrK->Tochka_A->Koordinata_Y=Y1;
            TrK->Tochka_B->Koordinata_X=X2;
            TrK->Tochka_B->Koordinata_Y=Y2;
            TrK->Tochka_C->Koordinata_X=X3;
            TrK->Tochka_C->Koordinata_Y=Y3;
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

void Vidalennya(SpskOfTrK *TagSpskOfTrK)
{
    if(TagSpskOfTrK!=NULL)
    {
        if(TagSpskOfTrK->TrK!=NULL)
        {
            for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
            {
                Trykutnyk *TrK=&(TagSpskOfTrK->TrK[i]);
                if(TrK->Tochka_A!=NULL)
                {
                    free(TrK->Tochka_A);
                }
                if(TrK->Tochka_B!=NULL)
                {
                    free(TrK->Tochka_B);
                }
                if(TrK->Tochka_C!= NULL)
                {
                    free(TrK->Tochka_C);
                }
            }
            free(TagSpskOfTrK->TrK);
        }
        free(TagSpskOfTrK);
    }
}

int ObchislennyaPloschi(Trykutnyk *TrK)
{
    int ploscha=abs((TrK->Tochka_A->Koordinata_X-TrK->Tochka_C->Koordinata_X)*(TrK->Tochka_B->Koordinata_Y-TrK->Tochka_C->Koordinata_Y)-(TrK->Tochka_B->Koordinata_X-TrK->Tochka_C->Koordinata_X)*(TrK->Tochka_A->Koordinata_Y-TrK->Tochka_C->Koordinata_Y));
    return ploscha;
}

void Print(SpskOfTrK *TagSpskOfTrK)
{
    for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
    {
        Trykutnyk *TrK=&(TagSpskOfTrK->TrK[i]);
        printf("Trykutnuk #%d:\n", i+1);
        printf("Tochka A={%d,%d}\n", TrK->Tochka_A->Koordinata_X, TrK->Tochka_A->Koordinata_Y);
        printf("Tochka B={%d,%d}\n", TrK->Tochka_B->Koordinata_X, TrK->Tochka_B->Koordinata_Y);
        printf("Tochka C={%d,%d}\n", TrK->Tochka_C->Koordinata_X, TrK->Tochka_C->Koordinata_Y);
        printf("Ploscha=%d\n", ObchislennyaPloschi(TrK));
    }
}

void WriteSpskOfTrK(FILE *TagFilE, SpskOfTrK *TagSpskOfTrK)
{
    BraceL;
    if (TagSpskOfTrK->TrK!=NULL)
    {
        NewLinE; SpacE; fprintf(TagFilE, "\"Size\": %d", TagSpskOfTrK->MaxKilkTrK); CommA;
        NewLinE; SpacE; fprintf(TagFilE, "\"Current size\": %d", TagSpskOfTrK->CurrentTrK); CommA;
        NewLinE; SpacE; fprintf(TagFilE, "\"Triangles\":");
        NewLinE; TaB; LongSpacE; BracketL;
        for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
        {
            Trykutnyk *TrK=&(TagSpskOfTrK->TrK[i]);
            NewLinE; TaB; LongSpacE; SpacE; BraceL;
            WriteTrykutnyk(TagFilE, TrK);
            if(i<TagSpskOfTrK->CurrentTrK-1)
            {
                NewLinE; TaB; LongSpacE; SpacE; BraceR; CommA;
            }
            else
            {
                NewLinE; TaB; LongSpacE; SpacE; BraceR;
            }
        }
        NewLinE; TaB; LongSpacE; BracketR;
    }
    else
    {
        NewLinE; SpacE; fprintf(TagFilE, "\"NULL\"");
    }
    NewLinE; BraceR;
}

void WriteTrykutnyk(FILE *TagFilE, Trykutnyk *TrK)
{
    NewLinE; TaB; TaB; fprintf(TagFilE, "\"Dot A\":"); SpacE;
    BraceL; fprintf(TagFilE, "\"Coord X\": %d", TrK->Tochka_A->Koordinata_X); CommA; SpacE;
    fprintf(TagFilE, "\"Coord Y\": %d", TrK->Tochka_A->Koordinata_Y); BraceR; CommA;
    NewLinE; TaB; TaB; fprintf(TagFilE, "\"Dot B\":"); SpacE;
    BraceL; fprintf(TagFilE, "\"Coord X\": %d", TrK->Tochka_B->Koordinata_X); CommA; SpacE;
    fprintf(TagFilE, "\"Coord Y\": %d", TrK->Tochka_B->Koordinata_Y); BraceR; CommA;
    NewLinE; TaB; TaB; fprintf(TagFilE, "\"Dot C\":"); SpacE;
    BraceL; fprintf(TagFilE, "\"Coord X\": %d", TrK->Tochka_C->Koordinata_X); CommA; SpacE;
    fprintf(TagFilE, "\"Coord Y\": %d", TrK->Tochka_C->Koordinata_Y); BraceR;
    }
