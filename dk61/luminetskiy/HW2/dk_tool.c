#include "circling.h"
#include <stdio.h>
//#include <stdbool.h>

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

double Squareof(circle s)
{
    return Pi * s.rad * s.rad ;
}
void ShowTheFigures(circle ptr[],int n)
{
    for (int k = 0; k < n; k++)
	{
        printf("Circle number %i with center(%i,%i), radius %i, and square %i\n",k+1,ptr[k].x,ptr[k].y,ptr[k].rad,ptr[k].square);
    }
}
