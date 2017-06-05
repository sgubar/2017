#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "dk_tool.h"

 
FigureList *createFigureList(int aSize) //create List of Figure;
{
	FigureList *List = (FigureList *)malloc(sizeof(FigureList));  //create List and memory;
	if(List != NULL)
	{
		List->chotirikytnik = (Figure *)malloc(aSize * sizeof(Figure)); //create memory for figure;
		memset(List->chotirikytnik, 0, sizeof(Figure));
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
			Figure *theFigure = &(aFigure->chotirikytnik[aFigure->current_size]);
			if( NULL != theFigure)
			{ 
				int i=0;
				theFigure->points = (Point *)malloc(sizeof(Point)*8); //create memory for points;
				for(i=0; i<5; i++)
				{
					theFigure->points[i].x = rand()%100+1;
					theFigure->points[i].y = rand()%100+1;
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
		if(NULL != aFigure-> chotirikytnik)
		{
			free(aFigure-> chotirikytnik);
		}
		free(aFigure);
	}
}

void printFigure(FigureList *aFigure) 
{ 
	int i, j;
	for ( i = 0; i < aFigure->current_size; i++) 
	{ 
		Figure *theFigure = &(aFigure->chotirikytnik[i]); 
		printf("Figura %d:\n", i + 1); 
		printf("S(chotirikytnika)= %d\n", square(theFigure)); //print square figure;
		for (j = 0; j < 4; j++) 
		{ 
			printf("Coordinati tochki %d:(%d,%d)\n", j+1, theFigure->points[j].x, theFigure->points[j].y); //print point of figure;
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
	int xa,xb,xc,xd,ya,yb,yc,yd;
    float a,b,c,d,acosA,acosB,cosfi,p,square;
	xa=(Figure->points[2].x) - (Figure->points[1].x);
	ya=(Figure->points[2].y) - (Figure->points[1].y);
	xb=(Figure->points[3].x) - (Figure->points[2].x);
	yb=(Figure->points[3].y) - (Figure->points[2].y);
	xc=(Figure->points[4].x) - (Figure->points[3].x);
	yc=(Figure->points[4].y) - (Figure->points[3].y);
	xd=(Figure->points[1].x) - (Figure->points[4].x);
	yd=(Figure->points[1].y) - (Figure->points[4].y);
    a=sqrt(xa*xa+ya*ya);
    b=sqrt(xb*xb+yb*yb);
    c=sqrt(xc*xc+yc*yc);
    d=sqrt(xd*xd+yd*yd);
    acosA= acos((xa*xd+ya*yd)/(sqrt(xa*xa+ya*ya)*sqrt(xd*xd+yd*yd))); 
    acosB= acos((xb*xc+yb*yc)/(sqrt(xb*xb+yb*yb)*sqrt(xc*xc+yc*yc)));
    cosfi= cos((acosA+acosB)/2);
    p=(a+b+c+d)/2;
    square=sqrt((p-a)*(p-b)*(p-c)*(p-d)-a*b*c*d*cosfi*cosfi); 
    return square;
}
void writeList(FILE *aFile, FigureList *aFigure)
{
	        fprintf(aFile, "{\n");
			fprintf(aFile, " \"size\":%d,\n", aFigure->size);
			fprintf(aFile, " \"current_size\":%d,\n", aFigure->current_size);
			fprintf(aFile, "\"parallelepipeds\":\n\t");
			
			if (NULL == aFigure->chotirikytnik)
	          {
		        fprintf(aFile, "null");
	          }
	        else
	           {
	           	fprintf(aFile, "[\n\t");
	           	int i;
	           	for (i = 0; i < aFigure->current_size; i++)
	           	{
	           		Figure *theFigure = &(aFigure->chotirikytnik[i]);
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
	for (i = 0; i < 4; i++)
    {
	fprintf(aFile, " \"Point[%d]\": {\"CoordX:\%d, \"CoordY:\%d}", i+1, aFigure->points[i].x, aFigure->points[i].y);
	if (i<3)
	  {
	  	fprintf(aFile, ",\n\t");
	  }
    }
    fprintf(aFile, "\n\t }");
}
