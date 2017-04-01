//
//  DKfigure.c
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "DKfigure.h"

DK_Figures *createFigure(int aSize)
{
    DK_Figures *theFigures = (DK_Figures *) malloc(sizeof(DK_Figures));
    
    if(NULL != theFigures)
    {
        theFigures->ListOfFigures = (descriptionOfFigure *)malloc(aSize*sizeof(descriptionOfFigure));
        
       // bzero(theFigures,aSize*sizeof(Coords_Of_Geometry_Points)); //Zero for elements of struct
        memset(theFigures->ListOfFigures, 0, aSize * sizeof(Coords_Of_Geometry_Points)); // Set zero array
        theFigures->size = aSize;
        theFigures->current_size = 0;
        
    }
    
    return theFigures;
}
int addMyFigureToArrayOfFigures(DK_Figures *ArrayFigures)
{
    int theResult = 0;
    if (NULL != ArrayFigures)
    {
        if (ArrayFigures->current_size < ArrayFigures->size)
        {
            descriptionOfFigure *ArrayOfFigures = &(ArrayFigures->ListOfFigures[ArrayFigures->current_size]);
            
            ArrayOfFigures->PointA = (Coords_Of_Geometry_Points *)malloc(sizeof(Coords_Of_Geometry_Points));
            ArrayOfFigures->PointB = (Coords_Of_Geometry_Points *)malloc(sizeof(Coords_Of_Geometry_Points));
            
            ArrayOfFigures->PointC = (Coords_Of_Geometry_Points *)malloc(sizeof(Coords_Of_Geometry_Points));
            ArrayOfFigures->PointD = (Coords_Of_Geometry_Points *)malloc(sizeof(Coords_Of_Geometry_Points));
            
            printf("\t\t\tThe Figure №%i\n", ArrayFigures->current_size);
            
            puts("\t PointA: ");
            ScanfCoords(ArrayOfFigures->PointA);
            puts("\t PointB: ");
            ScanfCoords(ArrayOfFigures->PointB);
            puts("\t PointC: ");
            ScanfCoords(ArrayOfFigures->PointC);
            puts("\t PointD: ");
            ScanfCoords(ArrayOfFigures->PointD);
            
            ArrayFigures->current_size ++;
            
        }
        else
        {
            theResult = -2;
        }
    }
    else
    {
        theResult = -1;
    }
    
    return theResult;
}
void ScanfCoords(Coords_Of_Geometry_Points *Point)
{
    puts("x: ");
    scanf("%i",&Point->x);
    puts("y: ");
    scanf("%i",&Point->y);
    puts("----");
    
}

void destroyFigure(DK_Figures *Figure)
{
    if (NULL != Figure)
    {
        if(NULL != Figure->ListOfFigures)
        {
            for (int i = 0; i < Figure->current_size; i++)
            {
                descriptionOfFigure *theLinkTolist = &(Figure->ListOfFigures[i]);
                if (NULL != theLinkTolist->PointA &&NULL != theLinkTolist->PointA && NULL != theLinkTolist->PointA && NULL != theLinkTolist->PointA)
                {
                    free(theLinkTolist->PointA);
                        free(theLinkTolist->PointB);
                            free(theLinkTolist->PointC);
                                free(theLinkTolist->PointD);
                }
            }
            free(Figure->ListOfFigures);
        }
      free(Figure);
    }
}

double FindAreaQuadrilateral(descriptionOfFigure *Figure) //Calculate Area of Quadrilateral
{
    double ResultArea =
    ((((Figure->PointA->x)*(Figure->PointB->y)-(Figure->PointA->y)*(Figure->PointB->x)))
    +
    (((Figure->PointB->x)*(Figure->PointC->y)-(Figure->PointB->y)*(Figure->PointB->x)))
    +
    (((Figure->PointC->x)*(Figure->PointC->y)-(Figure->PointB->y)*(Figure->PointC->x)))
    +
    (((Figure->PointC->x)*(Figure->PointA->y)- (Figure->PointC->y)*(Figure->PointA->x))))
                                        /2;
if (ResultArea < 0)
    return ResultArea*(-1); //ABS of Area
  else
    return ResultArea;

}

void printfAreaFigure(DK_Figures *FigureList)
{
    for (int i = 0; i < FigureList->current_size; i++)
    {
        descriptionOfFigure *theFigure = &(FigureList->ListOfFigures[i]);
        
        printf("[%d] - ", i);
        printf("Area Of Figure:%.2f\n",FindAreaQuadrilateral(theFigure));
    }
    
}

// Write Coords in json
void writePoint(FILE *aFile, descriptionOfFigure *aNote)
{
    fprintf (aFile,MINITAB);
    fprintf (aFile, "{");
    fprintf(aFile, NEWLINE);

    

        fprintf (aFile, DOUBLETAB);
        fprintf (aFile, "\"Point A\": \"coord x\": \"%d\",\"coord y\": \"%d\"\n" ,aNote->PointA->x , aNote->PointA->y);
        fprintf (aFile, DOUBLETAB);
    
        fprintf (aFile, "\"Point B\": \"coord x\": \"%d\",\"coord y\": \"%d\"\n" ,aNote->PointB->x , aNote->PointB->y);
        fprintf (aFile, DOUBLETAB);
    
        fprintf (aFile, "\"Point C\": \"coord x\": \"%d\",\"coord y\": \"%d\"\n" ,aNote->PointC->x , aNote->PointC->y);
        fprintf (aFile, DOUBLETAB);
    
        fprintf (aFile, "\"Point D\": \"coord x\": \"%d\",\"coord y\": \"%d\"\n" ,aNote->PointD->x , aNote->PointD->y);
        fprintf (aFile, DOUBLETAB);
    
    fprintf (aFile,MINITAB);
    fprintf (aFile, "}");


}

//  Write Figure in json
void writeFigures(FILE *aFile, DK_Figures *aList)
{
    fprintf (aFile, "{");
    fprintf (aFile, NEWLINE);
    
    if (NULL == aList->ListOfFigures)
    {
        fprintf(aFile, "null");
    }
    else
    {
        fprintf (aFile, NEWLINE);
       
        fprintf (aFile, "\"Figures\":\n");
        fprintf (aFile, TAB);
        fprintf(aFile, "[");
        fprintf(aFile, NEWLINE);
        
        for (int i = 0; i < aList->current_size; i++)
        {
            descriptionOfFigure *theNote = &(aList->ListOfFigures[i]);
            
            writePoint(aFile, theNote);
            if (i < (aList->current_size - 1))
            {
                fprintf (aFile, COMMA);
                fprintf(aFile, NEWLINE);

            }
        }
        
   
    fprintf(aFile, NEWLINE);
    fprintf (aFile, TAB);
    fprintf(aFile, "]");
    fprintf(aFile, COMMA);
    fprintf(aFile, NEWLINE);

             }
    fprintf(aFile, MINITAB);
    fprintf(aFile, "\"size\": %d ,\n", aList->size);
    fprintf(aFile, MINITAB);
    fprintf(aFile, "\"current size\" : %d\n", aList->current_size);
    fprintf (aFile, "}");
    fprintf(aFile, NEWLINE);

}
