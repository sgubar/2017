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
    
    
    theDescriptionArray ArrayWithTen = createArray(10);
    theDescriptionArray ArrayWithHundred = createArray(100);
    theDescriptionArray ArrayWithOneThousand = createArray(1000);
    theDescriptionArray ArrayWithTenThousand = createArray(10000);

    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < TEN; i++)   //Input CountOfElements  elements in Array
        input_in_Array(&ArrayWithTen , (unsigned)random() %TEN);
    
    
    for(int i = 0 ; i < HUNDRED; i++)   //Input CountOfElements  elements in Array
        input_in_Array(&ArrayWithHundred , (unsigned)random() %HUNDRED);
    
    
    for(int i = 0 ; i < ONE_THOUSAND; i++)   //Input CountOfElements  elements in Array
        input_in_Array(&ArrayWithOneThousand , (unsigned)random() %ONE_THOUSAND);
    
    for(int i = 0 ; i < TEN_THOUSAND; i++)   //Input CountOfElements  elements in Array
        input_in_Array(&ArrayWithTenThousand , (unsigned)random() %TEN_THOUSAND);
    
    
    puts("Please create a choose:\n(Q)sort, (B)ubble sort, (S)election sort,(I)nsertion sort:");
    char option = '\0';
    
    while  (        option != 'Q' &&
                        option != 'B' &&
                            option != 'S' &&
                                option != 'I'
            )
    {
        option = getchar();
    }
    float TimeForTen = clock(); // time at this moment
    float TimeForHundred = clock();
    float TimeForOneThousand = clock();
    float TimeForTenThousand = clock();

    switch(option)
    {
        case 'Q':
            
            QuickSort(&ArrayWithTen, ZERO, ArrayWithTen.current_size);
            TimeForTen = (clock()-TimeForTen);
            QuickSort(&ArrayWithHundred, ZERO, ArrayWithHundred.current_size);
            TimeForHundred = (clock()-TimeForHundred);

            QuickSort(&ArrayWithOneThousand, ZERO, ArrayWithOneThousand.current_size);
            TimeForOneThousand = (clock()-TimeForOneThousand);

            QuickSort(&ArrayWithTenThousand, ZERO, ArrayWithTenThousand.current_size);
            TimeForTenThousand = (clock()-TimeForTenThousand);

            break;
        case 'B':
            
            bubbleSort(&ArrayWithTen);
            TimeForTen = (clock()-TimeForTen);

              bubbleSort(&ArrayWithHundred);
            TimeForHundred = (clock()-TimeForHundred);

              bubbleSort(&ArrayWithOneThousand);
            TimeForOneThousand = (clock()-TimeForOneThousand);

              bubbleSort(&ArrayWithTenThousand);
            TimeForTenThousand = (clock()-TimeForTenThousand);

            break;
        case 'S':
            
            selectionSort(&ArrayWithTen);
            TimeForTen = (clock()-TimeForTen);

            selectionSort(&ArrayWithHundred);
            TimeForHundred = (clock()-TimeForHundred);

            selectionSort(&ArrayWithOneThousand);
            TimeForOneThousand = (clock()-TimeForOneThousand);

            selectionSort(&ArrayWithTenThousand);
            TimeForTenThousand = (clock()-TimeForTenThousand);

            break;
        case 'I':
            
            insertionSort(&ArrayWithTen);
            TimeForTen = (clock()-TimeForTen);

            insertionSort(&ArrayWithHundred);
            TimeForHundred = (clock()-TimeForHundred);

            insertionSort(&ArrayWithOneThousand);
            TimeForOneThousand = (clock()-TimeForOneThousand);

            insertionSort(&ArrayWithTenThousand);
            TimeForTenThousand = (clock()-TimeForTenThousand);

            break;
    }
    
    printf("@==========");
    printf("10");
    printf("===========");
    printf("100");
    printf("===========");
    printf("1000");
    printf("===========");
    printf("10000");
    printf("===========|\n");
    
    printf("||%c-Sort",option);
       printf("==");
    printf("\"%.0f ms\"",TimeForTen);
       printf("========");
    printf("\"%.0f ms\"",TimeForHundred);
       printf("========");
    printf("\"%.0f ms\"",TimeForHundred);
       printf("========");
    printf("\"%.0f ms\"",TimeForHundred);
    printf("========\n");
    printf("@====================================================================|\n\n");

    
   float TimeLineSearch = clock();
    line_search(&ArrayWithTenThousand,ArrayWithTenThousand.current_size);
    TimeLineSearch = (clock() - TimeLineSearch); // The time of performance the line search in ms
    printf("Time performance the line search: %.0f ms\n",TimeLineSearch);
    
    

    
    Print_To_File (ArrayWithTen.current_size,&ArrayWithTen);
    
    Print_To_File (ArrayWithHundred.current_size,&ArrayWithHundred);
    
    Print_To_File (ArrayWithOneThousand.current_size,&ArrayWithOneThousand);
    
    Print_To_File (ArrayWithTenThousand.current_size,&ArrayWithTenThousand);// Print Sorted array to file
    

    
    destroyArray(&ArrayWithTen);
   // destroyArray(&ArrayWithHundred);
    //destroyArray(&ArrayWithOneThousand);
    //destroyArray(&ArrayWithTenThousand);

    
    return 0;
}
