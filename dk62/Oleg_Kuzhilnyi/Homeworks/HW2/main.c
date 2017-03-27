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
    DK_tochki *ForMemory = CreateCoords();//Create memory for Points
    
    AddTochki(ForMemory);// Add Points
    
    printf("The Res:%.2f\n",Calculator(ForMemory));//Calculate area and PRINT

    DestroyFigure(ForMemory);// Free memory
    
    return 0;
}
