//
//  main.c
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//


#include "DKfigure.h"
#include "Sort.h"

int main(int argc, const char *argv[])
{
    FILE *theFile = fopen("/Users/air/Documents/Programming_C/Homework 3/HW3/HW3/data.json","w");
    
    DK_Figures *aFigure = createFigure(3);
    
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    
    
    printf ("Before sorting ...\n");
     printfAreaFigure(aFigure);
    
    puts("-----------------------");
    puts("\t1 - Bubble Sort");
    puts("\t2 - Select Sort");
    puts("\t3 - Insert Sort");
    printf("Please select the Type of Sort: \n");
    
    int Choose = 0;
    scanf("%i", &Choose);//counter for select type of sort
    
    switch(Choose)
    {
        case 1:// Bubble Sort
            
            bubbleSort(aFigure);
            break;
        case 2: // Selection Sort
            
            selectionSort(aFigure);
            break;
        case 3:// Insertion Sort
            
            insertionSort(aFigure);
            break;
            
        default:
            printf("You might Enter 1,2 or 3\n");
            return -1;
            
    }

    printf ("After sorting ...\n");
    printfAreaFigure(aFigure);      // Print Area of Figure "aFigure"
    
    destroyFigure(aFigure);     // Free memory
    
    fflush(theFile);
    fclose(theFile);
    return 0;
}
