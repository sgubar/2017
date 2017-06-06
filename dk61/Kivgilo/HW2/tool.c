#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tool.h"



int addCoordinate()
{
	int chislo = 1 + rand() %50;
	return chislo;
} 

List_of_Figure *createList_of_Figure(int aSize) //Создаем лист с фигурами;
{
    List_of_Figure *List = (List_of_Figure *)malloc(sizeof(List_of_Figure));  //Создаем новый лист и выделяем память;
    if(List != NULL)
	{
		List->paralel = (Figure *)malloc(aSize * sizeof(Figure)); //Выделяем память для фигур;
		memset(List->paralel, 0, sizeof(Figure));
		List->size = aSize;          //Максимальное допустимое количество фигур;
		List->current_size = 0;		//Введенное количество;
	}
	return List;
}

int WriteCoordinate(List_of_Figure *aFigure) //Задаем кординаты точки;
{
	if(NULL != aFigure )
	{
		if(aFigure -> current_size < aFigure->size)
		{
			Figure *theFigure = &(aFigure->paralel[aFigure->current_size]);
			if( NULL != theFigure)
			{ int i=0;
			  theFigure->points = (Point *)malloc(sizeof(Point)*8); //Выделяем память для точек;
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

void destroyList_of_Figure(List_of_Figure *aFigure) //Удаляем лист;
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

void printList(List_of_Figure *aFigure) 
{ 
 int i, j;
  for ( i = 0; i < aFigure->current_size; i++) 
   { 

     Figure *theFigure = &(aFigure->paralel[i]); 
     	
	printf("Фигура [%d]\n", i + 1); 
	printf("Площадь: %d\n", abs(square(theFigure))); //Вывод площади фигур;

     for (j = 0; j < 8; j++) 
      { 

      printf("Точка[%d]=[%d, %d, %d]\n", j+1, theFigure->points[j].x, theFigure->points[j].y, theFigure->points[j].z); //выводим значения точек в фигуре;
      
      }    
       printf("\n");
   } 
   
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
			L12 = sqrt((x*x) + (y*y) + (z*z)); //подсчет площади боковых сторон;
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
			
			S1=(L12*L23)/2; //Промежуточная площадь;
			S2=(L25*L23)/2;
			S3=(L25*L12)/2;
			square =(4*S1)+(4*S2)+(4*S3); //Подсчет полной площади фигуры;
			return square;			
}

