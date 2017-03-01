#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "dk_tool.h" 

int main()
{
 
 float A;
int stepen= 2;
float B;
float kvA;
int kvB;
int tchislo = 5;
float C;
int powC;
float dilenie;
printf("Vvedit tchislo A\n");
scanf("%f" , &A);
{
kvA=pow((double)A,(double)stepen);
	printf("tchislo %f v stepeni %i = %f\n" , A , stepen , kvA);
	}
printf("Vvedit tchislo B\n");
scanf("%f" , &B);
{
kvB=pow((double)B,(double)stepen);
	printf("tchislo %f v stepeni %i = %f\n" , B , stepen , kvB);
	}
printf("Vvedit tchislo C\n");
scanf("%f" ,&C);
{
if(C > 0)
{
powC = pow(tchislo , C);


}
float znamennyk;
float tchiselnik;
{
znamennyk = kvA + kvB;
}
{
tchiselnik = B + powC;
}
{
dilenie = (znamennyk / tchiselnik);
printf("Rezultat dilenija %f / %f = %f\n" , znamennyk ,tchiselnik , dilenie);
}
     float otvet;
 {
otvet = dilenie + fact(B);
printf(" %f + %f = %f", dilenie , B , otvet );

}
getch();


}
