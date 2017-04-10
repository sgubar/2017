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

theDescriptionArray createArray(unsigned aSize )
{
    theDescriptionArray *theArrays = (theDescriptionArray *)malloc(sizeof(theDescriptionArray));
    
    if(NULL != theArrays)
    {
        theArrays->current_size = 0;
        theArrays->maxSize = aSize;
        theArrays->value = (int*)malloc(sizeof(int)*aSize);
        
        bzero(theArrays->value, aSize);
        
    }
    return *theArrays;
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

void Print_To_File (int aSize,theDescriptionArray *MassOfNumbers){

  //  FILE *FileWithoutArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","w");
    FILE *FileWithArray = fopen("/Users/air/Documents/Programming_C/Lab2/Lab2/AfterSort.txt","w+a");
    
    fprintf(FileWithArray,"\n---------------------------------Array with %i Symbols--------------------------------------------\n",aSize);


    int i = 0;
    while(i < aSize){
        
        fprintf(FileWithArray,"%i",MassOfNumbers->value[i]);
        fprintf(FileWithArray," ");
        i++;
        
    }
    
   
    fflush(FileWithArray);
    fclose(FileWithArray);
}

//int FillingInArray(int theSize,void Function(theDescriptionArray* Air))


/*
 void printArray(theDescriptionArray *theArray)
 {
 printf ("\n{");
 
 for (int i = 0; i < theArray->current_size; i ++)
 {
 printf ("%d", theArray->value[i]);
 if (i < theArray->current_size - 1)
 {
 printf (",");
 }
 }
 
 printf ("}\n");
 }
 */

/*

*/
/*
 int intRandom(int min, int max)
 {
 srand(0);
 return rand() % (max-min+1) + min;
 }
 */


/*
void Input(FILE *aFileWrite,int *MassOfNumbers,int aSize)
{
    
    for(int i = 0; i < aSize; i++)
    {
        if(isdigit(MassOfNumbers[i]))
        fprintf(FileWithArray,"%i",MassOfNumbers[i]);
        
    }

    fflush(aFileWrite);
    fclose(aFileWrite);
}
 */
