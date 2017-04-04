//
// Created by Max on 20.03.2017.
//

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int RzmR;
    printf("Vvedit rozmir spisku:");
    scanf("%d", RzmR);

    SpskOfTrK *TagSpskOfTrK=StvorennyaSpsK(RzmR); //Виклик функції створення списку трикутників

    addDani(TagSpskOfTrK, 43, 14, 5, 2, 6, 3);
    addDani(TagSpskOfTrK, 53, 64, 4, 5, 12, 3);   //Виклик функції додавання координат вершин трикутників
    addDani(TagSpskOfTrK, 6, 1, 55, 4, 5, 6);

    Print(TagSpskOfTrK);                          //Виклик функції виведення списку трикутників

    Vidalennya(TagSpskOfTrK);                     //Виклик функції звільнення памяті

    return 0;
}
