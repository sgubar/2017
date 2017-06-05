#include "dk_toollab1.h"
#include <math.h>

double Obchislennya_Za_Formulou(int A, int B, int C)
{
    if(((B+C)>=0)&&(B!=0)&&(A>=0)&&(C>=0)&&((A+C)<=170))     
    {
        double Dobutok, Rezultat, Sigma=0;
        int K;
        Dobutok=(A*(sqrt(B+C)))/B;                          
        double Factorial(int K)
        {
            if(K==0||K==1)                                   
            {
                return 1;
            }
            return K * Factorial(K - 1);
        }
       for (int D=0; D<=C; D++)
        {
            K=A+D;
            Sigma=Sigma+Factorial(K);                       
        }
        Rezultat=Dobutok+Sigma;
        printf("Rezultat:%.3Lf", Rezultat);               
    }
    else
    {
        printf("Obrakhunok nemogliviy \n"); 
    }

}
