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
    DK_Figures *aFigure = createFigure(4);    
    

    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);

    printfFigure(aFigure);      // Print Area of Figure "aFigure"
    
    destroyFigure(aFigure);     // Free memory
    
    return 0;
}
