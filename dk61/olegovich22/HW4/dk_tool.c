#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

#define PI 3.14 //const in math

//make code more beautiful
#define enter fprintf(aFile, "\n")
#define coma fprintf(aFile, ",")
#define space fprintf(aFile, " ")



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


//get users choice type of sort from user
int getChoiceTypeSort()
{
    int numb=0;
    printf("\nPlease make a choice type of sorting:\n");
    printf("Enter 1 - bubble sorting\n");
    printf("Enter 2 - select sorting\n");
    printf("Enter 3 - insert sorting\n");
    do
    {
        int aChek=scanf("%d", &numb);
        rewind(stdin); //clear buffer in scanf
        if (numb<1 || numb>3 || aChek!=1)
            printf("ERROR. Please make a choice and enter one ineger from 1 to 3\n");
    }
    while(numb<1 || numb>3);

    return numb;
}


void printCircles(circleList *aCircleList)
{
    int CircleCounter=0;
    while(aCircleList->current_size > CircleCounter)
    {
        circle *sizeCircle=&(aCircleList->sizeCircle[CircleCounter]);
        printf("%d)Center (x, y): (%.3f, %.3f)\n", CircleCounter+1, sizeCircle->centerX, sizeCircle->centerY);
        printf("  Radius: %.3f\n", sizeCircle->radius);
        CircleCounter++;
    }
}

//count square
double theSquare(circle *aCircle)
{
    return PI*(powf((aCircle->radius), 2));
}

//write into file
int writeCircleList(FILE *aFile, circleList *aCircleList)
{
    if (aFile==NULL && aCircleList==NULL)
    {
        return -1;
    }
    else
    {
        fprintf(aFile, "{");
        enter;
        fprintf(aFile, "\"Size\": %d", aCircleList->size);coma;
        enter;
        fprintf(aFile, "\"Current_size\": %d", aCircleList->current_size);coma;
        enter;
        fprintf(aFile, "\"Circles\":");

        if (NULL == aCircleList->sizeCircle)
        {
            fprintf(aFile, "null");
        }
        else
        {
            fprintf(aFile, "[");
            enter;

            for (int i=0; i<aCircleList->current_size ; i++)
            {
                circle *aCircle=&(aCircleList->sizeCircle[i]);
                space;

                writeCircle(aFile, aCircle);

                if(i < aCircleList->current_size-1)
                {
                    coma;
                    enter;
                }
            }
            fprintf(aFile, "]");
        }
        enter;
        fprintf(aFile, "}");
    }


}
void writeCircle(FILE *aFile, circle *aCircle)
{
    fprintf(aFile, "{");
    fprintf(aFile, "\"CenterX\": %.3f", aCircle->centerX);coma;
    fprintf(aFile, "\"CenterY\": %.3f", aCircle->centerY);coma;
    fprintf(aFile, "\"Radius\": %.3f", aCircle->radius);
    fprintf(aFile, "}");
}