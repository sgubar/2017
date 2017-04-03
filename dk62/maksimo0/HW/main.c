//
// Created by Max on 20.03.2017.
//

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    //printf("Vvedit rozmir spisku:");
    int RzmR=10;
    //scanf("%d", RzmR);

    SpskOfTrK *TagSpskOfTrK=StvorennyaSpsK(RzmR);

    addDani(TagSpskOfTrK, 43, 14, 5, 2, 6, 3);
    addDani(TagSpskOfTrK, 53, 64, 4, 5, 12, 3);
    addDani(TagSpskOfTrK, 6, 1, 55, 4, 5, 6);

    Print(TagSpskOfTrK);

    Vidalennya(TagSpskOfTrK);

    return 0;
}
