#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tool.h"

 
FigureList *createFigureList(int aSize)
{
    FigureList *List = (FigureList *)malloc(sizeof(FigureList));
    if(List != NULL)
	{
		List->paralel = (Figure *)malloc(aSize * sizeof(Figure));
		memset(List->paralel, 0, sizeof(Figure));
		List->size = aSize;
		List->current_size = 0;		
	}
	return List;
}

int addCoor(FigureList *aFigure)
{
	if(NULL != aFigure )
	{
		if(aFigure -> current_size < aFigure->size)
		{
			Figure *theFigure = &(aFigure->paralel[aFigure->current_size]);
			if( NULL != theFigure)
			{ int num, i=0;
			  theFigure->points = (Point *)malloc(sizeof(Point)*8);
				for(i=0; i<8; i++)
				{
				printf("Enter the point[%d]\n", i+1);
				theFigure->points[i].x = scan_f();
				theFigure->points[i].y = scan_f();
			    theFigure->points[i].z = scan_f();
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
    
}

void destroyFigureList(FigureList *aFigure)
{
	if(NULL != aFigure)
	{
		if(NULL != aFigure-> paralel)
		{
			free(aFigure-> paralel);
		}
		free(aFigure);
	}
}

int printFigure(FigureList *aFigure) 
{ 
 int i, j;
  for ( i = 0; i < aFigure->current_size; i++) 
   { 

     Figure *theFigure = &(aFigure->paralel[i]); 
     	
	printf("Figure [%d]\n", i + 1);
	printf("the square of that figure is %d\n\n", abs(square(theFigure)));

     for (j = 0; j < 8; j++) 
      { 

      printf("point[%d]={%d, %d, %d}\n", j+1, theFigure->points[j].x, theFigure->points[j].y, theFigure->points[j].z); 

      }    

   } 
   return 0; 
}

int scan_f(void)
	{
     int num = 0;
			
     scanf("%d", &num);

	return num;
    }
    
int square(Figure *Figure)
{
	double PA = 0;
			double L12 = 0;
			double L23 = 0;
			double L15 = 0;
			double L25 = 0;
			double L27 = 0;
			double L13 = 0;
			double S1,S2,S3,square;
			double x=0, y=0, z=0;
			square = 0;
			
			x = (Figure->points[1].x) - (Figure->points[2].x);
			y = (Figure->points[1].y) - (Figure->points[2].y);
			z = (Figure->points[1].z) - (Figure->points[2].z);
			L12 = sqrt((x*x) + (y*y) + (z*z));
			x=0; y=0; z=0;

			x = (Figure->points[2].x) - (Figure->points[3].x);
			y = (Figure->points[2].y) - (Figure->points[3].y);
			z = (Figure->points[2].z) - (Figure->points[3].z);
			L23 = sqrt((x*x) + (y*y) + (z*z));
			x=0; y=0; z=0;

			x = (Figure->points[2].x) - (Figure->points[5].x);
			y = (Figure->points[2].y) - (Figure->points[5].y);
			z = (Figure->points[2].z) - (Figure->points[5].z);
			L25 = sqrt((x*x) + (y*y) + (z*z));
			x=0; y=0; z=0;
			
			S1=(L12*L23)/2;
			S2=(L25*L23)/2;
			S3=(L25*L12)/2;
			square =(4*S1)+(4*S2)+(4*S3);
			return square;			
}
