//
// Created by Олег on 19.02.2017.
//

#include "dk_tool.h"

float factorial(float i)
    {
        float a=1;

            while(i>=2)
            {
                a=a*i;
                i=i-1;
            }

        return a;
    }

float mod(float vyraz)
{
        if(vyraz<0)
        {
            vyraz=-vyraz;
        }

        return vyraz;
}