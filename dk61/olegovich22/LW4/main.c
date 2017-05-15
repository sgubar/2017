#include <stdio.h>
#include "dk_tool.h"
#include "dk_checker.h"
#include <stdlib.h>

int main()
{
    //open file
    FILE *aFile=fopen(getNameOfFile(), "r");

    if(aFile==NULL)
    {
        printf("ERROR. Can't open or can't find this file\n");
        return 0;
    }

    //check file
    checkFile(aFile);

    // close file
    fclose (aFile);

    return 0;
}