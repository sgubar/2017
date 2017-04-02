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
    
    DK_Figures *aFigure = createFigure(10);
    
     printf("\t\tPlease Enter a Four Points for %i Figure \n\n",aFigure->size);

    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);

    writeFigures(theFile, aFigure);

    printfAreaFigure(aFigure);      // Print Area of Figure "aFigure"
    
    destroyFigure(aFigure);     // Free memory
    
    fclose(theFile);
    return 0;
}
