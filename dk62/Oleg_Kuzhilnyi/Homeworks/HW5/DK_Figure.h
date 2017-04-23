//
//  evrist.h
//  HW5
//
//  Created by air on 16.04.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DOUBLETAB "\t\t"
#define MINITAB "\t   "
#define TAB "\t"
#define NEWLINE "\n"
#define COMMA ","


//Coords of Point
typedef struct Coords {
    int x;
    int y;
}Coords_Of_Geometry_Points;

//Description Figure ( points )
typedef struct
{
    Coords_Of_Geometry_Points Points[4];
    
}descriptionOfFigure;

//List with Figures
typedef struct TagFigure
{
    descriptionOfFigure * ListOfFigures;
    int size;
    int current_size;
    
}DK_Figures;

int addMyFigureToArrayOfFigures(DK_Figures *TheListOfFigures);


DK_Figures *createFigure(int aSize);


double CalculateAreaQuadrilateral(descriptionOfFigure *Figure);

void ScanTheCoords (descriptionOfFigure *TheListOfFigures);

void printfAreaFigure(DK_Figures *TheListOfFigures);

void destroyFigure(DK_Figures *TheListOfFigures);
void destroyPoints(descriptionOfFigure *PointsLins);

void write_theFigure(FILE *aFile, descriptionOfFigure *aNote);
void writeFiguresToFile(FILE *aFile, DK_Figures *aList);

#endif /* dk_tool_h */
