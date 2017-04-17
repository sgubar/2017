//
//  Random.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

theDescriptionArray *createArray(unsigned aSize)
{
    theDescriptionArray *theArrays = (theDescriptionArray *)malloc(sizeof(theDescriptionArray));
    
    if(NULL != theArrays)
    {
        theArrays->current_size = 0;
        theArrays->maxSize = aSize;
        theArrays->value = (int*)malloc(sizeof(int)*aSize);
        
        bzero(theArrays->value, aSize);
        
    }
    return theArrays;
}

unsigned input_in_ArrayNewElement(theDescriptionArray *theArray , int aValue)

{
    unsigned theResult = theArray->current_size;
    
    if(theArray->current_size == theArray->maxSize)
    {
        return theResult;
    }

    theArray->value[theArray->current_size] = aValue;
    theArray->current_size ++;
    
    return theResult;
}

void FillingInTypeOfArrays(theDescriptionArray *iArray)
{
    srand( (unsigned)time( NULL ) );
    
    for(int i = 0 ; i < iArray->maxSize; i++)
        input_in_ArrayNewElement(iArray , rrand(ZERO,ONE_THOUSAND));
}

float TheResultOfTimePoint(float aTime)
{
    aTime = clock() - aTime ; // time at this moment
    return aTime;
}


int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;
}

void destroyArray(theDescriptionArray *iArray)
{
    while (NULL == iArray)
    {
        if (NULL != iArray->value)
        {
            free(iArray->value);
        }
        
        free(iArray);
    }
}

void Print_To_File (theDescriptionArray *ArrayOfNumbers,unsigned aSize)
{
    
    //  FILE *FileWithoutArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","w");
    FILE *FileWithArray = fopen("AfterSort.txt","a");
    
    fprintf(FileWithArray,"\n----------------------------------------------------------------------------------");
    fprintf(FileWithArray,"Array with %i Symbols",aSize);
    fprintf(FileWithArray,"----------------------------------------------------------------------------------\n");
    
    int SEEK = 0;
    while(SEEK < aSize){
        
        fprintf(FileWithArray,"%i",ArrayOfNumbers->value[SEEK]);
        fprintf(FileWithArray," ");
        SEEK++;
        
    }
    
    fflush(FileWithArray);
    fclose(FileWithArray);
}
