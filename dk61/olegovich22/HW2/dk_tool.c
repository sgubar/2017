#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

#define PI 3.14

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
//count square
float theSquare(float centerX, float centerY, float radiusX, float radiusY)
{
    return PI*(powf((radiusX-centerX), 2)+powf((radiusY-centerY), 2));
}

//interface
int addToCircle(optionCircle *mainCircle, float centerX, float centerY, float radiusX, float radiusY)
{
        if(mainCircle->current_size<mainCircle->size)
        {
            circle *sizeCircle=&(mainCircle->sizeCircle[mainCircle->current_size]);
            if(sizeCircle!=NULL)
            {
                sizeCircle->centerX=centerX;
                sizeCircle->centerY=centerY;
                sizeCircle->radiusX=radiusX;
                sizeCircle->radiusY=radiusY;
                sizeCircle->square=theSquare(centerX, centerY, radiusX, radiusY);

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

