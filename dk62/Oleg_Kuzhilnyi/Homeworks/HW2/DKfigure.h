//
//  DKfigure.h
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

//Struct of coords
typedef struct point {
    int x;
    int y;
}DK_Note;

//Struct of Points
typedef struct TagFigure
{
    DK_Note versOne;
    DK_Note versTwo;
    DK_Note versThree;
    DK_Note versFour;
}DK_tochki;

int AddTochki(DK_tochki *AddsInMassiv);
void AddCoods(DK_Note *AddCoodrs);
double Calculator(DK_tochki *Area);

#endif /* dk_tool_h */
