//
//  first.c
//  S_K
//
//  Created by air on 27.02.17.
//  Copyright © 2017 O_Student. All rights reserved.
//

#include "first.h"


#include <stdio.h>
#include <math.h>
#include <string.h>

int ConvertToDecal(char Second[])
{
    
    int decal=0;
    int point = sizeof(&Second)-2;//Stepen
    
    for(int i=0;i<8 || '\0' != Second[i] ;i++)
    {
        if(Second[i] == '1'){
        decal = decal + pow(2,point);
            --point;
        }else
        {
             --point;
             continue;
        }
    }
    return decal;
    
}
