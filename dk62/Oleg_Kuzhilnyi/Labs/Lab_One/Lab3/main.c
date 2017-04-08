//
//  main.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

int main(int argc, const char * argv[])
{
  //  FILE *theFileForSort = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/SortedElemets.txt","w");
    
    const unsigned int CountOfElements = AMOUNT;//10000
    
    theDescriptionArray MassOfNumber = createArray(CountOfElements);
    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < CountOfElements; i++)   //Input CountOfElements  elements in Array
    {
        input_in_Array(&MassOfNumber , (unsigned)random() %100);
        //GenerateArray_OfintRandom(int aSize, int *MassOfNumbers, int min, int max)
    }
    puts("Please create a choose:\n(q)sort, (b)ubble sort, (s)election sort,(i)nsertion sort:");
    char option = '\0';
    
    while  (        option != 'q' &&
                        option != 'b' &&
                            option != 's' &&
                                option != 'i'
            )
    {
        option = getchar();
    }
    float time = clock(); // time at this moment
    
    switch(option)
    {
        case 'q':
            QuickSort(&MassOfNumber, ZERO, MassOfNumber.current_size);
            break;
        case 'b':
            bubbleSort(&MassOfNumber);
            break;
        case 's':
            selectionSort(&MassOfNumber);
            break;
        case 'i':
            insertionSort(&MassOfNumber);
            break;
    }
    time = (clock() - time); //The time one of option sort in miliseconds
    printf("\"Time performance the %c-sort : %.1f ms\"\n", option,time);
    Print_To_File (MassOfNumber.current_size,&MassOfNumber); // Print Sorted array to file
    
    time = clock();
    line_search(&MassOfNumber,MassOfNumber.current_size);
    time = (clock() - time); // The time of performance the line search in ms
    printf("\"Time performance the line search: %.0f ms\"\n",time);
    
    
    
    return 0;
}
