#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int A=0;
    int B=0;
    int C=0;
    int A1=0;   //modul A
    int B1=0;   //modul B
    int C1=0;   //modul C
    int u=0;    //A^2+B^2
    float st=1; //stepen
    float d=0;  //B+5^C
    int r=1;    //B!
    ///////////////////////vvodim danie
    printf("Введите целое число A = ");
    if(scanf("%i",&A)!=1)
    {
        printf("Вы ввели букву!!!\n");
        return 0;
    }
    
    if(A>10000)
    {
        printf("Введите меньше число A!!!\n");
        return 0;
    }
    //.....................................
    printf("Введите целое число B = ");
    if(scanf("%i",&B)!=1)
    {
        printf("Вы ввели букву!!!\n");
        return 0;
    }
    
    if(B>10)
    {
        printf("Введите меньше число B!!!\n");
        return 0;
    }
    //.....................................
    printf("Введите целое число C = ");
    if(scanf("%i",&C)!=1)
    {
        printf("Вы ввели букву!!!\n");
        return 0;
    }
    
    if(A>10000)
    {
        printf("Введите меньше число C!!!\n");
        return 0;
    }
    /////////////////////////////////////raschet A^2+B^2
    if(A<0)
    {
        A1=abs(A);
    }
    else
    {
        A1=A;
    }
    //.............
    if(B<0)
    {
        B1=abs(B);
    }
    else
    {
        B1=B;
    }
    //..............
    if(C<0)
    {
        C1=abs(C);
    }
    else
    {
        C1=C;
    }
    ///////////....
    u=A1*A1+B1*B1;
    
    ////////////////////////////////////raschet B+5^C
    if(C>0)
    {
        for(int i=1;i<=C;i++)
        {
            st=st*5;
        }
    }
    else if(C==0)
    {
        st=1;
    }
    else if(C<0)
    {
        
        for(int j=1;j<=C1;j++)
        {
            st=st/5;
        }
    }
    d=B+st;
    if(d==0)
    {
        printf("Невозможно посчитать\n");
        return 0;
    }
    //////////////////////////////////////////raschet B!
    for(int k=1;k<=B1;k++)
    {
        r=r*k;
    }
    if(B<0)
    {
        r=-r;
    }
    /////////////////////////summa
    float Q=u/d+r;  //...(A^2+B^2)/(B+5^C)+B!
    printf("Q = %f\n",Q);
    
}




    if(d==0)
    {
        printf("Невозможно посчитать\n");
        return 0;
    }
