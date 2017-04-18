
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dk_tool.h"


//get information from user
int getSize()
{
    int size=0;
    printf("Please enter size of array from 2 to 100 000 000\n");
    do
    {
        int aChek=scanf("%d", &size);
        rewind(stdin); //clear buffer in scanf
        if (size<2 || size>100000000 || aChek!=1)
            printf("ERROR. Please enter size of array from 2 to 100000000\n");
    }
    while(size<2 || size>100000000);

    return size;
}

char* getString()
{
    // growable buffer for chars
    char* buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {

        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            char* temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;

    // minimize buffer
    char* minimal = malloc((n + 5) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);



    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}

char *getNameOfFile()
{
    printf("Please enter name of file where will have written array. Name can't be only space and more than 20 letters.\n");
    char *aName;
    int findPoint=0;
    do
    {
        aName=getString();

        for (int i = 0; i < strlen(aName); ++i) {
            if ((int)aName[i]==46)
            {
                findPoint++;
            }
        }

        if(0==strlen(aName))
        {
            printf("ERROR. Name of file can't be empty!\n");
        }
        else if(strlen(aName)>20)
        {
            printf("ERROR. Name of file can't be more than 20 letters! But your %i letters\n", strlen(aName));
        }
        else if((int)aName[0]==32)
        {
            printf("ERROR. Name of file can't begin with space.\n");
        }
        else if(findPoint!=0)
        {
            printf("ERROR. Name of file can't has point.\n");
        }
        fflush(stdin);
    }
    while (0==strlen(aName) || strlen(aName)>20 || (int)aName[0]==32 || findPoint!=0);
    char *csv=".csv";
    strcat(aName, csv);

    return aName;
}

//get random array
int *getArray(int size)
{
    int *anArray=malloc(size*sizeof(int));
    memset(anArray, 0, size*sizeof(int));
    if (NULL==anArray)
    {
        printf("ERROR. Too little memory for array.\n");
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        *(anArray+i)=rand()%10001;
    }
    return anArray;
}

//make copy of array
int *makeArrayCopy(int *anArray, int size)
{
    int *arrayCopy=malloc(size*sizeof(int));
    memset(arrayCopy, 0, size*sizeof(int));

    if (NULL==arrayCopy)
    {
        printf("ERROR. Too little memory for make a copy.\n");
        return 0;
    }

    for (int i = 0; i < size; ++i)
    {
        *(arrayCopy+i)=*(anArray+i);
    }
    return arrayCopy;
}

//write all in the file
void writeIntoFile(FILE *aFile, int size, int *anArray, int *anArrayForWork, double timeSort, int searchPosition, double timeSearch, int aKey)
{
    //search data
    fprintf(aFile, "Search data\n");
    fprintf(aFile, "Key;%i\n", aKey);
    fprintf(aFile, "Time search;%.10lf\n", timeSearch);
    if(searchPosition==-1)
    {
        fprintf(aFile, "Position;NOT Found\n");
    }
    else
    {
        fprintf(aFile, "Position;%i\n", searchPosition);
    }

    //sort data
    fprintf(aFile, "\n");
    fprintf(aFile, "Sort data\n");
    fprintf(aFile, ";Index;Not sorted array;;Sorted array\n");
    fprintf(aFile, "Time of Sorting(s);;;;%.10lf\n", timeSort);

    int m=0;
    while(m<size)
    {
        fprintf(aFile, ";%i;%d;;%d\n", m, *(anArray+m), *(anArrayForWork+m));
        m++;
    }
}

//free memory
void destroyAllArrays(int *anArray1, int *anArray2)
{
    free(anArray1);
    free(anArray2);
}

int get1or2()
{
    int Choice=0;
    int repair=0;
    do
    {
        repair=scanf("%i", &Choice);
        if (Choice>2 || Choice<1 || repair!=1)
        {
            printf("ERROR. Please make choice or 1 or 2\n");
        }
        fflush(stdin);
    }while(Choice>2 || Choice<1 || repair!=1);

    return Choice;
}