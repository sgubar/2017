#include <stdio.h>
#include "dk_tool.h"

void printfmassiv (int razmer, int massive[razmer])
{
    for(int i=0;i<razmer;i++)
    {
        printf("%i ", massive[i]);
    }
    printf("\n");
}

void zmeshchenie(int razmer, int massive[razmer], int newmassive[razmer])
{
/////////////////////////////////////zmeshchenie
    for(int j=0, k=razmer;j<razmer;j++)
    {
        newmassive[j]=massive[k-1];
        k--;

        
    }        

    
}
