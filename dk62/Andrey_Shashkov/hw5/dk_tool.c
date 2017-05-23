#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tool.h"



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
			{ int i=0;
			  theFigure->points = (Point *)malloc(sizeof(Point)*8); 
				
				for(i=0; i<8; i++)
				{
				theFigure->points[i].x = addCoordinate();
				theFigure->points[i].y = addCoordinate(); 
			    theFigure->points[i].z = addCoordinate(); 
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
	printf("Square: %d\n", abs(square(theFigure))); 

     for (j = 0; j < 8; j++) 
      { 

      printf("point[%d]=[%d, %d, %d]\n", j+1, theFigure->points[j].x, theFigure->points[j].y, theFigure->points[j].z); 
      
      }    
       printf("\n");
   } 
   
}

int scan(void)
	{
     int num = 0;
			
     scanf("%d", &num);

	return num;
    }
    
int square(Figure *Figure)
{

			int p1,p2,p3,square,x,y,z ;
	
			x = abs(Figure->points[1].x) - (Figure->points[2].x);
			y = abs(Figure->points[1].y) - (Figure->points[2].y);
			p1 = (x*y) ; 

			x = abs(Figure->points[2].x) - (Figure->points[3].x);
			z = abs(Figure->points[2].z) - (Figure->points[3].z);
			p2 = (x*z);

			y = abs(Figure->points[2].y) - (Figure->points[5].y);
			z = abs(Figure->points[2].z) - (Figure->points[5].z);
			p3 =(y*z);

			square =(p1)+(p2)+(p3); 
			return square;			
}

int BinarySearch(FigureList *aFigure)
{
	int Value = scan();
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
	
		if (theLeft >= theRight) 
		{
			break;
		}
		else
		{
			swap(aFigure, theLeft, theRight);
		}
	}

	swap(aFigure, theLeft, aRightIndex-1);

	return theLeft; 
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
