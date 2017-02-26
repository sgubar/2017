#include "dk_tool.h"



 void print(struct matrica *inM)
{

printf("Transponovanaya matriña\n");
int i=0;
while (i<inM->visota_transp)
{
int j = 0;
while (j<inM->dlinna_transp)
{
printf (" %d ", inM->transponovanaya_mass[i][j]);

j++;
}
printf ("\n \n");

i++;
}
}



void matrix (struct matrica *inM)
{
    int i, j, t;
printf("Enter mass\n Enter dlinna mass\n");
scanf("%i", &inM->dlinna);
printf("Enter visota mass\n");
scanf("%i", &inM->visota);
printf("Enter element matr\n");
i = 0;
while (i<inM->visota) {
j = 0;
while (j<inM->dlinna) {
t=0;
scanf ("%i", &t);
inM->mass[i][j] = t;
j++;
}
i++;
};
}



void transp(struct matrica *inM)
{
    int x =0;
    int y =0;
int j=0;

while (j<inM->dlinna)
{
y=0;
int i = 0;
while(i<inM->visota)
{
inM->transponovanaya_mass[x][y]  = inM->mass[i][j];
y++;
i++;
}
x++;
j++;
}
inM->dlinna_transp=inM->visota;
inM->visota_transp=inM->dlinna;
}

