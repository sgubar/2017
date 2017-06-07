#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tool.h"

 
FigureList *createFigureList(int aSize) //create List of Figure;
{
    FigureList *List = (FigureList *)malloc(sizeof(FigureList));  //create List and memory;
    if(List != NULL)
	{
		List->square = (Figure *)malloc(aSize * sizeof(Figure)); //create memory for figure;
		memset(List->square, 0, sizeof(Figure));
		List->size = aSize;          //quantity of figure;
		List->current_size = 0;		//flag of figure;
	}
	return List;
}

int FillCoord(FigureList *aFigure) //adding coordinate of points;
{
	if(NULL != aFigure )
	{
		if(aFigure -> current_size < aFigure->size)
		{
			Figure *theFigure = &(aFigure->square[aFigure->current_size]);
			if( NULL != theFigure)
			{ int i=0;
			
			  theFigure->Coordinates = (Point *)malloc(sizeof(Point)*6); //create memory for points;
			    printf("\nFill a square by points: \n");
				for(i=0; i<4; i++)
				{
				printf("Enter X to point %i : ", i+1);
				scanf("%i", &theFigure->Coordinates[i].x);
				
				printf("Enter Y to point %i : ", i+1);
				scanf("%i", &theFigure->Coordinates[i].y);
		
			    }
				aFigure->current_size ++;
			}
		}
		else
		return -2;
	}
	else
	{
	    return -1;
    }
    return 0;
}

    
int area(Figure *Figure)
{
			float area;
			area = (((Figure->Coordinates[0].x * Figure->Coordinates[1].y) - (Figure->Coordinates[0].y) * Figure->Coordinates[1].x) +
			          ((Figure->Coordinates[1].x * Figure->Coordinates[2].y) - (Figure->Coordinates[1].y) * Figure->Coordinates[2].x) +
			          ((Figure->Coordinates[2].x * Figure->Coordinates[3].y) - (Figure->Coordinates[2].y) * Figure->Coordinates[3].x) +
			          ((Figure->Coordinates[3].x * Figure->Coordinates[0].y) - (Figure->Coordinates[3].y) * Figure->Coordinates[0].x))/2;
			return area;	
}


void WriteToFile_List(FILE *file, FigureList *aFigure)
{
			if (NULL != aFigure->square)
	        {
	        	printf("\n");
	           	for (int i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->square[i]);
	           		printf("-Square #%i-\n", i+1);
					fprintf(file, "-Square #%i-\n", i+1);
	           		WriteToFile_Square(file, theFigure);
	           		printf("|Area : %.0f|\n\n", (double) area(theFigure));
	           		fprintf(file, "|Area : %.0f|\n\n", (double) area(theFigure));
				}
			} 
	        else
			{
		       fprintf(file, "Slot is empty");
	        }
}

void WriteToFile_Square(FILE *file, Figure *aFigure)
{	
	for (int cnt = 0; cnt < 4; cnt++)
    {
    printf("Point (%i) : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
	fprintf(file, "Point (%i) : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
    }
}

void SelectionSort(FigureList *aFigure)
{
	int theOut, theIn;
	for (theOut = 0; theOut <aFigure->current_size-1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aFigure->current_size; theIn ++)
		{
			if (area(&aFigure->square[theIn])<area(&aFigure->square[theMinIndex])) //> to <
			{
				theMinIndex = theIn;
			}
		}
	
		Figure theTmp = aFigure->square[theOut];
		aFigure->square[theOut] =aFigure->square[theMinIndex];
	    aFigure->square[theMinIndex] = theTmp;
	}
}
