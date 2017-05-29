#include <stdio.h>
//#include <stdbool.h>
#include "dk_tool.h"
circle * CreateList(int size)
{
	circle *newlist(circle *)malloc(sizeof(circle)*size);
	return newlist;
}
void NewCircle(circle *ptr)
{
    printf("PLease write the coordinates of the center(2 points)\nX:\n");
    scanf("%d",&ptr->x);
    printf("Y:\n");
    scanf("%d",&ptr->y);
    printf("Enter the radius\n");
    scanf("%d",&ptr->rad);
    while(ptr->rad < 0){
        printf("Error! Radius is less than 0!\n");
        scanf("%d",&ptr->rad);
    }
    
}
long double square(circle s)
{
	return Pi*circle.rad * circle.rad;
}
void ShowTheFigures(square ptr[],int n) 
{
    for (int k = 0; k < n; k++) 
	{
        printf("Circle number %i with center(%i,%i), radius %i, and square %i\n",k+1,ptr[k].x,ptr[k].y,ptr[k].rad,ptr[k].square);
    }
}
