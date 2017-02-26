//
//  eigthByte.c
//  KPI_Pr
//
//  Created by air on 23.02.17.
//  Copyright © 2017 airMair. All rights reserved.
//

#include "EightByte.h"

#include <stdio.h>
#include <math.h>

long Converting(int EightNumber)
{
    int TenthNumber = 0,
    counter = 0;
    
    while(EightNumber != 0)
    {
        TenthNumber = TenthNumber + ((EightNumber%10) * pow(8,counter));
        counter++;
        EightNumber/=10;
    }
    counter = 1;

    return TenthNumber;
}
