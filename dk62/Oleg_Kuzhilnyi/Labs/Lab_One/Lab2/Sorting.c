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

void InsertSort(int *MassOfNumbers,int aSize)
{
    int newElement, location;
    
    for (int TheOut = 1; TheOut < aSize; TheOut++)
    {
        newElement = MassOfNumbers[TheOut];
        location = TheOut - 1;
        while(location >= 0 && MassOfNumbers[location] > newElement)
        {
            MassOfNumbers[location+1] = MassOfNumbers[location];
            location = location - 1;
        }
        MassOfNumbers[location+1] = newElement;
    }
}


void swap(int *Numbers,int First,int Second)//transposition two elements of array
{
    int temp;
    temp = Numbers[First];
    Numbers[First] = Numbers[Second];
    Numbers[Second] = temp;
}
