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
    Coords_Of_Geometry_Points *Point;
    
}descriptionOfFigure;

typedef struct TagFigure
{
    descriptionOfFigure * ListOfFigures;
    int size;
    int current_size;
   
}DK_Figures;

int addMyFigureToArrayOfFigures(DK_Figures *ArrayFigures);


DK_Figures *createFigure(int aSize);


double FindArea(descriptionOfFigure *Figure);

void printfFigure(DK_Figures *inPhoneBook);

void destroyFigure(DK_Figures *FigureList);
#endif /* dk_tool_h */
