#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

void make_triangle(Triangles *Element, Figure *Dots)
{
if(Element->current_fig < Element->max_fig)
	{
	Element->place = &(Dots[Element->current_fig]);
	enter_coor(Element, Dots);
	printf("\nCreate done!\n");
	float area_tr = calc_area(Element, Dots);
	if(!area_tr)
		printf("Atention! Area = 0.\n\n");
	else
		printf("Area of triangle: %f\n\n", area_tr);
	
	Element->place->area = area_tr;
	Element->current_fig++;
	}
else
	printf("Max amount of figures. Delete someone!!!\n\n");
}

//-----------------------------------------------------------------------------------------------------------

void enter_coor(Triangles *Element, Figure *Dots)
{
int i;
for(i = 0; i < 3; i++)
	{
	printf("Enter x[%i] coordinate: ", i);
	scanf("%f", &Element->place->x_coor[i]);
	printf("Enter y[%i] coordinate: ", i);
	scanf("%f", &Element->place->y_coor[i]);
	}
}

//-----------------------------------------------------------------------------------------------------------

float calc_area(Triangles *Element, Figure *Dots)
{
float result, tmp;
result = Element->place->x_coor[0] - Element->place->x_coor[2];
result *= Element->place->y_coor[1] - Element->place->y_coor[2];
tmp = Element->place->x_coor[1] - Element->place->x_coor[2];
tmp *= (Element->place->y_coor[0] - Element->place->y_coor[2]);
result = (result - tmp) / 2;

if(result < 0)
	result *= -1;
return result;
}

//-----------------------------------------------------------------------------------------------------------

void delete_all(Triangles *Element, Figure *Dots)
{
free(Dots);
Element->place = NULL;
free(Element);
}

//-----------------------------------------------------------------------------------------------------------

void delete_fig(Triangles *Element, Figure *Dots, int i)
{
if(i < Element->current_fig)
	{
	int k, l;
	float tmp1, tmp2, tmp3;
	for(l = i; l < Element->max_fig; l++)
		{
		for(k = 0; k < 3; k++)
			{
			Element->place = &(Dots[l + 1]);
			tmp1 = Element->place->x_coor[k];
			tmp2 = Element->place->y_coor[k];
			
			Element->place = &(Dots[l]);
			Element->place->x_coor[k] = tmp1;
			Element->place->y_coor[k] = tmp2;
			}
		Element->place = &(Dots[l + 1]);
		tmp3 = Element->place->area;
		
		Element->place = &(Dots[l]);
		Element->place->area = tmp3;
		}
	}
Element->current_fig--;
}

//-----------------------------------------------------------------------------------------------------------

void bubblesort(Triangles *Element, Figure *Dots)
{
int i, k, l, swaps = 0;
float tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
for(i = 0; i < Element->current_fig-1; i++)
    {
    for(l = 0; l < Element->current_fig-1-i; l++)
        {
		Element->place = &(Dots[l]);
		tmp1 = Element->place->area;
		Element->place = &(Dots[l + 1]);
		tmp2 = Element->place->area;
        if(tmp1 > tmp2)
            {
            for(k = 0; k < 3; k++)
				{
				Element->place = &(Dots[l]);
				tmp1 = Element->place->x_coor[k];
				tmp2 = Element->place->y_coor[k];
				
				Element->place = &(Dots[l + 1]);
				tmp4 = Element->place->x_coor[k];
				tmp5 = Element->place->y_coor[k];
				Element->place->x_coor[k] = tmp1;
				Element->place->y_coor[k] = tmp2;
				
				Element->place = &(Dots[l]);
				Element->place->x_coor[k] = tmp4;
				Element->place->y_coor[k] = tmp5;
				}
			Element->place = &(Dots[l]);
			tmp3 = Element->place->area;
			
			Element->place = &(Dots[l + 1]);
			tmp6 = Element->place->area;
			Element->place->area = tmp3;
			
			Element->place = &(Dots[l]);
			Element->place->area = tmp6;
			
			swaps++;
            }
        }
    if(!swaps)
    	{
    	printf("Array was sorted.\n");
    	break;
    	}
    }
}

//-----------------------------------------------------------------------------------------------------------

void print_structs(Triangles *Element, Figure *Dots)
{
int l;
for(l = 0; l < Element->current_fig; l++)
	{
	Element->place = &(Dots[l]);
	printf("\nFigure #%i\nArea: %f\n", l, Element->place->area);
	printf("Dot [0]: %f\t%f\n", Element->place->x_coor[0], Element->place->y_coor[0]);
	printf("Dot [1]: %f\t%f\n", Element->place->x_coor[1], Element->place->y_coor[1]);
	printf("Dot [2]: %f\t%f\n", Element->place->x_coor[2], Element->place->y_coor[2]);
	}
}
