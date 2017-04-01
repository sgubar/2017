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
#define DOUBLETAB "\t\t"
#define MINITAB "\t   "
#define TAB "\t"
#define NEWLINE "\n"


        //Coords of Point
typedef struct Coords {
    int x;
    int y;
}Coords_Of_Geometry_Points;

        //Description Figure ( points )
typedef struct
{
    Coords_Of_Geometry_Points * PointA;
    Coords_Of_Geometry_Points * PointB;
    Coords_Of_Geometry_Points * PointC;
    Coords_Of_Geometry_Points * PointD;
    
}descriptionOfFigure;

        //List with Figures
typedef struct TagFigure
{
    descriptionOfFigure * ListOfFigures;
    int size;
    int current_size;
   
}DK_Figures;

int addMyFigureToArrayOfFigures(DK_Figures *ArrayFigures);


DK_Figures *createFigure(int aSize);


double FindAreaQuadrilateral(descriptionOfFigure *Figure);

void ScanfCoords(Coords_Of_Geometry_Points *Point);
void printfAreaFigure(DK_Figures *inPhoneBook);

void destroyFigure(DK_Figures *FigureList);


void writePoint(FILE *aFile, descriptionOfFigure *aNote);
void writeFigures(FILE *aFile, DK_Figures *aList);

#endif /* dk_tool_h */
