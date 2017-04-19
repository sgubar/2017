//
// Created by Max on 18.04.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dk_tool.h"

int LengthOfUnsortedArray(char *name)
{
    FILE *file=fopen(name, "r");
    if(file!=NULL)
    {
        int aSmb;
        int Length=0;
        do
        {
            aSmb=fgetc(file);
            if(islower(aSmb)||isdigit(aSmb))
            {
                Length++;
            }
        }while(aSmb!=EOF);
        fclose(file);
        return Length;
    }
    else
    {
        printf("File don't open\n");
        return 0;
    }
}

char *FileToStr(void)
{
    int length=LengthOfUnsortedArray("File.txt");
    FILE *file=fopen("File.txt", "r");
    char *UnsortedArray=(char *)malloc(sizeof(char)*(length+1));
    int Smb;
    int i=0;
    do
    {
        Smb=fgetc(file);
        if(islower(Smb)||isdigit(Smb))
        {
            UnsortedArray[i]=(char)Smb;
            i++;

        }
    }while(Smb!=EOF);
    UnsortedArray[i]='\0';
    fclose(file);
    return UnsortedArray;
}

void PrintToFile(char *String)
{
    FILE *File=fopen("SortedFile.txt", "w");
    fputs(String, File);
    fclose(File);
}


