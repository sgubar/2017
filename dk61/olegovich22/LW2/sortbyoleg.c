//
// Created by Oleh on 26.03.2017.
//
//
// Created by Oleh on 08.03.2017.
//

#include "dk_tool.h"
/*
void swap(int *firstInt, int *secondInt)
{
    int time=*firstInt;
    *firstInt=*secondInt;
    *secondInt=time;
}

void bubbleSort(int size, int *oleg)
{
    int repair=0;
    for(int i=0; i<size-1; i++)
    {
        for (int j=0; j < size-1-i; j++)
        {
            if (*(oleg+j)>*(oleg+1+j))
            {
                swap((oleg+j), (oleg+1+j));
                repair++;
            }
        }
        if(repair==0)
        {
            break;
        }
        repair=0;
    }
}

void choose(int size, int oleg[])
{
    int theSmallest=0;
    int positionSmalest=0;
    for (int i = 0; i < size-1; ++i) {

        theSmallest = oleg[i];
        positionSmalest = i;

        for (int j = i + 1; j < size; ++j) {
            if (oleg[j] < theSmallest) {
                theSmallest = oleg[j];
                positionSmalest = j;
            }
        }
        int time=oleg[i];
        oleg[i]=theSmallest;
        oleg[positionSmalest]=time;
    }
}

void vstavkou(int size, int oleg[])
{
    // int position=-1;
    int theSecond=0;
    for (int i = 0; i < size-1; ++i) {

        theSecond=oleg[i+1];

        for (int j = i+1; j > 0 && theSecond<oleg[j-1]; --j)
        {
            int time=oleg[j-1];
            oleg[j-1]=theSecond;
            oleg[j]=time;
            // oleg[j]=oleg[j-1];
            //position=j-1;
        }
        //if (position!=-1)
        //{
        //  oleg[position]=theSecond;
        // position=-1;
        //}
    }
}
int firstInterval(int size)
{
    int h=1;
    while ((3*h+1)<size)
    {
        h=3*h+1;
    }
    return h;
}


void shell_sort(int oleg[], int size)
{
    for (int interval = firstInterval(size); interval >=1; interval=(interval-1)/3)
    {
        for (int firstPosition = interval; firstPosition < size; firstPosition++)
        {
            for (int currentPosition=firstPosition; currentPosition>=interval && oleg[currentPosition]<oleg[currentPosition-interval]; currentPosition-=interval)
            {
                int time=oleg[currentPosition];
                oleg[currentPosition]=oleg[currentPosition-interval];
                oleg[currentPosition-interval]=time;
            }
        }
    }
}

void quick_sort(int oleg[], int thefirst, int thelast)
{
    int i=thefirst, j=thelast, t=(thefirst+thelast)/2, x=*(oleg+t);
    do{
        while (*(oleg+i)<x)
            i++;
        while (*(oleg+j)>x)
            j--;

        if (i<=j)
        {
            if (*(oleg+i)>*(oleg+j))
                // swap((oleg+i),(oleg+j));
                i++;
            j--;
        }
    }
    while (i<=j);
    if (i < thelast)
        quick_sort(oleg, i, thelast);
    if (thefirst < j)
        quick_sort(oleg, thefirst, j);
}*/


