//
// Created by Oleh on 26.03.2017.
//
#include "sort.h"
#include <time.h>

//declaration swap function
void swap(int *theInt1, int *theInt2);

//bubble sort
double bubbleSort(int *anArray, int aSize)
{
    clock_t theStart = clock();
    for (int theOut = aSize - 1; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (*(anArray+theIn) > *(anArray+theIn+1))
            {
                swap((anArray+theIn), (anArray+theIn+1));
            }
        }
    }
    clock_t theEnd = clock();
    return (double)(theEnd - theStart)/CLOCKS_PER_SEC;
}

//selection sort
double selectionSort(int *anArray, int aSize)
{
    clock_t theStart = clock();
    for (int theOut = 0; theOut < aSize - 1; theOut ++)
    {
        int theMinIndex = theOut;

        for (int theIn = theOut + 1; theIn < aSize; theIn ++)
        {
            if (*(anArray+theIn) < *(anArray+theMinIndex))
            {
                theMinIndex = theIn;
            }
        }
        swap((anArray+theOut), (anArray+theMinIndex));
    }
    clock_t theEnd = clock();
    return (double)(theEnd - theStart)/CLOCKS_PER_SEC;
}

//insertion sort
double insertionSort(int *anArray, int aSize)
{
    clock_t theStart = clock();
    for (int theOut = 1; theOut < aSize; theOut ++)
    {
        int theTmp = *(anArray+theOut);
        int theIn = theOut;

        while (theIn > 0 && *(anArray+theIn - 1) >= theTmp)
        {
            *(anArray+theIn) = *(anArray+theIn - 1);
            -- theIn;
        }

        *(anArray+theIn) = theTmp;
    }
    clock_t theEnd = clock();
    return (double)(theEnd - theStart)/CLOCKS_PER_SEC;
}

//swap function
void swap(int *theInt1, int *theInt2)
{
    int temp=*theInt1;
    *theInt1=*theInt2;
    *theInt2=temp;
}