//
//  Sorting.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

int line_search(theDescriptionArray *iArray ,unsigned aSize)
{
    int key = 0;
    puts("Please Enter integer which you want to find in Array:");
    scanf("%i", &key);
    
    for (int thePosition = 0; thePosition < aSize; thePosition++)
    {
        if (iArray->value[thePosition] == key)
            {
                puts("The line search could find next information:");
                puts("-------------------");              
                printf("|The key: %i\n|The Position: %i\n",key,thePosition);
                puts("-------------------");
                        return thePosition;
            }
    }
  
    puts("NO have this element in Array");
    return -1;
}
void QuickSort(theDescriptionArray *MassOfNumbers,int left,int right)  //Quick Sort
{
    int TheOut,last;
    if(left >= right)
        return;
    
    swap(MassOfNumbers,left,(left + right)/2);
    last = left;
    for (TheOut = left+1;TheOut <=right;TheOut++)
        if(MassOfNumbers->value[TheOut] < MassOfNumbers->value[left])
            swap(MassOfNumbers,++last,TheOut);
    swap(MassOfNumbers,left,last);
    QuickSort(MassOfNumbers,left,last-1);
    QuickSort(MassOfNumbers, last+1, right);
}

void bubbleSort(theDescriptionArray *iArray)
{
    for (int theOut = iArray->current_size-1 ; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (iArray->value[theIn] > iArray->value[theIn+1])
            {
                swap(iArray,iArray->value[theIn],iArray->value[theIn+1]);
            }
        }
    }
}

void selectionSort(theDescriptionArray *iArray)
{
    for (int theOut = 0; theOut < iArray->current_size- 1; theOut ++)
    {
        int theMinIndex = theOut;
        
        for (int theIn = theOut + 1; theIn < iArray->current_size; theIn ++)
        {
            if (iArray->value[theIn] < iArray->value[theMinIndex])
            {
                theMinIndex = theIn;
            }
        }
        //swap(iArray,iArray->value[theOut],iArray->value[theMinIndex]);

        
        int theTmp = iArray->value[theOut];
        iArray->value[theOut] = iArray->value[theMinIndex];
        iArray->value[theMinIndex] = theTmp;
    }
}
void insertionSort(theDescriptionArray *iArray)
{
    for (int theOut = 1; theOut < iArray->current_size; theOut ++)
    {
        int theTmp = iArray->value[theOut];
        int theIn = theOut;
        
        while (theIn > 0 && iArray->value[theIn - 1] >= theTmp)
        {
            iArray->value[theIn] = iArray->value[theIn - 1];
            -- theIn;
        }
        
        iArray->value[theIn] = theTmp;
    }
}

void swap(theDescriptionArray *srcArray,int x,int y)//transposition two elements of array
{
    
    int temp = srcArray->value[x];
    srcArray->value[x] = srcArray->value[y];
    srcArray->value[y] = temp;
}

