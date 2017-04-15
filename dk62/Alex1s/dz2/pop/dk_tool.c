#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

void make_triangle(Triangles *Element/*, Figure *Dots*/)
{
if(Element->current_fig < Element->max_fig)
	{
	Figure *Dots = &(Element->place[Element->current_fig]);
	enter_coor(Dots);
	printf("Create done!\n");
	
	float area_tr = calc_area(Dots);
	if(!area_tr)
		printf("Atention! Area = 0.\n");
	else
		printf("Area of triangle: %f\n", area_tr);
	
	Element->area[Element->current_fig] = area_tr;
	Element->current_fig++;
	}
else
	printf("Max amount of figures. Delete someone.\n");	
}

//-----------------------------------------------------------------------------------------------------------

void enter_coor(Figure *Dots)
{
int i;
for(i = 0; i < 3; i++)
	{
	printf("Enter x[%i] coordinate: ", i);
	scanf("%f", &Dots->x_coor[i]);
	printf("Enter y[%i] coordinate: ", i);
	scanf("%f", &Dots->y_coor[i]);
	}	
}

//-----------------------------------------------------------------------------------------------------------

float calc_area(Figure *Dots)
{
float result = ((Dots->x_coor[0] - Dots->x_coor[2]) * (Dots->y_coor[1] - Dots->y_coor[2]) - (Dots->x_coor[1] - Dots->x_coor[2]) * (Dots->y_coor[0] - Dots->y_coor[2])) / 2;
/*float result = (Dots->x_coor[0] - Dots->x_coor[2]) * (Dots->y_coor[1] - Dots->y_coor[2]);
result -= (Dots->x_coor[1] - Dots->x_coor[2]) * (Dots->y_coor[0] - Dots->y_coor[2]) / 2;*/
if(result < 0)
	result *= -1;
return result;
}

//-----------------------------------------------------------------------------------------------------------

/*void delete_triangle(Triangles *Element, Figure *Dots, int i)
{
*Dots = Element->place[i];
free(Dots->x_coor);
free(Dots->y_coor);
Element->current_fig--;
}

//-----------------------------------------------------------------------------------------------------------

void delete_all(Triangles *Element, Figure *Dots)
{
int i;
for(i = 0; i < 5; i++)
	{
	*Dots = Element->place[i];
	free(Dots->x_coor);
	free(Dots->y_coor);
	Element->current_fig--;
	}
if(Element)
	free(Element);
if(Dots)
	free(Dots);
}*/
