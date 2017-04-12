#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"

int main() {

    //get size from user
     int size=getSize();
     char* aName=getNameOfFile();
     if (NULL==aName)
     {
         printf("ERROR with enter the name. Try again\n");
         return 0;
     }

     //open file
     FILE *aFile=fopen(aName, "w+");
     //chek the file
     if (NULL==aFile)
     {
         printf("ERROR. Too little memory for file.\n");
         return 0;
     }

    //get random array
    int *anArray=getArray(size);

    arrayWithT anArrayWithTBub;
    arrayWithT anArrayWithTSelect;
    arrayWithT anArrayWithTInsert;
    arrayWithT anArrayWithTShell;
    arrayWithT anArrayWithTQuick;

    //make copy random array for every sorting
    anArrayWithTBub.anArray=makeArrayCopy(anArray, size);
    anArrayWithTSelect.anArray=makeArrayCopy(anArray, size);
    anArrayWithTInsert.anArray=makeArrayCopy(anArray, size);
    anArrayWithTShell.anArray=makeArrayCopy(anArray, size);
    anArrayWithTQuick.anArray=makeArrayCopy(anArray, size);

    printf("A 5 arrays have been created\n");

    //sorting arrays and get time of sorting
    anArrayWithTBub.time=bubbleSort(anArrayWithTBub.anArray, size);
    printf("An array has been sorted by bubbleSort for %lf seconds\n", anArrayWithTBub.time);

    anArrayWithTSelect.time=selectionSort(anArrayWithTSelect.anArray, size);
    printf("An array has been sorted by selectSort for %lf seconds\n", anArrayWithTSelect.time);

    anArrayWithTInsert.time=insertionSort(anArrayWithTInsert.anArray, size);
    printf("An array has been sorted by inserSort for %lf seconds\n", anArrayWithTInsert.time);

    anArrayWithTShell.time=shellSort(anArrayWithTShell.anArray, size);
    printf("An array has been sorted by shellSort for %lf seconds\n", anArrayWithTShell.time);

    anArrayWithTQuick.time=quickSort(anArrayWithTQuick.anArray, 0, size-1);
    printf("An array has been sorted by quickSort for %lf seconds\n", anArrayWithTQuick.time);

    //write all in the file
    writeIntoFile(aFile, size, anArray, &anArrayWithTBub, &anArrayWithTSelect, &anArrayWithTInsert, &anArrayWithTShell, &anArrayWithTQuick);

    //free memory
    destroyAllArrays(anArray, anArrayWithTBub.anArray, anArrayWithTSelect.anArray, anArrayWithTInsert.anArray, anArrayWithTShell.anArray, anArrayWithTQuick.anArray);

    //close our opened file
    fclose(aFile);

    printf("\nAn arrays have been sorted and have been written in file %s\n", aName);

    return 0;
}