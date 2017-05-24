#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include "dk_tool.h"
 
 
int addPiramida(filepiramida *polochka) // передаємо куда будем ложить 
{
	int theResult = 0;
	
	
	if (NULL != polochka && polochka->current_size < polochka->size) // якщо поточний розмір менше максимального 
	{
		int index = (polochka->current_size > 0) ? polochka->current_size-1 : 0;

		Piramida *heops = &(polochka->Piramida[index]); //  адрес пустого места заполням его координатами 
		int i,value = 0; 
		if(NULL != heops)
		{
			for( i = 0; i < 4; i++)
			{
				kordinati *coord = (kordinati *)malloc(sizeof(kordinati));
				heops->points[i] = coord;
				
				printf("type a number'\n");
				scanf("%d", &value ); //// до 0 точки присваиваем 1 значение  
				heops->points[i]->x = value;
				printf("type 2\n");
				scanf("%d", &value ); //// до 0 точки присваиваем 1 значение  
				heops->points[i]->y = value;
				printf("type 3\n");
				scanf("%d", &value ); //// до 0 точки присваиваем 1 значение  
				heops->points[i]->z = value;
				
			}	
		}
			 polochka->current_size ++; // номер своб места 
  }
	else
	{
	theResult = -1;
	}
	return theResult;
}

filepiramida *Createfilepiramida(int aSize) // полочка расчиатна на только азайз
{
	filepiramida *polochka = (filepiramida *)malloc(sizeof(filepiramida));

	if (NULL != polochka)
	{
		polochka->Piramida = (Piramida *)malloc(aSize * sizeof(Piramida));
		memset(polochka->Piramida, 0 , aSize * sizeof(filepiramida));
	
		polochka->size = aSize;
		polochka->current_size = 0; //  
	}
	return polochka; // выдае полочку формат какой файл пирамида 
}


float area(Piramida *heops)
{
	
	 int length;
	 int length1;
	 int length2 ,length3 ,length4 ,length5;
	 int perimS1 , perimS2 ,perimS3 ,perimS4;
	float S1 , S2 ,S3 ,S4;
	float SWAG;
	 
	length  = sqrt(pow(heops->points[1]->x - heops->points[0]->x, 2) + pow(heops->points[1]->y - heops->points[0]->y, 2) + pow(heops->points[1]->z - heops->points[0]->z, 2));
	length1 = sqrt(pow(heops->points[2]->x - heops->points[0]->x, 2) + pow(heops->points[2]->y - heops->points[0]->y, 2) + pow(heops->points[2]->z - heops->points[0]->z, 2));
	length2 = sqrt(pow(heops->points[3]->x - heops->points[0]->x, 2) + pow(heops->points[3]->y - heops->points[0]->y, 2) + pow(heops->points[3]->z - heops->points[0]->z, 2));
	length3 = sqrt(pow(heops->points[3]->x - heops->points[1]->x, 2) + pow(heops->points[3]->y - heops->points[1]->y, 2) + pow(heops->points[3]->z - heops->points[1]->z, 2));
	length4 = sqrt(pow(heops->points[2]->x - heops->points[3]->x, 2) + pow(heops->points[2]->y - heops->points[3]->y, 2) + pow(heops->points[2]->z - heops->points[3]->z, 2));
	length5 = sqrt(pow(heops->points[2]->x - heops->points[1]->x, 2) + pow(heops->points[2]->y - heops->points[1]->y, 2) + pow(heops->points[2]->z - heops->points[1]->z, 2));
	
	perimS1 = (length + length1 + length5 )/2;
	perimS2 = ( length1 + length2 + length4 )/2;
	perimS3 = ( length + length2 + length3 )/2;
	perimS4 = (length3 + length4 + length5  )/2;
	
	S1 = sqrt(perimS1*(perimS1 - length)*(perimS1 - length1)*(perimS1 - length5));
	S2 = sqrt(perimS2*(perimS2 - length1)*(perimS2 - length2)*(perimS2 - length4));
	S3 = sqrt(perimS3*(perimS3 - length)*(perimS3 - length2)*(perimS3 - length3));
	S4 = sqrt(perimS4*(perimS4 - length3)*(perimS4 - length4)*(perimS4 - length5));
	
	SWAG = S1+ S2 + S3 + S4;
	printf( "otvet %.3f\n" , SWAG );
	
	return SWAG; 
}
