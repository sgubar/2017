#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tool.h"

int scan(void)//приймає значення типу int  з клавіатури
	{
     int num = 0;
			
     scanf("%d", &num);

	return num;
    }

 
mylist *createMyList(int aSize) //створює списокс труктур
{
    mylist *List = (mylist *)malloc(sizeof(mylist)); //виділяєм память
    if(List != NULL)
	{
		List->paralel = (Figure *)malloc(aSize * sizeof(Figure));
		memset(List->paralel, 0, sizeof(Figure));
		List->size = aSize;          
		List->current_size = 0;		
	}
	return List;
}

int addCoor(mylist *aFigure) //записує значення в структури
{
	if(NULL != aFigure )
	{
		if(aFigure -> current_size < aFigure->size)
		{
			Figure *theFigure = &(aFigure->paralel[aFigure->current_size]);
			if( NULL != theFigure)
			{ int x=0;
			  theFigure->points = (Point *)malloc(sizeof(Point)*8); 
			  printf("enter values for plane x = ");
			  x = scan();
				for(x=0; x<4; x++)
				{
				printf("Enter the point[%d] for plane basics \n", x+1);
				theFigure->points[x].x = x;
				theFigure->points[x].y = scan();
			    theFigure->points[x].z = scan();
			    }
			    
			    printf("Enter one point for an other ploskost \n");
			    printf("x = ");
				theFigure->points[4].x = scan();
				printf("y = ");
				theFigure->points[4].y = scan();
				printf("z = ");
				theFigure->points[4].z = scan();
				printf("\n");
				
				int raznx = theFigure->points[0].x - theFigure->points[4].x;
				int razny = theFigure->points[0].y - theFigure->points[4].y;
				int raznz = theFigure->points[0].z - theFigure->points[4].z;
				
				for(x=5;x<8;x++)
				{
				theFigure->points[x].x = theFigure->points[x - 4].x - raznx;
				theFigure->points[x].y = theFigure->points[x - 4].y - razny;
			    theFigure->points[x].z = theFigure->points[x - 4].z - raznz;				
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

void destroyMyList(mylist *aFigure) //видаляє список структур
{
	if(NULL != aFigure)//якщо список не порожній ачистити його
	{
		if(NULL != aFigure-> paralel)
		{
			free(aFigure-> paralel);
		}
		free(aFigure);
	}
}

void printMyFigure(mylist *aFigure) //друкує значення координат
{ 
 int x, y;
  for ( x = 0; x < aFigure->current_size; x++) 
   { 

    Figure *theFigure = &(aFigure->paralel[x]); 
     	
	printf("Figure [%d]\n", x + 1); 
	printf("Square is : %d\n", abs(square(theFigure))); 

     for (y = 0; y < 8; y++) 
      { 

      printf("point[%d]=[%d, %d, %d]\n", y+1, theFigure->points[y].x, theFigure->points[y].y, theFigure->points[y].z);
      
      }    
   } 
   
}
    
int square(Figure *Figure) //обраховує площу
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
