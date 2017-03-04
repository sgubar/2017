#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

#define PI 3.14 //const in math

//main: delete and create
circleList *createCircle(int size)
{
    circleList *aCircleList=(circleList *)malloc(sizeof(circleList));

    if(aCircleList!=NULL)
    {
        aCircleList->sizeCircle=(circle *)malloc(size*sizeof(circle));
        aCircleList->current_size=0;
        aCircleList->size=size;
    }
}

void destroyAllCircle(circleList *aCircleList)
{
    if (aCircleList!=NULL)
    {
        if(aCircleList->sizeCircle!=NULL)
            free(aCircleList->sizeCircle);

        free(aCircleList);
    }
}

//interface
int addToCircle(circleList *aCircleList, float centerX, float centerY, float radius)
{
        if(aCircleList->current_size < aCircleList->size)
        {
            circle *sizeCircle=&(aCircleList->sizeCircle[aCircleList->current_size]);
            if(sizeCircle!=NULL)
            {
                sizeCircle->centerX=centerX;
                sizeCircle->centerY=centerY;
                sizeCircle->radius=radius;
                sizeCircle->square=theSquare(sizeCircle);

                aCircleList->current_size++;
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
float theSquare(circle *aCircle)
{
    return PI*(powf((aCircle->radius), 2));
}
