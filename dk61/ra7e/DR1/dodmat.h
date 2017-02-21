#ifndef dodmat_h
#define dodmat_h
#include <stdio.h>

void mat1 ()

{
int x,i,j,n,m,a1,b2,y,q,mass3[10][10],mass1[10][10],mass2[10][10],a2;
x=0;
i=0;
j=0;
n=0;
m=0;
while (x<a1){
y=0;
while(y<b2) {
m=0;
j=0;
q=0;
mass3[x][y] = 0;
while (q<a2){
mass3[x][y]=mass3[x][y]+(mass1[i][j]*mass2[m][n]);
m++;
j++;
q++;
}
n++;
y++;
}
i++;
n=0;
x++;
}

}

#endif // dodmat_h
