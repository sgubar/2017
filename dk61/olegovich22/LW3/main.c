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
    printf("Please choose type of sort. Or 1, or 2\n");
    printf("1 - shellSort\n");
    printf("2 - quickSort\n");
    int choice=get1or2();

    clock_t theStart = clock();
    if (choice==1)
    {
        printf("Sorting.... Wait\n");
        shellSort(anArrayForWork, size);
    }
    else if(choice==2)
    {
        printf("Sorting.... Wait\n");
        quickSort(anArrayForWork, 0, size-1);
    }
    clock_t theEnd = clock();

    //get time of sorting
    double timeSort = (double)(theEnd - theStart)/CLOCKS_PER_SEC;
    printf("An array has been sorted for %lf sec\n", timeSort);

    //get numb which user want to find
    int aKey=getKey();

    //get type of search
    printf("Please choose type of search. Or 1, or 2\n");
    printf("1 - line search\n");
    printf("2 - binary search\n");
    choice=get1or2();

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

    printSearchResult(&timeSearch, searchPosition);

    //write all in the file
    printf("\nWriting in the file..... Wait please\n");
    writeIntoFile(aFile, size, anArray, anArrayForWork, timeSort, searchPosition, timeSearch, aKey);
    printf("All data have been written in file %s\n", aName);

    //free memory
    destroyAllArrays(anArray, anArrayForWork);

    //close our opened file
    fclose(aFile);

    return 0;
}