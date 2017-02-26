#include <stdio.h>
#include <locale.h>
#include "dodmat.h"
void main () {
setlocale(LC_ALL, "russian_russia.1251");
int first_mas[10][10];
int second_mas [10][10];
int rez_mas [10][10];
int i, j, ryad1, kol1, ryad2, kol2, t, y, a, n;
int x = 0;
int q = 0;
printf ("¬вiд размiру першоi матрицi\n");
printf ("¬ведiть кiлькiсть колонок\n");
scanf ("%i", &ryad1);
printf ("¬ведiть кiлькiсть р€дкiв\n");
scanf ("%i",&kol1);
printf ("¬ведiть елементи першоi матрицi\n");
i = 0;
while (i<ryad1) {
j = 0;
while (j<kol1) {
t=0;
scanf ("%i", &t);
first_mas[i][j] = t;
j++;
}
i++;
}
printf ("¬вiд розмiру другоi матрицi\n");
printf ("¬ведiть кiлькiсть колонок\n");
scanf ("%i", &ryad2);
printf ("¬ведiть кiлькiсть р€дкiв\n");
scanf ("%i", &kol2);
printf ("¬ведiть елементи першоi матрицi\n");
a = 0;
while (a<ryad2) {
n = 0;
while (n<kol2) {
t=0;
scanf ("%i", &t);
second_mas[a][n] = t;
n++;
}
a++;
}
printf("ѕерша матриц€ вигл€даe:\n");
i=0;
while (i<ryad1) {
j = 0;
while (j<kol1) {
printf(" %i ", first_mas[i][j]);
j++;
}
printf("\n");
i++;
}
printf("ƒруга матриц€ вигл€даe:\n");
a=0;
while (a<ryad2) {
n = 0;
while (n<kol2) {
printf(" %i ", second_mas[a][n]);
n++;
}
printf("\n");
a++;
}
if (kol1==ryad2){
printf("÷i матрицi можна перемножити\n");

mat1 (x,i,j,n,a,ryad1,kol2,y,q,rez_mas,first_mas,second_mas,ryad2);

printf("ƒoбуток:\n");
x=0;
while (x<ryad1) {
y = 0;
while (y<kol2) {
printf(" %i ",rez_mas[x][y]);
y++;
}
printf("\n");
x++;
}
}
}

