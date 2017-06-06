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
				{ 
				int i=0;
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


	void PrintList(FigureList *aFigure)
	{
			if (NULL != aFigure->triangle)
	        {
	        	printf("\n");
	           	for (int i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->triangle[i]);
	           		printf("-Triangle #%i-\n", i);
	           		PrintTriangle(theFigure);
	           		printf("|Square : %.0f|\n\n", (double) square(theFigure));
				}
			} 
	        else
			{
		       printf("Slot is empty");
	        }
	}

	void PrintTriangle(Figure *aFigure)
	{	
		for (int cnt = 0; cnt < 3; cnt++)
    	{
    	printf("|Point %i : [%i;%i]|\n", cnt+1, aFigure->Coordinates[cnt].x, aFigure->Coordinates[cnt].y);
    	}
	}
	
void ShellSort(FigureList *aFigure)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= aFigure->current_size/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aFigure->current_size; theOuter ++)
		{
			Figure Tmp = aFigure->triangle[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && square(&aFigure->triangle[theInner-theH]) >= square(&Tmp))   //change >= to <=
			{
				aFigure->triangle[theInner] = aFigure->triangle[theInner-theH];
				theInner -= theH;
			}
			aFigure->triangle[theInner] = Tmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}

int BinarySearch(FigureList *aFigure, int key)
{
	printf("\n -Binary Search-\nEnter square value to find : ");

	int value_checker =  scanf("%i", &key);
	while (value_checker == 0)
	{
		fflush(stdin);
		printf("Incorrect value. Try again : ");
		value_checker = scanf("%i", &key);
	}
	if (value_checker == 1)
	{
		 printf("You entered : %i\n", key );
	}
		
	
	int left = 0;
	int right = aFigure->current_size;
	int middle = 0; int triangle_position=0;
	
	while(left < right)
	{
		middle = (left + right)/2;
		
		if (square(&aFigure->triangle[middle]) == key)
			{
			int triangle_position = middle;
			printf("\n*!Found. Figure #%i!*\n", triangle_position);
			break;
			}	
		else
		{
			if (square(&aFigure->triangle[middle]) > key)
				{
				right = middle - 1;
				}
			else
				{
				left = middle + 1;
				}
		}
	
	}
		return -1;	
}
