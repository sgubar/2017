//
//  Sorting.c
//  HW3
//
//  Created by air on 31.03.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#include "Sort.h"
#include "DKfigure.h"

void bubbleSort(DK_Figures *FigureList)
{
    for(int TheOut = 0;TheOut < FigureList->current_size; TheOut++)
    {
        for(int TheIn = 0; TheIn < FigureList->current_size-1;TheIn++)
        {
            
            if (FindAreaQuadrilateral(&FigureList->ListOfFigures[TheIn]) >FindAreaQuadrilateral(&FigureList->ListOfFigures[TheIn+1]))
            {
                descriptionOfFigure temp = FigureList->ListOfFigures[TheOut];
                FigureList->ListOfFigures[TheOut] = FigureList->ListOfFigures[TheIn+1];
                FigureList->ListOfFigures[TheIn+1] = temp;
               
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
            if(FindAreaQuadrilateral(&FigureList->ListOfFigures[TheIn]) < FindAreaQuadrilateral(&FigureList->ListOfFigures[min]))
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
        
        while (theIn > 0 && FindAreaQuadrilateral(&FigureList->ListOfFigures[theIn - 1]) >= FindAreaQuadrilateral(&theTmp))
        {
            FigureList->ListOfFigures[theIn] = FigureList->ListOfFigures[theIn - 1];
            -- theIn;
        }
        
        FigureList->ListOfFigures[theIn] = theTmp;
    }
}

