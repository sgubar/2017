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
		List->triangle = (Figure *)malloc(aSize * sizeof(Figure)); //create memory for figure;
		memset(List->triangle, 0, sizeof(Figure));
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
			Figure *theFigure = &(aFigure->triangle[aFigure->current_size]);
			if( NULL != theFigure)
			{ int i=0;
			
			  theFigure->Coordinates = (Point *)malloc(sizeof(Point)*6); //create memory for points;
			    printf("\nFill a triangle by points: \n");
				for(i=0; i<3; i++)
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

    
int square(Figure *Figure)
{
			float square;
			square = abs((((Figure->Coordinates[0].x - Figure->Coordinates[2].x) * (Figure->Coordinates[1].y) - Figure->Coordinates[2].y) - ((Figure->Coordinates[1].x - Figure->Coordinates[2].x) * (Figure->Coordinates[0].y - Figure->Coordinates[2].y)))/2);
			return square;	
}


void WriteToFile_List(FILE *file, FigureList *aFigure)
{
			if (NULL != aFigure->triangle)
	        {
	        	printf("\n");
	           	for (int i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->triangle[i]);
	           		printf("-Triangle #%i-\n", i+1);
					fprintf(file, "-Triangle #%i-\n", i+1);
	           		WriteToFile_Triangle(file, theFigure);
	           		printf("|Square : %.0f|\n\n", (double) square(theFigure));
	           		fprintf(file, "|Square : %.0f|\n\n", (double) square(theFigure));
				}
			} 
	        else
			{
		       fprintf(file, "Slot is empty");
	        }
}

void WriteToFile_Triangle(FILE *file, Figure *aFigure)
{	
	for (int cnt = 0; cnt < 3; cnt++)
    {
    printf("|Point %i : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
	fprintf(file, "|Point %i : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
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
			if (square(&aFigure->triangle[theIn])<square(&aFigure->triangle[theMinIndex])) //> to <
			{
				theMinIndex = theIn;
			}
		}
	
		Figure theTmp = aFigure->triangle[theOut];
		aFigure->triangle[theOut] =aFigure->triangle[theMinIndex];
	    aFigure->triangle[theMinIndex] = theTmp;
	}
}
