//
//  main.c
//  HW2
//
//  Created by air on 03.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//


#include "DKfigure.h"

int main(int argc, const char *argv[])
{
    FILE *theFile = fopen("data.json","w");
    
    DK_Figures *aFigure = createFigure(10);  //Create List Of Figure
    
    printf("\t\tPlease Enter a Four Points for %i Figure \n\n",aFigure->size);
    
    addMyFigureToArrayOfFigures(aFigure);   //Add New Figure
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    
    writeFigures(theFile, aFigure);
    
    printfAreaFigure(aFigure);      // Print Area of Figure "aFigure"
    
    destroyFigure(aFigure);     // Free memory
    
    fflush(theFile);
    fclose(theFile);
    return 0;
}
