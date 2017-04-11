//
//  Random.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"
#include <stdlib.h>
#include <string.h>
#include <memory.h>

theDescriptionArray *createArray(unsigned aSize )
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

unsigned input_in_Array(theDescriptionArray *theArray , int aValue)

{
    unsigned theResult = theArray->current_size;
    int i = 0;
    
    if(theArray->current_size == theArray->maxSize)
    {
        return theResult;
        
    }
    
    for(;i < theArray->current_size;i++)
    {
        
        if(theArray->value[i] > aValue)
        {
            theResult = i;
            break;
        }
    }
        for(int j = theArray->current_size; j > i; j --)
        {
            theArray->value[j] = theArray->value[j-1];
            
        }
        
        theArray->value[i] = aValue;
        theArray->current_size ++;
        
        return theResult;
    }

void destroyArray(theDescriptionArray *iArray)
{
    if (NULL != iArray)
    {
        if (NULL != iArray->value)
        {
           free(iArray->value);
        }
        
        free(iArray);
    }
}

void Print_To_File (unsigned aSize,theDescriptionArray *MassOfNumbers)
{
    
  //  FILE *FileWithoutArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","w");
    FILE *FileWithArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","a");
    
    fprintf(FileWithArray,"\n---------------------------------------------------------Array with %i Symbols----------------------------------------------------------------\n",aSize);

    int i = 0;
    while(i < aSize){
        
        fprintf(FileWithArray,"%i",MassOfNumbers->value[i]);
        fprintf(FileWithArray," ");
        i++;
        
    }
    
    fflush(FileWithArray);
    fclose(FileWithArray);
}


float TheResultOfTimePoint(float aTime)
{
         aTime = clock() - aTime ; // time at this moment
    return aTime;
}

void FillingInTypeOfArrays(theDescriptionArray *SmallArray, theDescriptionArray *MediumArray, theDescriptionArray *theBigArray , theDescriptionArray *TheBiggestArray)
{
    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < HUNDRED; i++)
        input_in_Array(SmallArray , (unsigned)random() %HUNDRED);
    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < ONE_THOUSAND; i++)
        input_in_Array(MediumArray , (unsigned)random() %ONE_THOUSAND);
    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < TEN_THOUSAND; i++)
        input_in_Array(theBigArray , (unsigned)random() %TEN_THOUSAND);
    
    srand( (unsigned)time( NULL ) );
    for(int i = 0 ; i < TWENTY_THOUSAND; i++)
        input_in_Array(TheBiggestArray , (unsigned)random() %TWENTY_THOUSAND);
    
}
