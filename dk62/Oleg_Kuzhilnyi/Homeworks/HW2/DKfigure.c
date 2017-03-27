//
//  DKfigure.c
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "DKfigure.h"

void AddCoords(DK_Note *AddCoodrs);

DK_tochki *CreateCoords(void)
{
    DK_tochki *ForMemory = (DK_tochki *) malloc(sizeof(DK_tochki));// Create memory
    
    if(NULL != ForMemory)
    {
        bzero(ForMemory,sizeof(DK_tochki)); //Zero for elements of struct
   
    }
    
    return ForMemory;
}

void AddCoords(DK_Note *AddCoodrs) //Screen Input Coords X,Y
{
    
    printf("please x:");
    scanf("%i", &AddCoodrs->x);
    printf("please y:");
    scanf("%i", &AddCoodrs->y);
    printf("------------------------\n");
    
}

int AddTochki(DK_tochki *AddsInMassiv) //Struct of Points
{
    
    //Memory allocation
    
    DK_Note *TheNoteOne = &AddsInMassiv->versOne;
    DK_Note *TheNoteTwo = &AddsInMassiv->versTwo;
    DK_Note *TheNoteThree = &AddsInMassiv->versThree;
    DK_Note *TheNoteFour = &AddsInMassiv->versFour;
    
    //Add in Massiv Coords
    AddCoords(TheNoteOne);
    AddCoords(TheNoteTwo);
    AddCoords(TheNoteThree);
    AddCoords(TheNoteFour);
    
    return 0;
}



void DestroyFigure(DK_tochki * theTochki)
{
    if(NULL != theTochki)
    {
        free(theTochki);
    }
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


