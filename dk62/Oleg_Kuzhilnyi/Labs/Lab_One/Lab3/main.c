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
    theDescriptionArray *SmallArray = createArray(HUNDRED);
    theDescriptionArray *MediumArray = createArray(ONE_THOUSAND);
    theDescriptionArray *BigArray = createArray(TEN_THOUSAND);
    theDescriptionArray *theBiggestArray = createArray(TWENTY_THOUSAND);

    TheArrayList *TimeTable = TheSorting_Of_a_FourArrays(SmallArray,MediumArray,BigArray,theBiggestArray);
    
    PrintTheResultTable(TimeTable);

    float aTime = clock();
    line_search(theBiggestArray,theBiggestArray->current_size);
    float TheTimeResultForLineSearch = TheResultOfTimePoint(aTime); // The time of performance the line search in ms
    
    printf("Time performance the line search: %.0f ms\n",TheTimeResultForLineSearch);
    
     Print_To_File (SmallArray,SmallArray->maxSize);
     Print_To_File (MediumArray,MediumArray->maxSize);
     Print_To_File (BigArray,BigArray->maxSize);
     Print_To_File (theBiggestArray,theBiggestArray->maxSize);// Print Sorted array with last type of Sort to file
    
    
    destroyArray(SmallArray);
    destroyArray(MediumArray);
    destroyArray(BigArray);
    destroyArray(theBiggestArray);
    
    
    return 0;
}
