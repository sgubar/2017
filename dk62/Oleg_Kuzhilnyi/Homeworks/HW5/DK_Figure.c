//
//  evrissort.c
//  HW5
//
//  Created by air on 16.04.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#include "DK_Figure.h"

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
int addMyFigureToArrayOfFigures(DK_Figures *TheListOfFigures)
{
    int theResult = 0;
    if (NULL != TheListOfFigures)
    {
        if (TheListOfFigures->current_size < TheListOfFigures->size)
        {
           descriptionOfFigure *aFigure = &(TheListOfFigures->ListOfFigures[TheListOfFigures->current_size]);
        
            printf("\t\tCurrent: № %i\n\n",TheListOfFigures->current_size);
 
                ScanTheCoords(aFigure);
            
                TheListOfFigures->current_size ++;
            
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


void ScanTheCoords (descriptionOfFigure *TheListOfFigures)
{
    for(int theIndexOfPoint = 0; theIndexOfPoint < 4 ; theIndexOfPoint++)
    {
        printf("The Point: %i\n",theIndexOfPoint);
        
        printf("\tx: ");
        scanf("%i",&TheListOfFigures-> Points[theIndexOfPoint].x);
        
        printf("\ty: ");
        scanf("%i",&TheListOfFigures-> Points[theIndexOfPoint].y);
    }
    
}

void destroyFigure(DK_Figures *TheListOfFigures)
{
    if (NULL != TheListOfFigures)
    {
        if(NULL != TheListOfFigures->ListOfFigures)
        {
            free(TheListOfFigures->ListOfFigures);
        }
        free(TheListOfFigures);
    }
}


double CalculateAreaQuadrilateral(descriptionOfFigure *Figure) //Calculate Area of Quadrilateral
{
    double ResultArea =
    ((((Figure->Points[0].x)*(Figure->Points[1].y)-(Figure->Points[0].y)*(Figure->Points[1].x)))
     +
     (((Figure->Points[1].x)*(Figure->Points[2].y)-(Figure->Points[1].y)*(Figure->Points[2].x)))
     +
     (((Figure->Points[2].x)*(Figure->Points[3].y)-(Figure->Points[2].y)*(Figure->Points[3].x)))
     +
     (((Figure->Points[3].x)*(Figure->Points[1].y)- (Figure->Points[3].y)*(Figure->Points[1].x))))
    /2;
    if (ResultArea < 0)
        return ResultArea*(-1); //ABS of Area
    else
        return ResultArea;
    
}

void printfAreaFigure(DK_Figures *TheListOfFigures)
{
    for (int i = 0; i < TheListOfFigures->current_size; i++)
    {
        descriptionOfFigure *TheFigure = &(TheListOfFigures->ListOfFigures[i]);
        
        printf("[%d] - ", i);
        printf("Area Of Figure:%.2f\n",CalculateAreaQuadrilateral(TheFigure));
    }
    
}

// Write Coords in json
void write_theFigure(FILE *aFile, descriptionOfFigure *aNote)
{
    fprintf (aFile,MINITAB);
    fprintf (aFile, "{");
    fprintf(aFile, NEWLINE);
    
    
    
    fprintf (aFile, DOUBLETAB);
    fprintf (aFile, "\"Point A\":");
    fprintf (aFile, "{");
    fprintf (aFile,  "\"coord x\": %d,\"coord y\": %d" ,aNote->Points[0].x , aNote->Points[0].y);
    fprintf (aFile, "}");
    fprintf (aFile, COMMA);
    fprintf (aFile, NEWLINE);
    fprintf (aFile, DOUBLETAB);
    
    fprintf (aFile, "\"Point B\":");
    fprintf (aFile, "{");
    fprintf (aFile,"\"coord x\": %d,\"coord y\": %d" ,aNote->Points[1].x , aNote->Points[1].y);
    fprintf (aFile, "}");
    fprintf (aFile, COMMA);
    fprintf (aFile, NEWLINE);
    fprintf (aFile, DOUBLETAB);
    
    fprintf (aFile, "\"Point C\":");
    fprintf (aFile, "{");
    fprintf (aFile,"\"coord x\": %d,\"coord y\": %d" ,aNote->Points[2].x , aNote->Points[2].y);
    fprintf (aFile, "}");
    fprintf (aFile, COMMA);
    fprintf (aFile, NEWLINE);
    fprintf (aFile, DOUBLETAB);
    
    fprintf (aFile, "\"Point D\":");
    fprintf (aFile, "{");
    fprintf (aFile,"\"coord x\": %d,\"coord y\": %d" ,aNote->Points[3].x , aNote->Points[3].y);
    fprintf (aFile, "}");
    fprintf (aFile, NEWLINE);
    fprintf (aFile, DOUBLETAB);
    
    
    
    fprintf (aFile,MINITAB);
    fprintf (aFile, "}");
    
}

//  Write Figure in json
void writeFiguresToFile(FILE *aFile, DK_Figures *aList)
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
            
            write_theFigure(aFile, theNote);
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
    
    puts("Write to File your Figures complete");
}
