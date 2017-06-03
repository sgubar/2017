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


void printFigure(FigureList *aFigure) 
{ 
 int i, j;
  for ( i = 0; i < aFigure->current_size; i++) 
   { 

     Figure *theFigure = &(aFigure->triangle[i]); 
     	
	printf("\n - - - - -  Figure #%d - - - - - \n\n", i + 1); 
	printf("Square  : %.2f\n", (float)square(theFigure)); //print square figure;
   } 
}
    
int square(Figure *Figure)
{
			float square;
			printf("Point 1 : [%i;%i] \n", Figure->Coordinates[0].x, Figure->Coordinates[0].y);
			printf("Point 2 : [%i;%i] \n", Figure->Coordinates[1].x, Figure->Coordinates[1].y);
			printf("Point 3 : [%i;%i] \n", Figure->Coordinates[2].x, Figure->Coordinates[2].y);
			
			square = abs((((Figure->Coordinates[0].x - Figure->Coordinates[2].x) * (Figure->Coordinates[1].y) - Figure->Coordinates[2].y) - ((Figure->Coordinates[1].x - Figure->Coordinates[2].x) * (Figure->Coordinates[0].y - Figure->Coordinates[2].y)))/2);
			return square;	
}


void WriteToFile_List(FILE *file, FigureList *aFigure)
{
			fprintf(file, "Quanity of triangles : %d \n", aFigure->current_size);
			fprintf(file, " - - - - - - - - - - - - - - List of triangles - - - - - - - - - - - - - - \n");
			
			if (NULL != aFigure->triangle)
	        {
	           	for (int i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->triangle[i]);
					fprintf(file, "-Triangle #%i-\n", i+1);
	           		WriteToFile_Triangle(file, theFigure);
	           		fprintf(file, "\n");
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
	fprintf(file, "|Point %i : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
    }
}
