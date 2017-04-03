#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
	int *tochka = (int*)malloc(4 * sizeof(tochka));
float xA=0;
printf("Vodim xA:");
scanf("%f",&xA);
float yA=0;
printf("Vodim yA:");
scanf("%f",&yA);
float xB=0;
printf("Vodim xB:");
scanf("%f",&xB);
float yB=0;
printf("Vodim yB:");
scanf("%f",&yB);
float xC=0;
printf("Vodim xC:");
scanf("%f",&xC);
float yC=0; 
printf("Vodim yC:");
scanf("%f",&yC);
float xD=0;
printf("Vodim xD:");
scanf("%f",&xD);
float yD=0; 
printf("Vodim yD:");
scanf("%f",&yD);

float xAB=xB -xA;
float yAB=yB-yA;
float xBC=xC -xB;
float yBC=yC -yB;
float xCD=xD-xC;
float yCD=yD-yC;
float xDA=xA-xD;
float yDA=yA-yD;

float modulAB= sqrt(xAB*xAB+yAB*yAB);
float modulBC= sqrt(xBC*xBC+yBC*yBC);
float modulCD= sqrt(xCD*xCD+yCD*yCD);
float modulDA=sqrt(xDA*xDA+yDA*yDA);

float ABDA=xAB*xDA+yAB*yDA;
float BCCD=xBC*xCD+yBC*yCD;
 
float A = ABDA/modulAB*modulDA;
float C = BCCD/	modulBC*modulCD;
float p = (modulAB+modulBC+modulCD+modulDA)/2;
float S = sqrt((p -modulAB )*(p-modulBC)*(p-modulCD)*(p-modulDA)-modulAB*modulBC*modulCD*modulDA*(A*C)/2);
printf("Plosha ravno:\n");
printf("%f",S);
}
