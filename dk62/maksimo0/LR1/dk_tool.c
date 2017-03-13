#include "dk_tool.h"
#include <math.h>

double Obchislennya_Za_Formulou(int A, int B, int C)
{
    if(((B+C)>=0)&&(B!=0)&&(A>=0)&&(C>=0)&&((A+C)<=170))     //перевірка на недопустимі дані
    {
        double Dobutok, Rezultat, Sigma=0;
        int K;
        Dobutok=(A*(sqrt(B+C)))/B;                           //обчислення добутку в формулі
        double Factorial(int K)
        {
            if(K==0||K==1)                                   //перевірка на "0" та "1", так як їхній факторіал рівний "1"
            {
                return 1;
            }
            return K * Factorial(K - 1);
        }
        for (int D=0; D<=C; D++)
        {
            K=A+D;
            Sigma=Sigma+Factorial(K);                       //обчислення суми факторіалів в якій викликається функція для обчислення факторіалу
        }
        Rezultat=Dobutok+Sigma;
        return Rezultat;
    }
    else
    {
        printf("Obrakhunok nemogliviy abo rezultat zanadto velikiy, vvedit novi dani\n"); //повідомлення яке буде виводитись на екран, якщо користувач ввів хибні дані
    }

}
