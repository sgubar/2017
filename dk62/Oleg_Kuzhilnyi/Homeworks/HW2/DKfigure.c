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
            
            printf("\t\tThe Figure №%i\n", ArrayFigures->current_size);
            
             ScanfCoords(ArrayOfFigures->PointA);
             ScanfCoords(ArrayOfFigures->PointB);
             ScanfCoords(ArrayOfFigures->PointC);
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
    printf("\tx: ");
    scanf("%i",&Point->x);
    printf("\ty: ");
    scanf("%i",&Point->y);
    puts("\t------");
    
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


