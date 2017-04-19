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

void shellSort(char UnsortedArray[], int Length)
{
    int theInner=0;
    int theOuter=0;
    int theH=1;
    while(theH<=Length/3)
    {
        theH=theH*3+1;
    }
    while(theH>0)
    {
        for(theOuter=theH;theOuter<Length; theOuter++)
        {
            char theTmp=UnsortedArray[theOuter];
            theInner=theOuter;
            while(theInner>theH-1&&UnsortedArray[theInner-theH]<=theTmp)
            {
                UnsortedArray[theInner]=UnsortedArray[theInner-theH];
                theInner-=theH;
            }
            UnsortedArray[theInner]=theTmp;
        }
        theH=(theH-1)/3;
    }
}

int BinarySearch(char UnsortedArray[], int Length, int Find)
{
    int theResult=-1;
    int theLowerBound=0;
    int theUpperBound=Length;
    int theCurIn=0;
    while (1)
    {
        theCurIn=(theLowerBound+theUpperBound)/2;
        if (UnsortedArray[theCurIn]==Find)
        {
            theResult=theCurIn;
            break;
        }
        else if(theLowerBound>theUpperBound)
        {
            break;
        }
        else
        {
            if(UnsortedArray[theCurIn]>Find)
            {
                theLowerBound=theCurIn+1;
            }
            else
            {
                theUpperBound=theCurIn-1;
            }
        }
    }
    return theResult;
}