#include<stdio.h>
#include <math.h>

int main(void)
{
int A = 0;
int B = 0;
int C = 0;
int right=0;
int K=0;
printf("Вводим А:");
scanf("%d",&A);

printf("Вводим В:");
scanf("%d",&B);

printf("Вводим C:");
scanf("%d",&C);

float koren = sqrt( B + C);
float left = koren*A/B;


for(int i = 0; i < C+1; i++ )
{
K=1;
for(int j=1; j<A+i+1; j++)
{
K=K*j;

}
right=right+K;
}
float Q = left + right;
printf("left=%f\n",left);
printf("right=%d\n",right);
printf("Q= %f\n" ,Q);
}
