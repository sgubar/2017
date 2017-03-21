#include <stdio.h>
#include "dk_tool.h" /*підключення директиви, з яких препроцесор зчитує зміст файлу, що знаходиться в одній папці звиконавчим файло, а також виконує директиви і підстановки*/

float sum_of_factorials(float D,float B) /* обчислюємо суму всіх факторіалів, починаючи з D=0 по B, значення якого ми отримуємо з клавіатури*/
{
float sum=0;
float fact=1;

    for (D=0;D<=B;D++)
    {
        if (D==0)
            sum++;
        else
        {
            fact=fact*D;
            sum = fact + sum;
        }
    }
   return sum;
    printf("\n");
}

float sqr(float C) /* піднесення до квадрату числа C, яке ми також отримуємо з клавіатури*/
{
    float result=0;
    result=C*C;
return result;
}

