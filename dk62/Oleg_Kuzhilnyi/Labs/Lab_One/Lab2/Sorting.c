//
//  Sorting.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

void BubbleSort(int *MassOfNumber)
{
for(int i = 0;i < ELEMENTS; i++)
{
    for(int j = 0; j < ELEMENTS-1;j++)
    {
        
        if (MassOfNumber[j] > MassOfNumber[j+1])
        {
            swap(MassOfNumber,i,j+1);
        }
    }
   }

}

void SelectSort(int *MassOfNumber)
{
    for(int i = 0; i< ELEMENTS; i++)
    {
        int min = i;
        for(int j = i;j < ELEMENTS; j++)
        {
            if(MassOfNumber[j] < MassOfNumber[min])
            {
                min = j;
            }
        }
        swap(MassOfNumber,i,min);
    }
}

void QuickSort(int *MassOfNumber,int left,int right)
{
    int i,last;
    if(left >= right)
    return;
    
    swap(MassOfNumber,left,(left + right)/2);
    last = left;
            for (i = left+1;i <=right;i++)
         if(MassOfNumber[i] < MassOfNumber[left])
             swap(MassOfNumber,++last,i);
    swap(MassOfNumber,left,last);
    QuickSort(MassOfNumber,left,last-1);
    QuickSort(MassOfNumber, last+1, right);
}

void ShellsSort(int *MassOfNumber)
{
    int t = 0;
    for(int q = ELEMENTS/2; q > 0; q /= 2)
        for(int i = q; i < ELEMENTS; i += 1)
        {
            t = MassOfNumber[i];
            int j = 0;
            for(j = i; j >= q; j -= q)
            {
                if(t < MassOfNumber[j-q])
                    MassOfNumber[j] = MassOfNumber[j-q];
                else
                break;
            }
            MassOfNumber[j] = t;
        }
}

void swap(int *v,int i,int j)//transposition two elements of array
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