void TheSorts_For_DifferentArrays(theDescriptionArray *Small, theDescriptionArray *Medium, theDescriptionArray *theBig , theDescriptionArray *TheBiggest)
{
    TheArrayList TimeClass ;
    float TheTimeAtTheMoment;

    // -----------------------------------------------------------------------------//   Quick Sort
    
    FillingInTypeOfArrays(Small);
    TheTimeAtTheMoment = clock();
    QuickSort(Small, ZERO, Small->current_size);
    TimeClass.For_Q_Sort.TheTime[0] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(Medium);
    TheTimeAtTheMoment = clock();
    QuickSort(Medium, ZERO, Medium->current_size);
    TimeClass.For_Q_Sort.TheTime[1] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(theBig);
    TheTimeAtTheMoment = clock();
    QuickSort(theBig, ZERO, theBig->current_size);
    TimeClass.For_Q_Sort.TheTime[2] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(TheBiggest);
    TheTimeAtTheMoment = clock();
    QuickSort(TheBiggest, ZERO, TheBiggest->current_size);
    TimeClass.For_Q_Sort.TheTime[3] = TheResultOfTimePoint(TheTimeAtTheMoment);
  
    // -----------------------------------------------------------------------------//      Bubble Sort
    
    FillingInTypeOfArrays(Small);
    TheTimeAtTheMoment = clock();
    bubbleSort(Small);
    TimeClass.For_B_Sort.TheTime[0] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(Medium);
    TheTimeAtTheMoment = clock();
    bubbleSort(Medium);
    TimeClass.For_B_Sort.TheTime[1] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(theBig);
    TheTimeAtTheMoment = clock();
    bubbleSort(theBig);
    TimeClass.For_B_Sort.TheTime[2] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(TheBiggest);
    TheTimeAtTheMoment = clock();
    bubbleSort(TheBiggest);
    TimeClass.For_B_Sort.TheTime[3] = TheResultOfTimePoint(TheTimeAtTheMoment);

    // -----------------------------------------------------------------------------//      Selection Sort
    
    
    FillingInTypeOfArrays(Small);
   TheTimeAtTheMoment = clock();
    selectionSort(Small);
    TimeClass.For_S_Sort.TheTime[0] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(Medium);
    TheTimeAtTheMoment = clock();
    selectionSort(Medium);
    TimeClass.For_S_Sort.TheTime[1] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(theBig);
    TheTimeAtTheMoment = clock();
    selectionSort(theBig);
    TimeClass.For_S_Sort.TheTime[2] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(TheBiggest);
    TheTimeAtTheMoment = clock();
    selectionSort(TheBiggest);
    TimeClass.For_S_Sort.TheTime[3] = TheResultOfTimePoint(TheTimeAtTheMoment);

    // -----------------------------------------------------------------------------//  Insertion Sort
    
    FillingInTypeOfArrays(Small);
    TheTimeAtTheMoment = clock();
    insertionSort(Small);
    TimeClass.For_I_Sort.TheTime[0] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(Medium);
    TheTimeAtTheMoment = clock();
    insertionSort(Medium);
    TimeClass.For_I_Sort.TheTime[1] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(theBig);
    TheTimeAtTheMoment = clock();
    insertionSort(theBig);
    TimeClass.For_I_Sort.TheTime[2] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(TheBiggest);
    TheTimeAtTheMoment = clock();
    insertionSort(TheBiggest);
    TimeClass.For_I_Sort.TheTime[3] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    // -----------------------------------------------------------------------------//  The End
    
    
    PrintfTheResultTable(&TimeClass);

}

void PrintfTheResultTable(TheArrayList *VariableTime)
{
    printf("@===============================================================================@\n");
    printf("||=");
    printf("/TYPE OF SORT/");
    printf("===");
    printf("/SMALL/");
    printf("=====");
    printf("/MEDIUM/");
    printf("==========");
    printf("/BIG/");
    printf("========");
    printf("/THE BIGGEST/");
    printf("====|\n");
    
    printf("||QuickSort");
    printf("========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[0]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[1]);
    printf("=========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[2]);
    printf("==========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[3]);
    printf("=====|\n");
    
    printf("||BubbleSort");
    printf("=======");
    printf("|%.0fms|",VariableTime->For_B_Sort.TheTime[0]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_B_Sort.TheTime[1]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_B_Sort.TheTime[2]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_B_Sort.TheTime[3]);
    printf("===|\n");
    
    printf("||SelectionSort");
    printf("====");
    printf("|%.0fms|",VariableTime->For_S_Sort.TheTime[0]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_S_Sort.TheTime[1]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_S_Sort.TheTime[2]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_S_Sort.TheTime[3]);
    printf("===|\n");
    
    printf("||InsertionSort");
    printf("====");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[0]);
    printf("=========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[1]);
    printf("==========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[2]);
    printf("===========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[3]);
    printf("======|\n");
    
    printf("||=================");
    printf("[TIME]");
    printf("=========");
    printf("[TIME]");
    printf("==========");
    printf("[TIME]");
    printf("============");
    printf("[TIME]");
    printf("======|\n");
    
    printf("@===============================================================================@\n\n");
    
}
