#ifndef dodmat_h
#define dodmat_h
#include <stdio.h>

void mat1 ()

{
int x,i,j,n,a,ryad1,kol2,y,q, rez_mas[10][10],first_mas[10][10],second_mas[10][10],ryad2;
x=0;
i=0;
j=0;
n=0;
a=0;
while (a<ryad1){
y=0;
while(y<kol2) {
a=0;
j=0;
q=0;
rez_mas[a][y] = 0;
while (q<ryad2){
rez_mas[a][y]=rez_mas[a][y]+(first_mas[i][j]*second_mas[a][n]);
a++;
j++;
q++;
}
n++;
y++;
}
i++;
n=0;
a++;
}

}

#endif // dodmat_h
