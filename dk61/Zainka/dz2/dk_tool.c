#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

#include "dk_tool.h"
 
 
int addPiramida(filepiramida *polochka) // ïåðåäàºìî êóäà áóäåì ëîæèòü 
{
	int theResult = 0;
	
	
	if (NULL != polochka && polochka->current_size < polochka->size) // ÿêùî ïîòî÷íèé ðîçì³ð ìåíøå ìàêñèìàëüíîãî 
	{
	

		Piramida *heops = &(polochka->Piramida[polochka->current_size]); //  àäðåñ ïóñòîãî ìåñòà çàïîëíÿì åãî êîîðäèíàòàìè 
		int i,value = 0; 
		if(NULL != heops)
		{
			for( i = 0; i < 4; i++)
			{
				printf("type a number'\n");
				scanf("%d", &value ); //// äî 0 òî÷êè ïðèñâàèâàåì 1 çíà÷åíèå  
				heops->points[i]->x = value;
				scanf("%d", &value ); //// äî 0 òî÷êè ïðèñâàèâàåì 1 çíà÷åíèå  
				heops->points[i]->y = value;
				scanf("%d", &value ); //// äî 0 òî÷êè ïðèñâàèâàåì 1 çíà÷åíèå  
				heops->points[i]->z = value;
			}	
		}
			 polochka->current_size ++; // íîìåð ñâîá ìåñòà 
  }
	else
	{
		theResult = -1;
	}
	return theResult;
}

filepiramida *Createfilepiramida(int aSize) // ïîëî÷êà ðàñ÷èàòíà íà òîëüêî àçàéç
{
	filepiramida *polochka = (filepiramida *)malloc(sizeof(filepiramida));

	if (NULL != polochka)
	{
		polochka->Piramida = (Piramida *)malloc(aSize * sizeof(Piramida));
		memset(polochka->Piramida, 0 , aSize * sizeof(filepiramida));
	
		polochka->size = aSize;
		polochka->current_size = 0; //  
	}
	return polochka; // âûäàå ïîëî÷êó ôîðìàò êàêîé ôàéë ïèðàìèäà 
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
	length4 = sqrt(pow(heops->points[2]->x - heops->points[3]->x, 2) + pow(heops->points[2]->y - heops->points[3]->y, 2) + pow(heops->points[2]->z - heops->points[4]->z, 2));
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
