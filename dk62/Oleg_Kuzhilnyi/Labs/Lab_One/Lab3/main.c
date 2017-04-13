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
    
    
    theDescriptionArray *ArrayWithHundred = createArray(HUNDRED);
    theDescriptionArray *ArrayWithThousand = createArray(ONE_THOUSAND);
    theDescriptionArray *ArrayWithTenThousands = createArray(TEN_THOUSAND);
    theDescriptionArray *ArrayWithTwentyThousands = createArray(TWENTY_THOUSAND);

    FillingInTypeOfArrays(ArrayWithTwentyThousands);
    Print_To_File (ArrayWithTwentyThousands,ArrayWithTwentyThousands->maxSize);
    
    TheSorts_For_DifferentArrays( ArrayWithHundred, ArrayWithThousand,ArrayWithTenThousands ,ArrayWithTwentyThousands);
    
    float aTime = clock();
    
    line_search(ArrayWithTwentyThousands,ArrayWithTwentyThousands->current_size);
    float TheTimeResultForLineSearch = TheResultOfTimePoint(aTime); // The time of performance the line search in ms
    
    printf("Time performance the line search: %.0f ms\n",TheTimeResultForLineSearch);
    
    
    /*
    Print_To_File (ArrayWithHundred,ArrayWithHundred->maxSize);
    
        Print_To_File (ArrayWithThousand,ArrayWithThousand->maxSize);
    
            Print_To_File (ArrayWithTenThousands,ArrayWithTenThousands->maxSize);
    
                Print_To_File (ArrayWithTwentyThousands,ArrayWithTwentyThousands->maxSize);// Print Sorted array to file
    */
    
    destroyArray(ArrayWithHundred);
    destroyArray(ArrayWithThousand);
    destroyArray(ArrayWithTenThousands);
    destroyArray(ArrayWithTwentyThousands);

    
    return 0;
}
