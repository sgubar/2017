
#include "dk.tool.h"
#include <stdio.h>
#include <stdbool.h>

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
bool output(char *filename, circle *ptr, int n)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
		return false;//You don't need to check filename
	fprintf(file, "{\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(file,"\t\"Circle %i\": {\n\t\t\"X\": %i,\n\t\t\"Y\": %i,\n\t\t\"Radius\": %i,\n\t\t\"Square\": %.2f\n\t}",\
			i,ptr[i].x,ptr[i].y,ptr[i].rad,ptr[i].square);// Ð¼Ð°Ñ‚ÑŽÐºÐ°Ñ”Ñ‚ÑŒÑÑ Ð½Ð° square
		if (i != n - 1)
			fprintf(file, ",");
        fflush(file);
		fprintf(file, "\n");

	}
	fprintf(file,"}\n");
	fclose(file);
	return 0;
}
