#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "t.h"
#include "sort.h"
#include "binary.h"

ListFigures *CreateListFigure (int aSize)
{

    ListFigures *aFigures = (ListFigures*) malloc(sizeof(ListFigures));

    if (NULL != aFigures)
    {
        aFigures->Rectangles = (Rectangle *)malloc(sizeof(Rectangle) * aSize);
        memset(aFigures->Rectangles, 0, aSize * sizeof(Rectangle));
        aFigures->size = aSize;
        aFigures->current_size = 0;
    }
    return aFigures;
};



void DestroyList (ListFigures * aFigures)
{
    if (NULL != aFigures)
    {
        if(NULL != aFigures->Rectangles)
        {
            for (int i = 0; i < aFigures->current_size; i++)
            {
                Rectangle *theLinkTolist = &(aFigures->Rectangles[i]);

                if (NULL != theLinkTolist->Point)
                {
                    free(theLinkTolist->Point);
                }
            }
            free(aFigures->Rectangles);
        }
        free(aFigures);
    }
    printf("Deleting is completed");
};


void swap(Rectangle *var1, Rectangle *var2)
{
    Rectangle temp = *var1;
    *var1 = *var2;
    *var2 = temp;
};



int AddRectangle(ListFigures * aFigures)
{
    int theResult = 0;
    if (NULL != aFigures)
    {
        if (aFigures->current_size < aFigures->size)
        {
            Rectangle *Figures = &(aFigures->Rectangles[aFigures->current_size]);

            Figures->Point = (RectanglePoint *) malloc(sizeof(RectanglePoint)*4);


            for(int i= 0; i<4; i++)
            {
                printf("\t Point[%i]:\n",i+1);
                printf("\t X[%d] : ",i+1);
                scanf("%i", &Figures->Point[i].x);
                printf("\t Y[%d] : ",i+1);
                scanf("%d", &Figures->Point[i].y);
                printf("\n");
            }

            aFigures->current_size ++;
        }
        else
            {
            theResult = -2;//full
            }
    }
    else
    {
        theResult = -1;//already exist
    }
    printf("\t \tRectangle is created-----------------------------------------------------------------------------------\n\n");
    return theResult;
};




int Square(Rectangle * aFigures)
{

   double result;

    result = sqrt( pow(aFigures->Point[0].x - aFigures->Point[1].x,2) + pow(aFigures->Point[0].y - aFigures->Point[1].y,2))+
                    sqrt( pow(aFigures->Point[2].x - aFigures->Point[3].x,2) + pow(aFigures->Point[2].y - aFigures->Point[3].y,2)) ;
    return result;
};



 int printRectangle(Rectangle*theRectangle)
{
    if (NULL == theRectangle)
        printf("NULL");
    else
    {
        for (int i = 0; i < 4; i++)
        {
            printf("Point[%d]={%d, %d}\n",i+1, theRectangle->Point[i].x, theRectangle->Point[i].y);
        }
    }
    return 0;
};



void printRectangleList(ListFigures *aRectangleList)
{


    for (int i = 0; i < aRectangleList->current_size; i++)
    {
        Rectangle *theRectangle = &(aRectangleList->Rectangles[i]);
        printf("\t Rectangle #%d\n", i+1);
        printRectangle(theRectangle);
        printf("\t \t \t Square of %d rectangle is %d\n\n", i+1,abs(Square(theRectangle)));

    }
};





void searching(ListFigures * aFigures, int value)
{
    int bin;
    fflush(stdin);
    printf("   Enter the Square Of Rectangle\n");
    scanf("%d", &value);

	bin = binarySearch(aFigures, value);

	if (bin == -1)
	{
             printf("   There are no such pyramid with square %d\n\n", value);
        while (bin < 0)
	        {
            printf("Try again:\n");
            scanf(" %d", &value);
            bin = binarySearch(aFigures, value);
            }
    }
}



void sorting(ListFigures * aFigures)
{
    char sort;

    printf("Choose type of sorting\n");
    printf("1   -  Bubble_Sort\n");
    printf("2   -  Selection_Sort\n");
    printf("3   -  Insertion_Sort\n");
    printf("4   -  shellSort\n");

    scanf("\t \t %c", &sort);

    while (!strchr("1234", sort))
    {
        printf("From 1 to 4 \n");
        scanf(" %c", &sort);
    }

    printf("		BEFORE SORTING---------------------------------------------------------\n");
    printRectangleList(aFigures);

   switch (sort)
	{
        case '1':
            Bubble_Sort(aFigures);

            break;

        case '2':
            Selection_Sort(aFigures);

            break;

        case '3':
            Insertion_Sort(aFigures);
            break;

        case '4':
           shellSort(aFigures);
            break;

    }
    printf("		AFTER SORTING------------------------------------------------------------\n");
    printRectangleList(aFigures);


};











