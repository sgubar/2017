#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"

int dlinnateksta(char *name)
{
    FILE *file=fopen(name, "r");
    if(file!=NULL)
    {
        int simvol;
        int dlinna=0;
        do
        {
            simvol=fgetc(file);
            if(islower(simvol)||isdigit(simvol))
            {
                dlinna++;
            }
        }while(simvol!=EOF);
        fclose(file);
        return dlinna;
    }
    else
    {
        printf("file pust\n");
        return 0;
    }
}

char *FileToStr(void)
{
    int dlinna=dlinnateksta("File.txt");
    FILE *file=fopen("File.txt", "r");
    char *tekst=(char *)malloc(sizeof(char)*(dlinna+1));
    int simvol=0;
    int i=0;
    do
    {
        simvol=fgetc(file);
        if(islower(simvol)||isdigit(simvol))
        {
            tekst[i]=(char)simvol;
            i++;

        }
    }while(simvol!=EOF);
    tekst[i]='\0';
    fclose(file);
    return tekst; 
}

void bubbleSort(char tekst[], int dlinna)
{
	int theOut;
    for(theOut=dlinna-1; theOut>1; theOut--)
    {
    	int theIn;
        for(theIn=0; theIn<theOut; theIn++)
        {
            if (tekst[theIn]>tekst[theIn+1])
            {
                char theTmp=tekst[theIn];
                tekst[theIn]=tekst[theIn + 1];
                tekst[theIn+1]=theTmp;
            }
        }
    }
}

void selectionSort(char tekst[], int dlinna)
{
	int theOut;
    for(theOut=0; theOut<dlinna-1; theOut++)
    {
    	int theIn;
        int theMinIndex=theOut;
        for(theIn=theOut+1; theIn<dlinna; theIn++)
        {
            if(tekst[theIn]<tekst[theMinIndex])
            {
                theMinIndex=theIn;
            }
        }
        char theTmp=tekst[theOut];
        tekst[theOut]=tekst[theMinIndex];
        tekst[theMinIndex]=theTmp;
    }
}

void insertionSort(char tekst[], int dlinna)
{
	int theOut;
    for(theOut=1; theOut<dlinna; theOut++)
    {
        char theTmp=tekst[theOut];
        int theIn=theOut;
        while(theIn>0&&tekst[theIn-1]>=theTmp)
        {
            tekst[theIn]=tekst[theIn-1];
            --theIn;
        }
        tekst[theIn]=theTmp;
    }
}

void shellSort(char tekst[], int dlinna)
{
	int theIn = 0;
	int theOut = 0;
	int theH = 1; 
	
	
	while (theH <= dlinna/3)
	{
		theH = theH*3 + 1; 
	}

	while (theH > 0)
	{
		for (theOut = theH; theOut < dlinna; theOut ++)
		{
			int theTmp = tekst[theOut];
			theIn = theOut;
		
			while (theIn > theH-1 &&  tekst[theIn - theH] >= theTmp)
			{
				 tekst[theIn] =  tekst[theIn - theH];
				theIn =theIn - theH;
			}
		
			 tekst[theIn] = theTmp;
		}
	
		theH = (theH - 1) / 3; 
	}
}

int binarySearch(char *tekst, int dlinna, char search)
{
	int left = 0;
	int right = dlinna;
	int middle = 0;
	int result = 0;
	while(left < right)
	{
		middle = (left + right)/2;
		if(tekst[middle] == search)
		{
			result = middle;
			break;
		}
		else
		{
			if(tekst[middle] > search)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
	}
	return result;
}

void PrintToFile(char *String)
{
    FILE *File=fopen("Sorted.txt", "w");
    fputs(String, File);
    fclose(File);
}
