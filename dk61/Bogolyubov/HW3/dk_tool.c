#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tool.h"

 
PtsList *createPtsList(int aSize) //create List of Pts;
{
    PtsList *List = (PtsList *)malloc(sizeof(PtsList));  //create List and memory;
    if(List != NULL)
	{
		List->square = (Pts *)malloc(aSize * sizeof(Pts)); //create memory for pts;
		memset(List->square, 0, sizeof(Pts));
		List->size = aSize;          //quantity of pts;
		List->current_size = 0;		//flag of pts;
	}
	return List;
}

int fillList(PtsList *aPts) //adding coordinate of coords;
{
	if(NULL != aPts )
	{
		if(aPts -> current_size < aPts->size)
		{
			Pts *thePts = &(aPts->square[aPts->current_size]);
			if( NULL != thePts)
			{ int i=0;
			
			  thePts->coords = (Coord *)malloc(sizeof(Coord)*8); //create memory for coords;
			    printf("\nFill a square by coords: \n");
				for(i=0; i<4; i++)
				{
				printf("Enter X to coord %i : ", i+1);
				scanf("%i", &thePts->coords[i].x);
				
				printf("Enter Y to coord %i : ", i+1);
				scanf("%i", &thePts->coords[i].y);
		
			    }
				aPts->current_size ++;
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


void printPts(PtsList *aPts) 
{ 

 int i, j;
  for ( i = 0; i < aPts->current_size; i++) 
   { 

     Pts *thePts = &(aPts->square[i]); 
     	
	printf("-------------------------\n"); 
	printf("Area: %.2f\n", (float)square(thePts)); //print square pts;
   } 
}
    
int square(Pts *Pts)
{

			float area;
			
			
			
			area =    (((Pts->coords[0].x * Pts->coords[1].y) - (Pts->coords[0].y) * (Pts->coords[1].x)) + 
			          (((Pts->coords[1].x) * (Pts->coords[2].y)) - ((Pts->coords[1].y) * (Pts->coords[2].x))) + 
			          (((Pts->coords[2].x) * (Pts->coords[3].y)) - ((Pts->coords[2].y) * (Pts->coords[3].x))) + 
					  (((Pts->coords[3].x) * (Pts->coords[1].y)) - ((Pts->coords[3].y) * (Pts->coords[1].x))))/2;
					  
					  if(area<0){
					  area *= -1;
					  }
					  
					  printf("Coord 1 : [%i;%i] \n", Pts->coords[0].x, Pts->coords[0].y); //a
			printf("Coord 2 : [%i;%i] \n", Pts->coords[1].x, Pts->coords[1].y); //b
			printf("Coord 3 : [%i;%i] \n", Pts->coords[2].x, Pts->coords[2].y); //c
			printf("Coord 4 : [%i;%i] \n", Pts->coords[3].x, Pts->coords[3].y); //d
					  	
			return area;
					
}

void WriteToFile_List(FILE *file, PtsList *aFigure)
{
			if (NULL != aFigure->square)
	        {
	           	for (int i = 0; i < aFigure->current_size; i++)
	           	{
	           		Pts *theFigure = &(aFigure->square[i]);
					fprintf(file, "square ?%i", i+1);
	           		WriteToFile_Square(file, theFigure);
	           		fprintf(file, "\n");
				}
			} 
	        else
			{
		       fprintf(file, "Slot is empty");
	        }
}

void WriteToFile_Square(FILE *file, Pts *aFigure)
{	
	for (int i = 0; i < 4; i++)
    {
	fprintf(file, "Point %i: %i;%i\n", i+1, aFigure->coords[i].x, aFigure->coords[i].y);
    }
}
