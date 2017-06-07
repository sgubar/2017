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
				//printf("Enter the point[%d]\n", i+1);
				theFigure->points[i].x = addCoordinate();// scan_f();
				theFigure->points[i].y = addCoordinate(); //scan_f();
			    theFigure->points[i].z = addCoordinate(); //scan_f();
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

int addCoordinate()
{
	int chislo = 1 + rand() %50;
	return chislo;
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
			fprintf(aFile, " \"current_size\":%d,\n", aFigure->current_size);
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

void BubbleSort(FigureList *aFigure) 
{   
	int j, i;
	for(i=aFigure->current_size-1; i>1; i--) 
	{ 
		for(j=0; j<i; j++) 
	{ 
		if(square(&aFigure->paralel[j])>square(&aFigure->paralel[j+1])) 
		{ 
		Figure tmp=aFigure->paralel[j]; 
		aFigure->paralel[j]=aFigure->paralel[j+1]; 
		aFigure->paralel[j+1]=tmp; 
        } 
	} 
	} 
}

int BinarySearch(FigureList *aFigure)
{
	int Value = scan_f();
	int Left = 0;
	int Right = aFigure->current_size;
	int middle = 0;
	
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if (square(&aFigure->paralel[middle]) == Value)
		{
			int Result = middle;
			return Result+1;
		}
		else
		{
			if (square(&aFigure->paralel[middle]) > Value)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	return -1;	
}

void swap(FigureList *aFigure, int aLeftIndex, int aRightIndex)
{
	Figure theTmp = aFigure->paralel[aLeftIndex];
	aFigure->paralel[aLeftIndex] = aFigure->paralel[aRightIndex];
	aFigure->paralel[aRightIndex] = theTmp;
}
int mediana(FigureList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	
	
	if (square(&aFigure->paralel[aLeftIndex]) > square(&aFigure->paralel[theCenter]))
	{
		swap(aFigure, aLeftIndex, theCenter);
	}

	if (square(&aFigure->paralel[aLeftIndex]) > square(&aFigure->paralel[aRightIndex]))
	{
		swap(aFigure, aLeftIndex, aRightIndex);
	}

	if (square(&aFigure->paralel[theCenter]) > square(&aFigure->paralel[aRightIndex]))
	{
		swap(aFigure, theCenter, aRightIndex);
	}
	
	swap(aFigure, theCenter, aRightIndex - 1);
	
	
	return square(&aFigure->paralel[aRightIndex-1]);;
}

int m_partitionIt(FigureList *aFigure, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex-1;
	
	while (1)
	{
		// search the bigest element
		while (square(&aFigure->paralel[++theLeft]) < aPivot);
	
		// search the lowest element
		while (square(&aFigure->paralel[--theRight]) > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(aFigure, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(aFigure, theLeft, aRightIndex-1);

	return theLeft; // return break position
}

void quickSort2(FigureList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(aFigure, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(aFigure, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(aFigure, aLeftIndex, aRightIndex, thePivot);
		
		//left part sorting
		quickSort2(aFigure, aLeftIndex, thePartitionIndex - 1);
		
		//right part sorting
		quickSort2(aFigure, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(FigureList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{
		if (square(&aFigure->paralel[aLeftIndex]) > square(&aFigure->paralel[aRightIndex]))
		{
			swap(aFigure, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (square(&aFigure->paralel[aLeftIndex]) > square(&aFigure->paralel[aRightIndex-1]))
	     {
		swap(aFigure, aLeftIndex, aRightIndex-1);
	     }
	
		if (square(&aFigure->paralel[aLeftIndex]) > square(&aFigure->paralel[aRightIndex]))
		{
			swap(aFigure, aLeftIndex, aRightIndex);
		}

		if (square(&aFigure->paralel[aRightIndex - 1]) > square(&aFigure->paralel[aRightIndex]))
		{
			swap(aFigure, aRightIndex - 1, aRightIndex);
		}
	}
}
