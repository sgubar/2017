#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

#define PI 3.14 //const in math

//main: delete and create
optionCircle *createCircle(int size)
{
    optionCircle *mainCircle=(optionCircle *)malloc(sizeof(optionCircle));

    if(mainCircle!=NULL)
    {
        mainCircle->sizeCircle=(circle *)malloc(size*sizeof(circle));
        mainCircle->current_size=0;
        mainCircle->size=size;
    }
}

void destroyAllCircle(optionCircle *mainCircle)
{
    if (mainCircle!=NULL)
    {
        if(mainCircle->sizeCircle!=NULL)
            free(mainCircle->sizeCircle);

        free(mainCircle);
    }
}

//interface
int addToCircle(optionCircle *mainCircle, float centerX, float centerY, float radius)
{
        if(mainCircle->current_size < mainCircle->size)
        {
            circle *sizeCircle=&(mainCircle->sizeCircle[mainCircle->current_size]);
            if(sizeCircle!=NULL)
            {
                sizeCircle->centerX=centerX;
                sizeCircle->centerY=centerY;
                sizeCircle->radius=radius;
                sizeCircle->square=theSquare(sizeCircle);

                mainCircle->current_size++;
            }
            else
            {
                return -3;
            }
        }
        else
        {
            return -2;
        }

    return 0;
}

//count square
float theSquare(circle *mainCircle)
{
    return PI*(powf((mainCircle->radius), 2));
}
