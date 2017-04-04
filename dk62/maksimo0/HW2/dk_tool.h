//
// Created by Max on 28.03.2017.
//

#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>
#include <string.h>

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
  //  int Ploscha;
}Trykutnyk;  //Структура трикутника, який містить в собі три точки

typedef struct TagTrK
{
    Trykutnyk *TrK;
    int CurrentTrK;
    int MaxKilkTrK;
}SpskOfTrK; //Структура яка містить в собі список трикутників

SpskOfTrK *StvorennyaSpsK(int RzmR);

int addDani(SpskOfTrK *TagSpskOfTrK, int X1, int Y1, int X2, int Y2, int X3, int Y3);

void Vidalennya(SpskOfTrK *TagSpskOfTrK);

int ObchislennyaPloschi(Trykutnyk *TrK);

void Print(SpskOfTrK *TagSpskOfTrK);

#endif
