//
// Created by Oleg on 08.05.2017.
//

#include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

char* getString();

char *getNameOfFile()
{
    printf("Please enter name of file witch will be checking.\n");
    char *aName;

    do
    {
        aName=getString();

        if(0==strlen(aName))
        {
            printf("ERROR. Name of file can't be empty!\n");
        }
        else if(strlen(aName)>INT_MAX)
        {
            printf("ERROR. Name of file can't be more than %i letters!\n", INT_MAX);
        }
        else if((int)aName[0]==32)
        {
            printf("ERROR. Name of file can't begin with space.\n");
        }

        fflush(stdin);
    }
    while (0==strlen(aName) || strlen(aName)>INT_MAX || (int)aName[0]==32);

    return aName;
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