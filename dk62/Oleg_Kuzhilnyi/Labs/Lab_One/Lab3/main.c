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
    
    
    theDescriptionArray *ArrayWithHundred = createArray(100);
    theDescriptionArray *ArrayWithThousand = createArray(1000);
    theDescriptionArray *ArrayWithTenThousands = createArray(10000);
    theDescriptionArray *ArrayWithTwentyThousands = createArray(20000);
    
    FillingInTypeOfArrays( ArrayWithHundred, ArrayWithThousand,ArrayWithTenThousands ,ArrayWithTwentyThousands);    
    TheSorts_For_DifferentArrays( ArrayWithHundred, ArrayWithThousand,ArrayWithTenThousands ,ArrayWithTwentyThousands);
    
    
    PrintfTheResultTable();
    
    
    float aTime = clock();
    
    line_search(ArrayWithTwentyThousands,ArrayWithTwentyThousands->current_size);
    float TheTimeResultForLineSearch = TheResultOfTimePoint(aTime); // The time of performance the line search in ms
    
    printf("Time performance the line search: %.0f ms\n",TheTimeResultForLineSearch);
    
    
    Print_To_File (ArrayWithHundred->current_size,ArrayWithHundred);
    
        Print_To_File (ArrayWithThousand->current_size,ArrayWithThousand);
    
            Print_To_File (ArrayWithTenThousands->current_size,ArrayWithTenThousands);
    
                Print_To_File (ArrayWithTwentyThousands->current_size,ArrayWithTwentyThousands);// Print Sorted array to file
    
    
    destroyArray(ArrayWithHundred);
    destroyArray(ArrayWithThousand);
    destroyArray(ArrayWithTenThousands);
    destroyArray(ArrayWithTwentyThousands);

    
    return 0;
}
