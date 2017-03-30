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
        theFigures->ListOfFigures = (descriptionOfFigure *)malloc(aSize * sizeof(descriptionOfFigure));
        
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
    int MountOfAngle = 4;
    if (NULL != ArrayFigures)
    {
        if (ArrayFigures->current_size < ArrayFigures->size)
        {
            descriptionOfFigure *ArrayOfFigures = &(ArrayFigures->ListOfFigures[ArrayFigures->current_size]);

            ArrayOfFigures->Point = (Coords_Of_Geometry_Points *)malloc(MountOfAngle*sizeof(Coords_Of_Geometry_Points));

            for(int Counter_Points = 0 ; Counter_Points < MountOfAngle ; Counter_Points++)
            {
                switch(Counter_Points) // idintificate
                {
                    case 0: printf("\t\tPoint A\n");
                        break;
                    case 1: printf("\t\tPoint B\n");
                        break;
                    case 2: printf("\t\tPoint C\n");
                        break;
                    case 3: printf("\t\tPoint D\n");
                        break;
                }
                printf("\tx: ");
                scanf("%i",&ArrayOfFigures->Point[Counter_Points].x);   //= rand()%100;
                printf("\ty: ");
                scanf("%i",&ArrayOfFigures->Point[Counter_Points].y);    //    =  rand()%100;
           }
            printf("-------------------\n");
            
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

void destroyFigure(DK_Figures *Figure)
{
    if (NULL != Figure)
    {
        if(NULL != Figure->ListOfFigures)
        {
            for (int i = 0; i < Figure->current_size; i++)
            {
                descriptionOfFigure *theLinkTolist = &(Figure->ListOfFigures[i]);
                if (NULL != theLinkTolist->Point)
                {
                    free(theLinkTolist->Point);
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
    ((((Figure->Point[0].x)*(Figure->Point[1].y)- (Figure->Point[0].y)*(Figure->Point[1].x)))
    +
    (((Figure->Point[1].x)*(Figure->Point[2].y)-(Figure->Point[1].y)*(Figure->Point[2].x)))
    +
    (((Figure->Point[2].x)*(Figure->Point[3].y)-(Figure->Point[2].y)*(Figure->Point[3].x)))
    +
    (((Figure->Point[3].x)*(Figure->Point[0].y)- (Figure->Point[3].y)*(Figure->Point[0].x))))
                                        /2;
if (ResultArea < 0)
    return ResultArea*(-1); //ABS of Area
  else
    return ResultArea;

}

void printfFigure(DK_Figures *FigureList)
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
    fprintf (aFile, "{");
    
    for(int Counter_Points = 0; Counter_Points < 4 ; Counter_Points++)
    {
        char ASCIIcounter = 65;
        
        fprintf (aFile, "\"P%d\": \"coord x\": \"%d\",\"coord y\": \"%d\"" ,Counter_Points,aNote->Point[Counter_Points].x , aNote->Point[Counter_Points].x);
    
    fprintf (aFile, ",");
        ASCIIcounter++;
    }
    fprintf (aFile, "\"Area\":\"%.2f\"", FindAreaQuadrilateral(aNote));
   
    fprintf (aFile, "}");
}

                //  Write Figure in json
void writeFigures(FILE *aFile, DK_Figures *aList)
{
    fprintf (aFile, "{");
    
    fprintf(aFile, "\"size\":%d", aList->size);
    fprintf(aFile, ",");
    
    fprintf(aFile, "\"Figure\":");
    
    if (NULL == aList->ListOfFigures)
    {
        fprintf(aFile, "null");
    }
    else
    {
        fprintf(aFile, "[");
        
        for (int i = 0; i < aList->current_size; i++)
        {
            descriptionOfFigure *theNote = &(aList->ListOfFigures[i]);
            
            writePoint(aFile, theNote);
            
            if (i < (aList->current_size - 1))
            {
                fprintf (aFile, ",");
            }
        }
        
        fprintf(aFile, "]");
    }
    
    fprintf (aFile, "}");
}




