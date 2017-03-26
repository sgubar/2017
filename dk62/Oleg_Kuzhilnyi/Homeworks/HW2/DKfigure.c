//
//  DKfigure.c
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "DKfigure.h"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
void AddCoods(DK_Note *AddCoodrs);

int AddTochki(DK_tochki *AddsInMassiv) //Struct of Points
{
    
    //Memory allocation
    
    DK_Note *TheNoteOne = &AddsInMassiv->versOne;
    DK_Note *TheNoteTwo = &AddsInMassiv->versTwo;
    DK_Note *TheNoteThree = &AddsInMassiv->versThree;
    DK_Note *TheNoteFour = &AddsInMassiv->versFour;
    
    //Add in Massiv Coords
    AddCoods(TheNoteOne);
    AddCoods(TheNoteTwo);
    AddCoods(TheNoteThree);
    AddCoods(TheNoteFour);
    
    return 0;
}

void AddCoods(DK_Note *AddCoodrs) //Screen Input
{
    
    printf("please x:");
    scanf("%i", &AddCoodrs->x);
    printf("please y:");
    scanf("%i", &AddCoodrs->y);
    
}


double Calculator(DK_tochki *Area) //Calculate Area of Quadrilateral
{
    double ResultArea =
    ((((Area->versOne.x)*(Area->versTwo.y)- (Area->versOne.y)*(Area->versTwo.x)))
    +
    (((Area->versTwo.x)*(Area->versThree.y)-(Area->versTwo.y)*(Area->versThree.x)))
    +
    (((Area->versThree.x)*(Area->versFour.y)-(Area->versThree.y)*(Area->versFour.x)))
    +
    (((Area->versFour.x)*(Area->versOne.y)- (Area->versFour.y)*(Area->versOne.x))))
                                        /2;

  if (ResultArea < 0)
    return ResultArea*(-1); //ABS of Area
  else
    return ResultArea;

}


//void Calculator
