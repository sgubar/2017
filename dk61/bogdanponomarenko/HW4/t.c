
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t.h"
#include <math.h>

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


int AddRectangle(ListFigures * AFigures)
{
    int theResult = 0;
    if (NULL != AFigures)
    {
        if (AFigures->current_size < AFigures->size)
        {
            Rectangle *Figures = &(AFigures->Rectangles[AFigures->current_size]);

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

            AFigures->current_size ++;
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
    printf("\t \tRectangle is created-------------------------------------------------------------------------------------------\n\n");
    return theResult;
};



void DestroyList (ListFigures * AFigures)
{
    if (NULL != AFigures)
    {
        if(NULL != AFigures->Rectangles)
        {
            for (int i = 0; i < AFigures->current_size; i++)
            {
                Rectangle *theLinkTolist = &(AFigures->Rectangles[i]);

                if (NULL != theLinkTolist->Point)
                {
                    free(theLinkTolist->Point);
                }
            }
            free(AFigures->Rectangles);
        }
        free(AFigures);
    }
    printf("Deleting is completed");
};




double Square(Rectangle * Figures) {
    /*    double AB = sqrt( pow(Figures->Point[0].x - Figures->Point[1].x,2) + pow(Figures->Point[0].y - Figures->Point[1].y,2));
        double BC = sqrt( pow(Figures->Point[1].x - Figures->Point[2].x,2) + pow(Figures->Point[1].y - Figures->Point[2].y,2));
   	double CD = sqrt( pow(Figures->Point[2].x - Figures->Point[3].x,2) + pow(Figures->Point[2].y - Figures->Point[3].y,2));
	double DA = sqrt( pow(Figures->Point[3].x - Figures->Point[4].x,2) + pow(Figures->Point[3].y - Figures->Point[4].y,2));
	double AC = sqrt( pow(Figures->Point[0].x - Figures->Point[2].x,2) + pow(Figures->Point[0].y - Figures->Point[2].y,2));
	double S_1,S_2,result;
S_1 = (1/4)*sqrt((AB+BC+AC)*(AB+BC-AC)*(AB+AC-BC)*(AC+BC-AB));
S_2 = (1/4)*sqrt((DA+CD+AC)*(DA+CD-AC)*(DA+AC-CD)*(CD+AC-DA));

return result = S_1+S_2;*/
    double result = sqrt( pow(Figures->Point[0].x - Figures->Point[1].x,2) + pow(Figures->Point[0].y - Figures->Point[1].y,2))*
                    sqrt( pow(Figures->Point[1].x - Figures->Point[2].x,2) + pow(Figures->Point[1].y - Figures->Point[2].y,2)) ;
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
        printf("\t Rectangle #%d\n", i + 1);
        printRectangle(theRectangle);
        printf("\t \t \t Square of %d rectangle is %.2f\n\n", i+1,Square(theRectangle));

    }
};



void swap(Rectangle *var1, Rectangle *var2)
{
    Rectangle temp = *var1;
    *var1 = *var2;
    *var2 = temp;
};



void writeRectangle(FILE *aFile, Rectangle*theRectangle)
{



    for (int i = 0; i < 3; i++) {
        fprintf(aFile, " \"Point[%d]\"={%d,%d},\n", i + 1, theRectangle->Point[i+1].x, theRectangle->Point[i+1].y);
        if (i == 2)
            fprintf(aFile, " \"Point[%d]\"={%d,%d}\n", i + 1, theRectangle->Point[i+1].x, theRectangle->Point[i+1].y);

    }

};


void writeList(FILE *aFile, ListFigures *AFigures)
{
    fprintf(aFile, "{\n");
    fprintf(aFile, "  \"size\":%d;\n", AFigures->size);
    fprintf(aFile, "  \"current_size\":%d;\n\n", AFigures->current_size);
    fprintf(aFile, "\"Rectangles\":[\n");


     for (int i = 0; i < AFigures->current_size; i++)
     {
         Rectangle *theRectangle = &(AFigures->Rectangles[i]);

         fprintf(aFile, " \"Rectangle #%d\" :\n\n", i + 1);
         fprintf(aFile, "{\n");
         writeRectangle(aFile, theRectangle);
         if (i < AFigures->current_size-1) {
             fprintf(aFile, "},\n\n");
         }
         else
         if(i<=AFigures->current_size-1)
             fprintf(aFile, "}\n\n");




     }
     fprintf(aFile, "]\n");
     fprintf(aFile, "}\n");
     
};











