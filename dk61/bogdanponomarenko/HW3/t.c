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
        aFigures->Rectangles = (Rectangle *)malloc(sizeof(ListFigures));

        memset (aFigures->Rectangles,0,aSize * sizeof(RectanglePoint));
                        aFigures->size = aSize;
                                 aFigures->current_size = 0;
    }
    return aFigures;
}


void Coordinates(RectanglePoint*PointA, RectanglePoint*PointB, RectanglePoint*PointC, RectanglePoint*PointD )
{
    printf("Coordinate_X_A: ");
        scanf("%i",&PointA->x);
    printf("Coordinate_Y_A: ");
        scanf("%i",&PointA->y);

    printf("\nCoordinate_X_B: ");
        scanf("%i",&PointB->x);
    printf("Coordinate_Y_B: ");
        scanf("%i",&PointB->y);

    printf("\nCoordinate_X_C: ");
        scanf("%i",&PointC->x);
    printf("Coordinate_Y_C: ");
        scanf("%i",&PointC->y);

    printf("\nCoordinate_X_D: ");
        scanf("%i",&PointD->x);
    printf("Coordinate_Y_D: ");
        scanf("%i",&PointD->y);
}

int AddRectangle(ListFigures * AFigures)
{
    int theResult = 0;
    if (NULL != AFigures)
    {
       for (int  i = 0; i  < AFigures->size;  i++)
        {
            Rectangle *Figures = &AFigures->Rectangles[AFigures->current_size];

            Figures->PointA = (RectanglePoint *) malloc(sizeof(RectanglePoint));

            Figures->PointB = (RectanglePoint *) malloc(sizeof(RectanglePoint));

            Figures->PointC = (RectanglePoint *) malloc(sizeof(RectanglePoint));

            Figures->PointD = (RectanglePoint *) malloc(sizeof(RectanglePoint));

            printf("Coordinates(x,y) For Figure #%i:\n\n", AFigures->current_size + 1);

            Coordinates(Figures->PointA, Figures->PointB, Figures->PointC, Figures->PointD);

            AFigures->current_size++;
        }

        {
            theResult = -2;
        }
    }
    else
    {
        theResult = -1;
    }
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
                if (NULL != theLinkTolist->PointA &&NULL != theLinkTolist->PointB && NULL != theLinkTolist->PointC && NULL != theLinkTolist->PointD)
                {
                    free(theLinkTolist->PointA);
                        free(theLinkTolist->PointB);
                            free(theLinkTolist->PointC);
                                free(theLinkTolist->PointD);
                }
            }
            free(AFigures->Rectangles);
        }
        free(AFigures);
    }
};




double Square(Rectangle * rectangle)
{
    double result = sqrt( pow(rectangle->PointA->x - rectangle->PointB->x,2) + pow(rectangle->PointA->y - rectangle->PointB->y,2)) *
                    sqrt( pow(rectangle->PointB->x - rectangle->PointC->x,2) + pow(rectangle->PointB->y - rectangle->PointC->y,2));
    return result;
};


void PrintSquare(ListFigures *FiguresNumber)
{
    for (int i = 0; i < FiguresNumber->current_size+1; i++)
    {
        Rectangle *Figure = &(FiguresNumber->Rectangles[i]);

        printf("\nSquare For Figure #%d = %.2f\n\n",i+1,Square(Figure));
    }
};

void writeRectangle(FILE *aFile, Rectangle *aNote)
{
    fprintf (aFile, "{");
    fprintf(aFile, "\n");



    fprintf (aFile,"\t\t");
        fprintf (aFile, "{");
            fprintf (aFile,"\t\t");
                fprintf (aFile,  "Coordinate_X_A = %d , Coordinate_Y_A: %d" ,aNote->PointA->x , aNote->PointA->y);
                    fprintf (aFile, ";");
                        fprintf (aFile, "}");

    fprintf (aFile,"\t\t");
        fprintf (aFile, "{");
            fprintf (aFile,"\t\t");
                fprintf (aFile,  "Coordinate_X_A = %d , Coordinate_Y_A: %d" ,aNote->PointA->x , aNote->PointA->y);
                    fprintf (aFile, ";");
                        fprintf (aFile, "}");

    fprintf (aFile,"\t\t");
        fprintf (aFile, "{");
            fprintf (aFile,"\t\t");
                fprintf (aFile,  "Coordinate_X_A = %d , Coordinate_Y_A: %d" ,aNote->PointA->x , aNote->PointA->y);
                    fprintf (aFile, ";");
                        fprintf (aFile, "}");

    fprintf (aFile,"\t\t");
        fprintf (aFile, "{");
            fprintf (aFile,"\t\t");
                fprintf (aFile,  "Coordinate_X_A = %d , Coordinate_Y_A: %d" ,aNote->PointA->x , aNote->PointA->y);
                    fprintf (aFile, ";");
                        fprintf (aFile, "}");


    fprintf (aFile,"\n");
        fprintf (aFile, "}");
    fprintf (aFile,"\n");
    fprintf (aFile,"\n");
        fprintf (aFile, "}");
    fprintf (aFile,"\n");
    fprintf (aFile,"\n");
        fprintf (aFile, "}");
    fprintf (aFile,"\n");
    fprintf (aFile,"\n");
        fprintf (aFile, "}");
}


void writeList(FILE *aFile, ListFigures * AFigures)
{
    fprintf(aFile, "{");
    fprintf(aFile, "\n");

    if (NULL == AFigures->Rectangles) {
        fprintf(aFile, "NULL");
    } else {
        fprintf(aFile, "\n");
        fprintf(aFile, "Rectangles:\n");
        fprintf(aFile, "\t");
        fprintf(aFile, "{");
        fprintf(aFile, "\n");

        for (int i = 0; i < AFigures->current_size; i++)
        {
            Rectangle *theNote = &(AFigures->Rectangles[i]);

            writeRectangle(aFile, theNote);

            if (i < (AFigures->current_size-1 ))
            {
                fprintf(aFile, ",");
            }
        }
        fprintf(aFile, "}");

        fprintf(aFile, "}");
    }
}




