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
    DK_Figures *aFigure = createFigure(4);//Create memory for Points
    

    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);
    addMyFigureToArrayOfFigures(aFigure);

    printfFigure(aFigure);
    
    destroyFigure(aFigure);// Free memory
    
    return 0;
}
