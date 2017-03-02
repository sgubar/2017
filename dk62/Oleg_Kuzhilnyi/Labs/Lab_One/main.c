//
//  main.c
//  Lab_one
//
//  Created by air on 01.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "dk_tool.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    int Number_A=0,
            Number_B=0,
                Number_C=0;
    printf("Please Enter the Numbers in Integer Type e.g. 0,1,-2,-3\n");
    printf("A: ");
    scanf("%i", &Number_A);
    printf("B: ");
    scanf("%i", &Number_B);
    printf("C: ");
    scanf("%i", &Number_C);
    
    printf("The Result Q:  <%.2f> \n", MathDEL(Number_A, Number_B, Number_C )
                                                                    + MathDegree(Number_A, Number_B, Number_C));
                /*
                  Math funtion Q<-
                 */

    return 0;
}
