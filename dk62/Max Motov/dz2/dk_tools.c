#include <string.h>
#include <stdlib.h>
#include "dk_tools.h"
#include <math.h>
sphere_t* elements = NULL;
int count = 0;

void AddSphere(float x, float y, float z, float radius)
{
    point_t* tempCoordinates = (point_t *)malloc(sizeof(point_t));//память на структуру координат
    elements = realloc(elements, (count + 1) * sizeof(sphere_t)); //выделяем доп память под след структуру

    tempCoordinates->x = x;
    tempCoordinates->y = y;
    tempCoordinates->z = z;

    elements[count].radius = radius;
    elements[count].center = (point_t *)malloc(sizeof(point_t)); //память под вторую структуру
    memcpy(elements[count].center, tempCoordinates, sizeof(point_t)); //копируем память певой структуры в массив структур

    free(tempCoordinates);
    count++;

}

void PrintElements(void)
{
   for(int i = 0; i < count; i++)
   {
       printf("Sphere number is %i:\n x = %f,\n y = %f,\n z = %f,\n radius = %f\n", i, elements[i].center->x, elements[i].center->y, elements[i].center->z, elements[i].radius);
   }

}

void CalcSquare(int number)
{
    if(number < 0 || number > count)
        printf("No such struct exists\n");
    else
    {
        float pi = 3.14;
        float square = ((float)4/3) * pi * pow(elements[number].radius, 3);
        printf("Curent sphere square = %f\n", square);

    }

}

void CleanUp(void)
{
    for(int i = 0; i < count; i++)
        free(elements[i].center);

    free(elements);
}




