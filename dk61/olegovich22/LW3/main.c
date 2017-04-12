#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"
#include "search.h"
#include <time.h>

int main() {

    //get size from user
    int size=getSize();

    //get name of file
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

    //make copy array
    int *anArrayForWork=makeArrayCopy(anArray, size);

    //get type of sorting
    int choice=getTypeOfSort();

    clock_t theStart = clock();
    if (choice==1)
    {
        shellSort(anArrayForWork, size);
    }
    else if(choice==2)
    {
        quickSort(anArrayForWork, 0, size-1);
    }
    clock_t theEnd = clock();

    //get time of sorting
    double timeSort = (double)(theEnd - theStart)/CLOCKS_PER_SEC;
    printf("An array has been sorted for %lf sec\n", timeSort);

    //get key
    int aKey=getKey();

    //get type of search
    choice=getTypeOfSearch();

    int searchPosition=0;
    clock_t theStart1 = clock();
    if (choice==1)
    {
        searchPosition=line_find(anArrayForWork, size, aKey);
    }
    else if(choice==2)
    {
        searchPosition=binary_find(anArrayForWork, size, aKey);
    }
    clock_t theEnd1 = clock();

    //get time of search
    double timeSearch = (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC;

    if(searchPosition==-1)
    {
        printf("An array has not been found your int\n");
    }
    else
    {
        printf("An array has been found int for %lf sec on %i position\n", timeSearch, searchPosition);
    }

    //write all in the file
    writeIntoFile(aFile, size, anArray, anArrayForWork, timeSort, searchPosition, timeSearch, aKey);
    printf("\nAll data have been written in file %s\n", aName);

    //free memory
    destroyAllArrays(anArray, anArrayForWork);

    //close our opened file
    fclose(aFile);

    return 0;
}