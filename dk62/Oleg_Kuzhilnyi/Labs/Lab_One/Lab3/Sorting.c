//
//  Sorting.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

void bubbleSort(theDescriptionArray *iArray)
{
    for (int theOut = iArray->current_size-1 ; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (iArray->value[theIn] > iArray->value[theIn+1])
            {
                int theTmp = iArray->value[theIn];
                iArray->value[theIn] = iArray->value[theIn+1];
                iArray->value[theIn+1] = theTmp;
            }
        }
    }
}

//-----------------------------------------------------------------------------------------//

void insertionSort(theDescriptionArray *iArray)
{
    int newElement, location;
    
    for (int TheOut = 1; TheOut < iArray->maxSize; TheOut++)
    {
        newElement = iArray->value[TheOut];
        location = TheOut - 1;
        while(location >= 0 && iArray->value[location] > newElement)
        {
            iArray->value[location+1] = iArray->value[location];
            location = location - 1;
        }
        iArray->value[location+1] = newElement;
    }
}

//-----------------------------------------------------------------------------------------//

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
//-----------------------------------------------------------------------------------------//

void quickSort(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }
    
    int thePivot = anArray->value[aRightIndex];
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
    
    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
    
    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

//-----------------------------------------------------------------------------------------//

int line_search(theDescriptionArray *iArray ,unsigned aSize)
{
    int key = rrand(ZERO,ONE_THOUSAND);
    /*
    puts("Please Enter integer which you want to find in Array:");
    scanf("%i", &key);
     */
    
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

//-----------------------------------------------------------------------------------------//

void TheSorts_For_DifferentArrays(theDescriptionArray *Small, theDescriptionArray *Medium, theDescriptionArray *theBig , theDescriptionArray *TheBiggest)
{
    TheArrayList TimeClass ;
    float TheTimeAtTheMoment;
    

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
    
    // -----------------------------------------------------------------------------//  Insertion Sort
    
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
    
    // -----------------------------------------------------------------------------//      Bubble Sort
    
    
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
  
    
    // -----------------------------------------------------------------------------//  Selection Sort
    
    FillingInTypeOfArrays(Small);
    TheTimeAtTheMoment = clock();
    quickSort(Small, ZERO, Small->current_size);
    TimeClass.For_Q_Sort.TheTime[0] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(Medium);
    TheTimeAtTheMoment = clock();
    quickSort(Medium, ZERO, Medium->current_size);
    TimeClass.For_Q_Sort.TheTime[1] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(theBig);
    TheTimeAtTheMoment = clock();
    quickSort(theBig, ZERO, theBig->current_size);
    TimeClass.For_Q_Sort.TheTime[2] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    FillingInTypeOfArrays(TheBiggest);
    TheTimeAtTheMoment = clock();
    quickSort(TheBiggest, ZERO, TheBiggest->current_size);
    TimeClass.For_Q_Sort.TheTime[3] = TheResultOfTimePoint(TheTimeAtTheMoment);
    
    // -----------------------------------------------------------------------------//     Quick Sort
    
    PrintfTheResultTable(&TimeClass);
    
}

void PrintfTheResultTable(TheArrayList *VariableTime)


{
    printf("@================================|^Sort Table^|=================================@\n");
    printf("||");
    printf("****************^Size Of^******^Size Of^*******^Size Of^*********^Size Of^****|\n");
    printf("||=");
    printf("/TYPE OF SORT/");
    printf("===");
    printf("/%i/",HUNDRED);
    printf("=========");
    printf("/%i/",ONE_THOUSAND);
    printf("==========");
    printf("/%i/",TEN_THOUSAND);
    printf("===========");
    printf("/%i/",TWENTY_THOUSAND);
    printf("=====|\n");
    
    printf("||QuickSort");
    printf("========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[0]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[1]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[2]);
    printf("=========");
    printf("|%.0fms|",VariableTime->For_Q_Sort.TheTime[3]);
    printf("===|\n");
    
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
    printf("========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[1]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[2]);
    printf("========");
    printf("|%.0fms|",VariableTime->For_I_Sort.TheTime[3]);
    printf("===|\n");
    
    printf("||=================");
    printf("[TIME]");
    printf("=========");
    printf("[TIME]");
    printf("===========");
    printf("[TIME]");
    printf("============");
    printf("[TIME]");
    printf("=====|\n");
    
    printf("@===============================================================================@\n\n");
    
}



int partitionIt(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;
    
    while (1)
    {
        // search the bigest element
        while (anArray->value[++theLeft] < aPivot);
        
        // search the lowest element
        while (theRight > 0 && anArray->value[--theRight] > aPivot);
        
        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            
            
            int theTmp = anArray->value[theLeft];
            anArray->value[theLeft] = anArray->value[theRight];
            anArray->value[theRight] = theTmp;
        }
    }
    
    //lets to swap elements
    int theTmp = anArray->value[theLeft];
    anArray->value[theLeft] = anArray->value[aRightIndex];
    anArray->value[aRightIndex] = theTmp;
    
    return theLeft; // return break position
}

void swap(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex)
{
    int theTmp = anArray->value[aLeftIndex];
    anArray->value[aLeftIndex] = anArray->value[aRightIndex];
    anArray->value[aRightIndex] = theTmp;
}
