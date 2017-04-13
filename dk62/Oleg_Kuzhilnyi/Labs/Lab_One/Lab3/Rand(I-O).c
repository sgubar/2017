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

unsigned input_in_Array(theDescriptionArray *theArray , int aValue)

{
    int i = 0;
    
    unsigned theResult = theArray->current_size;
    
    
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

float TheResultOfTimePoint(float aTime)
{
         aTime = clock() - aTime ; // time at this moment
    return aTime;
}

void FillingInTypeOfArrays(theDescriptionArray *iArray)
{
    srand( (unsigned)time( NULL ) );
    
    for(int i = 0 ; i < iArray->maxSize; i++)
        input_in_Array(iArray , (unsigned)random() %(iArray->maxSize));
}

void Print_To_File (theDescriptionArray *ArrayOfNumbers,unsigned aSize)
{
    
    //  FILE *FileWithoutArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","w");
    FILE *FileWithArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","a");
    
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
