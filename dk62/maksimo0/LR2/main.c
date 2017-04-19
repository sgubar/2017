//
// Created by Max on 18.04.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "sort.h"

int main(int argc, const char * argv[])
{
    int LengthOfStr=LengthOfUnsortedArray("File.txt");

    char *Str1=FileToStr();
    if(NULL!=Str1)
    {
        clock_t TheBegin1=clock();
        bubbleSort(Str1, LengthOfStr);
        clock_t TheEnd1=clock();
        printf("time of bubbleSort:%f\n", (float)(TheEnd1-TheBegin1)/CLOCKS_PER_SEC);
    }
    //PrintToFile(Str1);
    free(Str1);

    char *Str2=FileToStr();
    if(NULL!=Str2)
    {
        clock_t TheBegin2=clock();
        selectionSort(Str2, LengthOfStr);
        clock_t TheEnd2=clock();
        printf("time of selectionSort:%f\n", (float)(TheEnd2-TheBegin2)/CLOCKS_PER_SEC);
    }
    PrintToFile(Str2);
    free(Str2);

    char *Str3=FileToStr();
    if(NULL!=Str3)
    {
        clock_t TheBegin3=clock();
        insertionSort(Str3, LengthOfStr);
        clock_t TheEnd3=clock();
        printf("time of insertionSort:%f\n", (float)(TheEnd3-TheBegin3)/CLOCKS_PER_SEC);
    }
    //PrintToFile(Str3);
    free(Str3);

    return 0;
}