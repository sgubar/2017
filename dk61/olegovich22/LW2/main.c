#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include "sort.h"

int main() {

    //open file
    FILE *aFile=fopen("sortedTable.csv", "w+");
    //chek the file
    if (NULL==aFile)
    {
        printf("ERROR. Too little memory for file.\n");
        return 0;
    }

    //get size from user
    int size=getSize();

    //get random array
    int *anArray1=getArray(size);

    //make copy random array for every sorting
    int *anArray2=makeArrayCopy(anArray1, size);
    int *anArray3=makeArrayCopy(anArray1, size);

    //sorting arrays and get time of sorting
    double timeBubbleSort=bubbleSort(anArray1, size);
    double timeSelectionSort=selectionSort(anArray2, size);
    double timeInsertSort=insertionSort(anArray3, size);

    //write all in the file
    writeIntoFile(aFile, size, anArray1, anArray2, anArray3, &timeBubbleSort, &timeSelectionSort, &timeInsertSort);

    //free memory
    destroyAllArrays(anArray1, anArray2, anArray3);

    //close our opened file
    fclose(aFile);

    printf("\nAn arrays have been sorted and have been written in file sortedTable.csv\n");

    return 0;
}