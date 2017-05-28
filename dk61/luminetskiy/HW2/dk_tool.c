#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

#define PI 3.14 

//main: delete and create
FigList *createCircle(int size)
{
    FigList *aFigList=(FigList *)malloc(sizeof(FigList));

    if(aFigList!=NULL)
    {
        aFigureList->sizeCircle=(circle *)malloc(size*sizeof(circle));
        aFigureList->current_size=0;
        aFigureList->size=size;
    }
    return aFigureList;
}

void destroyFigure(circleList *aCircleList)
{
    if (aCircleList!=NULL)
    {
        if(aCircleList->sizeCircle!=NULL)
            free(aCircleList->sizeCircle);

        free(aCircleList);
    }
}

//interface
int addToFigure(FigList *aFigList, int x, int y, int rad);
{
        if(aCircleList->current_size < aCircleList->size)
        {
            circle *sizeCircle=&(aCircleList->sizeCircle[aCircleList->current_size]);
            if(sizeCircle!=NULL)
            {
                sizeCircle->x=x;
                sizeCircle->y=y;
                sizeCircle->rad=rad;

                aCircleList->current_size++;
            }
            else
            {
                return -2;
            }
        }
        else
        {
            return -1;
        }

    return 0;
}
 
void print(FigList *aFigureList);
{
    int CircleCounter=0;
    while(aFigList->current_size > CircleCounter)
    {
        circle *sizeCircle=&(aFigList->sizeCircle[CircleCounter]);
        printf("%d)Center (x, y): (%.3f, %.3f)\n", CircleCounter+1, sizeCircle->x, sizeCircle->y);
        printf("  Radius: %.3f\n", sizeCircle->rad);
        printf("  Square: %.3lf\n", theSquare(sizeCircle));
        CircleCounter++;
    }
}

//count square
float Square (Circle *aCircle)
{
	return 3.14159*aCircle->radius * aCircle->radius;
}
