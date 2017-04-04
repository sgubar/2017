#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tool.h"

 
FigureList *createFigureList(int aSize) //create List of Figure;
{
    FigureList *List = (FigureList *)malloc(sizeof(FigureList));  //create List and memory;
    if(List != NULL)
	{
		List->paralel = (Figure *)malloc(aSize * sizeof(Figure)); //create memory for figure;
		memset(List->paralel, 0, sizeof(Figure));
		List->size = aSize;          //quantity of figure;
		List->current_size = 0;		//flag of figure;
	}
	return List;
}

int addCoor(FigureList *aFigure) //adding coordinate of points;
{
	if(NULL != aFigure )
	{
		if(aFigure -> current_size < aFigure->size)
		{
			Figure *theFigure = &(aFigure->paralel[aFigure->current_size]);
			if( NULL != theFigure)
			{ int i=0;
			  theFigure->points = (Point *)malloc(sizeof(Point)*8); //create memory for points;
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
    return 0;
}

void destroyFigureList(FigureList *aFigure) //delete List;
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

void printFigure(FigureList *aFigure) 
{ 
 int i, j;
  for ( i = 0; i < aFigure->current_size; i++) 
   { 

     Figure *theFigure = &(aFigure->paralel[i]); 
     	
	printf("Figure [%d]\n", i + 1); 
	printf("Square: %d\n", abs(square(theFigure))); //print square figure;

     for (j = 0; j < 8; j++) 
      { 

      printf("point[%d]=[%d, %d, %d]\n", j+1, theFigure->points[j].x, theFigure->points[j].y, theFigure->points[j].z); //print point of figure;
      
      }    
       printf("\n");
   } 
   
}

int scan_f(void)
	{
     int num = 0;
			
     scanf("%d", &num);

	return num;
    }
    
int square(Figure *Figure)
{

			double L12 = 0;
			double L23 = 0;
			double L25 = 0;
			double S1,S2,S3,square;
			double x=0, y=0, z=0;
			square = 0;
			
			x = (Figure->points[1].x) - (Figure->points[2].x);
			y = (Figure->points[1].y) - (Figure->points[2].y);
			z = (Figure->points[1].z) - (Figure->points[2].z);
			L12 = sqrt((x*x) + (y*y) + (z*z)); //Calculate leght of side figure;
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
			
			S1=(L12*L23)/2; //Intermediate square;
			S2=(L25*L23)/2;
			S3=(L25*L12)/2;
			square =(4*S1)+(4*S2)+(4*S3); //calculate square of figure
			return square;			
}

void writeList(FILE *aFile, FigureList *aFigure)
{
	        fprintf(aFile, "{\n");
			fprintf(aFile, " \"size\":%d,\n", aFigure->size);
			fprintf(aFile, " \"current_size\":%d\n\n\t", aFigure->current_size);
			fprintf(aFile, "\"parallelepipeds\":\n\t");
			
			if (NULL == aFigure->paralel)
	          {
		        fprintf(aFile, "null");
	          }
	        else
	           {
	           	fprintf(aFile, "[\n\t");
	           	int i;
	           	for (i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->paralel[i]);
	           		writeFigure(aFile, theFigure);
	           		if (i < (aFigure->current_size - 1))
			         {
				      fprintf (aFile, ",\n\t");
			         }
			}
	
		fprintf(aFile, "\n\t]\n");
	}
	
	fprintf (aFile, "}");
}



void writeFigure(FILE *aFile, Figure *aFigure)
{
	
	fprintf(aFile, " {\n\t");
    int i;
	for (i = 0; i < 8; i++)
    {
	fprintf(aFile, " \"Point[%d]\": {\"CoordX:\%d, \"CoordY:\%d, \"CoordZ:\%d}", i+1, aFigure->points[i].x, aFigure->points[i].y, aFigure->points[i].z);
	if (i<7)
	  {
	  	fprintf(aFile, ",\n\t");
	  }
    }
    fprintf(aFile, "\n\t }");
}
