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
#include <stdlib.h>
#include <string.h>

//Struct of coords
typedef struct Coords {
    int x;
    int y;
}Coords_Of_Geometry_Points;

//Struct of Points
typedef struct
{
    Coords_Of_Geometry_Points *Points;
    
}descriptionOfFigure;

typedef struct TagFigure
{
    descriptionOfFigure * ListOfFigures;
    int size;
    int current_size;
   
}DK_Figures;


descriptionOfFigure *CreateCoords(void);// Create memory

int addMyFigureToArrayOfFigures(DK_Figures *ArrayFigures);
int addCoordsInPointsOfmyFigure(Coords_Of_Geometry_Points *isertedCoordsToPointsOfFigue);

DK_Figures *createFigure(int aSize);
double FindArea(descriptionOfFigure *Figure);
void destroyFigure(DK_Figures *FigureList);
void printPhoneBook(DK_Figures *inPhoneBook);
#endif /* dk_tool_h */
