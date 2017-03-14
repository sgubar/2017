//
//  Sorting.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

void BubbleSort(int *MassOfNumbers,int aSize)
{
for(int TheOut = 0;TheOut < aSize; TheOut++)
{
    for(int TheIn = 0; TheIn < aSize-1;TheIn++)
    {
        
        if (MassOfNumbers[TheIn] > MassOfNumbers[TheIn+1])
        {
            swap(MassOfNumbers,TheOut,TheIn+1);
        }
    }
   }

}

void SelectSort(int *MassOfNumbers,int aSize)
{
    for(int TheOut = 0; TheOut< aSize; TheOut++)
    {
        int min = TheOut;
        for(int TheIn = TheOut;TheIn < aSize; TheIn++)
        {
            if(MassOfNumbers[TheIn] < MassOfNumbers[min])
            {
                min = TheIn;
            }
        }
        swap(MassOfNumbers,TheOut,min);
    }
}

void QuickSort(int *MassOfNumbers,int left,int right)
{
    int TheOut,last;
    if(left >= right)
    return;
    
    swap(MassOfNumbers,left,(left + right)/2);
    last = left;
            for (TheOut = left+1;TheOut <=right;TheOut++)
         if(MassOfNumbers[TheOut] < MassOfNumbers[left])
             swap(MassOfNumbers,++last,TheOut);
    swap(MassOfNumbers,left,last);
    QuickSort(MassOfNumbers,left,last-1);
    QuickSort(MassOfNumbers, last+1, right);
}

void ShellsSort(int *MassOfNumbers,int aSize)
{
    int t = 0;
    for(int q = aSize/2; q > 0; q /= 2)
        for(int TheOut = q; TheOut < aSize; TheOut += 1)
        {
            t = MassOfNumbers[TheOut];
            int TheIn = 0;
            for(TheIn = TheOut; TheIn >= q; TheIn -= q)
            {
                if(t < MassOfNumbers[TheIn-q])
                    MassOfNumbers[TheIn] = MassOfNumbers[TheIn-q];
                else
                break;
            }
            MassOfNumbers[TheIn] = t;
        }
}

void swap(int *v,int i,int j)//transposition two elements of array
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
