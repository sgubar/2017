//
//  main.c
//  KPI_Programming
//
//  Created by air on 23.02.17.
//  Copyright © 2017 airMair. All rights reserved.
//

#include "EightByte.h"
#include <stdio.h>

int main()
{
    int EightNumber;
    
    printf("Enter number in 8: ");
    scanf("%d", &EightNumber);
    printf("The Result Number in Decal: %ld\n",Converting(EightNumber));
    
    return 0;
}
