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
    return aCircleList;
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

void print(circleList *aCircleList)
{
    int CircleCounter=0;
    while(aCircleList->current_size > CircleCounter)
    {
        circle *sizeCircle=&(aCircleList->sizeCircle[CircleCounter]);
        printf("%d)Center (x, y): (%.3f, %.3f)\n", CircleCounter+1, sizeCircle->centerX, sizeCircle->centerY);
        printf("  Radius: %.3f\n", sizeCircle->radius);
        printf("  Square: %.3lf\n", theSquare(sizeCircle));
        CircleCounter++;
    }
}

//count square
double theSquare(circle *aCircle)
{
    return PI*(powf((aCircle->radius), 2));
}