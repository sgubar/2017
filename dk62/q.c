#include<stdio.h>

int main(void)
{
printf("ROW:");
int x = 0;
scanf("%d",x);
printf("COL:");
int y = 0;
scanf("%d",y);
 int mac[x][y];
int a = 0;
int b = 0;
scanf("%d",a);
scanf("%d",b);
int mas[a][b];
int z = mas[x][y]+mas[a][b];
printf("%d",z);
}
