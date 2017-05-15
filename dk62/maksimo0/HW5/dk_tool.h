//
// Created by Max on 04.04.2017.
//

#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>
#include <string.h>

#define CommA fprintf(TagFilE, ",")
#define BraceR fprintf(TagFilE, "}")
#define BraceL fprintf(TagFilE, "{")
#define BracketR fprintf(TagFilE, "]")
#define BracketL fprintf(TagFilE, "[")
#define TaB fprintf(TagFilE, "\t")
#define NewLinE fprintf(TagFilE, "\n")
#define SpacE fprintf(TagFilE, " ");
#define LongSpacE fprintf(TagFilE, "   ");


typedef struct Koordinaty
{
    int Koordinata_X;
    int Koordinata_Y;
}Tochka;

typedef struct Tochki
{
    Tochka *Tochka_A;
    Tochka *Tochka_B;
    Tochka *Tochka_C;
}Trykutnyk;

typedef struct TagTrK
{
    Trykutnyk *TrK;
    int CurrentTrK;
    int MaxKilkTrK;
}SpskOfTrK;

SpskOfTrK *StvorennyaSpsK(int RzmR);

int addDani(SpskOfTrK *TagSpskOfTrK, int X1, int Y1, int X2, int Y2, int X3, int Y3);

void Vidalennya(SpskOfTrK *TagSpskOfTrK);

int ObchislennyaPloschi(Trykutnyk *TrK);

void Print(SpskOfTrK *TagSpskOfTrK);

void WriteSpskOfTrK(FILE *TagFilE, SpskOfTrK *TagSpskOfTrK);

void WriteTrykutnyk(FILE *TagFilE, Trykutnyk *TrK);

#endif
