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
	Element->current_fig--;
	}
}

//-----------------------------------------------------------------------------------------------------------

void file_triangle(FILE *file, Triangles *Element, Figure *Dots, int *f)
{
fprintf(file, "{\"Record\":%i,", *f);
fprintf(file, "\"Max size\":%i,", Element->max_fig);

(*f)++;
fprintf(file, "\"Current size\":%i", Element->current_fig);

if(Element->current_fig)
	{
	int l;
	fprintf(file, ",\"Triangles\":[\n");

	for(l = 0; l < Element->current_fig; l++)
		{
		Element->place = &(Dots[l]);
		fprintf(file, "{\"Area\":%.3f},", Element->place->area);
		fprintf(file, "{\"Dot[0]\":%.3f  %.3f},", Element->place->x_coor[0], Element->place->y_coor[0]);
		fprintf(file, "{\"Dot[1]\":%.3f  %.3f},", Element->place->x_coor[1], Element->place->y_coor[1]);
		fprintf(file, "{\"Dot[2]\":%.3f  %.3f}\n", Element->place->x_coor[2], Element->place->y_coor[2]);
		}
	fprintf(file, "]");
	}
fprintf(file, "}\n");
}
