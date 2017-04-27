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
	Element->place->area = calc_area(Element, Dots);
	if(!Element->place->area)
		printf("Atention! Area = 0\n\n");
	else
		printf("Area of triangle: %f\n\n", Element->place->area);
	
	Element->current_fig++;
	}
else
	printf("Max amount of figures.\n\n");
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
	float tmp1, tmp2;
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
		tmp1 = Element->place->area;
		
		Element->place = &(Dots[l]);
		Element->place->area = tmp1;
		}
	Element->current_fig--;
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

//-----------------------------------------------------------------------------------------------------------

void shellsort(Triangles *Element, Figure *Dots)
{
float tmp;
float *tmp_x = (float *) malloc(sizeof(float) * 3);
float *tmp_y = (float *) malloc(sizeof(float) * 3);

int i = 0, j = 0, H = 1, k;

while(H <= Element->current_fig / 3)
	H = H * 3 + 1;

while(H > 0)
	{
	for(j = H; j < Element->current_fig; j++)
		{
		Element->place = &(Dots[j]);
		save(Element, Dots, &tmp, tmp_x, tmp_y);		//tmp = array[j]
		i = j;
		
		Element->place = &(Dots[i - H]);
		while(i > H - 1 && Element->place->area >= tmp)
			{
			appropriation(Element, Dots, i, H);			//array[i] = array[i - H];
			i -= H;
			Element->place = &(Dots[i - H]);
			}
		
		Element->place = &(Dots[i]);
		boot(Element, Dots, &tmp, tmp_x, tmp_y);		//array[i] = tmp
		print_structs(Element, Dots);
		}
	H = (H - 1) / 3;
	}
free(tmp_x);
free(tmp_y);
}

//-----------------------------------------------------------------------------------------------------------

int line_search(Triangles *Element, Figure *Dots, float val)
{
int i;
for(i = 0; i < Element->current_fig; i++)
	{
	Element->place = &(Dots[i]);
	if(Element->place->area == val)
		return i;
	}
return -1;
}

//-----------------------------------------------------------------------------------------------------------

void appropriation(Triangles *Element, Figure *Dots, int i, int H)
{
int k;
float tmp;
float *tmp_x = (float *) malloc(sizeof(float) * 3);
float *tmp_y = (float *) malloc(sizeof(float) * 3);
Element->place = &(Dots[i - H]);
tmp = Element->place->area;
for(k = 0; k < 3; k++)
	{
	tmp_x[k] = Element->place->x_coor[k];
	tmp_y[k] = Element->place->y_coor[k];
	}
Element->place = &(Dots[i]);
Element->place->area = tmp;
for(k = 0; k < 3; k++)
	{
	Element->place->x_coor[k] = tmp_x[k];
	Element->place->y_coor[k] = tmp_y[k];
	}
free(tmp_x);
free(tmp_y);
}

//-----------------------------------------------------------------------------------------------------------

void print_struct(Triangles *Element, Figure *Dots, int i)
{
Element->place = &(Dots[i]);
printf("\nFigure #%i\nArea: %f\n", i, Element->place->area);
printf("Dot [0]: %f\t%f\n", Element->place->x_coor[0], Element->place->y_coor[0]);
printf("Dot [1]: %f\t%f\n", Element->place->x_coor[1], Element->place->y_coor[1]);
printf("Dot [2]: %f\t%f\n", Element->place->x_coor[2], Element->place->y_coor[2]);
}

//-----------------------------------------------------------------------------------------------------------

void save(Triangles *Element, Figure *Dots, float *tmp, float *tmp_x, float *tmp_y)
{
*tmp = Element->place->area;
int k;
for(k = 0; k < 3; k++)
	{
	tmp_x[k] = Element->place->x_coor[k];
	tmp_y[k] = Element->place->y_coor[k];
	}
}

//-----------------------------------------------------------------------------------------------------------

void boot(Triangles *Element, Figure *Dots, float *tmp, float *tmp_x, float *tmp_y)
{
Element->place->area = *tmp;
int k;
for(k = 0; k < 3; k++)
	{
	Element->place->x_coor[k] = tmp_x[k];
	Element->place->y_coor[k] = tmp_y[k];
	}
}
