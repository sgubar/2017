//
//  main.c
//  HW5
//
//  Created by air on 16.04.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#include "DK_Figure.h"
#include "Sorting.h"

int main(int argc, const char *argv[])
{
  //  FILE *theFile = fopen("data.json","w");
    
    DK_Figures *aFigure = createFigure(10);  //Create List Of Figure
    
    addMyFigureToArrayOfFigures(aFigure);   //Add New Figure
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);

    printf("----------Before Sorting----------\n");
    
    printfAreaFigure(aFigure);
    
    shellSort(aFigure);
    
    printf("----------After Sorting----------\n");

    printfAreaFigure(aFigure);
    
    line_find(aFigure, 228);

    destroyFigure(aFigure);     // Free memory
    
    
    /*
    fflush(theFile);
    fclose(theFile);
     */
    return 0;
}
