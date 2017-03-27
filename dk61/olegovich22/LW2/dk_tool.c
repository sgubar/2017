
#include <stdlib.h>
#include <stdio.h>
#include "dk_tool.h"

//get size from user
int getSize()
{
    int size=0;
    printf("Please enter size of array from 2 to 30000\n");
    do
    {
        int aChek=scanf("%d", &size);
        rewind(stdin); //clear buffer in scanf
        if (size<2 || size>30000 || aChek!=1)
            printf("ERROR. Please enter size of array from 2 to 30000\n");
    }
    while(size<2 || size>30000);

    return size;
}

//get random array
int *getArray(int size)
{
    int *anArray=malloc(size*sizeof(int));

    if (NULL==anArray)
    {
        printf("ERROR. Too little memory for array.\n");
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        *(anArray+i)=rand()%10000;
    }
    return anArray;
}

//make copy of array
int *makeArrayCopy(int *anArray, int size)
{
    int *arrayCopy=malloc(size*sizeof(int));

    if (NULL==arrayCopy)
    {
        printf("ERROR. Too little memory for make a copy.\n");
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        *(arrayCopy+i)=*(anArray+i);
    }
    return arrayCopy;
}

//write all in the file
void writeIntoFile(FILE *aFile, int size, int *anArray1, int *anArray2, int *anArray3, double *timeBubbleSort, double *timeSelectionSort, double *timeInsertSort)
{
    fprintf(aFile, ";BubbleSort;;SelectionSort;;InsertSort\n");
    fprintf(aFile, "Time(s);%.10lf;;%.10lf;;%.10f\n", *timeBubbleSort, *timeSelectionSort, *timeInsertSort);

    int m=0;
    while(m<size)
    {
        fprintf(aFile, ";%d;;%d;;%d\n", *(anArray1+m), *(anArray2+m), *(anArray3+m));
        m++;
    }
}

//free memory
void destroyAllArrays(int *anArray1, int *anArray2, int *anArray3)
{
    free(anArray1);
    free(anArray2);
    free(anArray3);
}
