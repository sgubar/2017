//
// Created by Max on 18.04.2017.
//

#include "sort.h"

void bubbleSort(char UnsortedArray[], int Length)
{
    for(int theOut=Length-1; theOut>1; theOut--)
    {
        for(int theIn=0; theIn<theOut; theIn++)
        {
            if (UnsortedArray[theIn]<UnsortedArray[theIn+1])
            {
                char theTmp=UnsortedArray[theIn];
                UnsortedArray[theIn]=UnsortedArray[theIn + 1];
                UnsortedArray[theIn+1]=theTmp;
            }
        }
    }
}

void selectionSort(char UnsortedArray[], int Length)
{
    for(int theOut=0; theOut<Length-1; theOut++)
    {
        int theMinIndex=theOut;
        for(int theIn=theOut+1; theIn<Length; theIn++)
        {
            if(UnsortedArray[theIn]>UnsortedArray[theMinIndex])
            {
                theMinIndex=theIn;
            }
        }
        char theTmp=UnsortedArray[theOut];
        UnsortedArray[theOut]=UnsortedArray[theMinIndex];
        UnsortedArray[theMinIndex]=theTmp;
    }
}

void insertionSort(char UnsortedArray[], int Length)
{
    for(int theOut=1; theOut<Length; theOut++)
    {
        char theTmp=UnsortedArray[theOut];
        int theIn=theOut;
        while(theIn>0&&UnsortedArray[theIn-1]<=theTmp)
        {
            UnsortedArray[theIn]=UnsortedArray[theIn-1];
            --theIn;
        }
        UnsortedArray[theIn]=theTmp;
    }
}
