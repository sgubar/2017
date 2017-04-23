//
//  Sorting.c
//  HW5
//
//  Created by air on 16.04.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#include "Sorting.h"
#include "DK_Figure.h"

void bubbleSort(DK_Figures *FigureList)
{
    for (int theOut = FigureList->current_size-1 ; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (CalculateAreaQuadrilateral(&FigureList->ListOfFigures[theIn]) > CalculateAreaQuadrilateral(&FigureList->ListOfFigures[theIn+1]))
            {
                descriptionOfFigure theTmp = FigureList->ListOfFigures[theIn];
                FigureList->ListOfFigures[theIn] = FigureList->ListOfFigures[theIn + 1];
                FigureList->ListOfFigures[theIn + 1] = theTmp;
            }
        }
    }
}

void selectionSort(DK_Figures *FigureList)
{
    for(int TheOut = 0; TheOut< FigureList->current_size; TheOut++)
    {
        int min = TheOut;
        for(int TheIn = TheOut;TheIn < FigureList->current_size; TheIn++)
        {
            if(CalculateAreaQuadrilateral(&FigureList->ListOfFigures[TheIn]) < CalculateAreaQuadrilateral(&FigureList->ListOfFigures[min]))
            {
                min = TheIn;
            }
        }
        descriptionOfFigure temp = FigureList->ListOfFigures[TheOut];
        FigureList->ListOfFigures[TheOut] = FigureList->ListOfFigures[min];
        FigureList->ListOfFigures[min] = temp;
        
    }
}

void insertionSort(DK_Figures *FigureList)
{
    for (int theOut = 1; theOut < FigureList->current_size; theOut ++)
    {
        descriptionOfFigure theTmp = FigureList->ListOfFigures[theOut];
        int theIn = theOut;
        
        while (theIn > 0 && CalculateAreaQuadrilateral(&FigureList->ListOfFigures[theIn - 1]) >= CalculateAreaQuadrilateral(&theTmp))
        {
            FigureList->ListOfFigures[theIn] = FigureList->ListOfFigures[theIn - 1];
            -- theIn;
        }
        
        FigureList->ListOfFigures[theIn] = theTmp;
    }
}


void shellSort(DK_Figures *anArray)
{
    int theInner = 0;
    int theOuter = 0;
    int theH = 1; // start h = 1
    
    //1. Calculate start value of h
    while (theH <= anArray->current_size/3)
    {
        theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
    }
    
    //2. Sequental decrease h to 1
    while (theH > 0)
    {
        for (theOuter = theH; theOuter < anArray->current_size; theOuter ++)
        {
            descriptionOfFigure theTmp = anArray->ListOfFigures[theOuter];
            theInner = theOuter;
            
            // the first sub-array {0, 4, 8}
            while (theInner > theH-1 && CalculateAreaQuadrilateral(&anArray->ListOfFigures[theInner - theH]) >= CalculateAreaQuadrilateral(&theTmp))
            {
                anArray->ListOfFigures[theInner] = anArray->ListOfFigures[theInner - theH];
                theInner -= theH;
            }
            
            anArray->ListOfFigures[theInner] = theTmp;
        }
        
        theH = (theH - 1) / 3; //decrease h
    }
}


unsigned line_find(DK_Figures *FigureList, int aKey)
{
    const unsigned kNotFound = -1;
    unsigned theResult = kNotFound;
    
    for (unsigned i = 0; i < FigureList->current_size; i++)
    {
        if (CalculateAreaQuadrilateral(&FigureList->ListOfFigures[i]) == aKey)
        {
            theResult = i;
            printf("The Index of Your element: %i", theResult);
            break;
        }
    }
    
    puts("No have this area in ArrayList");
    
    return theResult;
}
