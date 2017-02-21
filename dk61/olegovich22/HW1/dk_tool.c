//
// Created by Олег on 19.02.2017.
//
#include <stdio.h>
#include "dk_tool.h"

void getText(int maxText, char text[] )
{

    printf("Write text(max %d symbols with space, min 2 symbols)\n", maxText-2);
    do
    {
        gets(text);
        if (lenght(text)>=maxText-1 || lenght(text)<2)
        {
            printf("ERROR. Invalid input. Write text(max %d symbols with space, min 2 symbols)\n", maxText-2);
        }
    }
    while (lenght(text)>=maxText-1 || lenght(text)<2);
    printf("\nYour Text\n%s\n\n", text);
}


void getWord(int maxWord, char searchWord[])
{
    printf("Write search word(max %d symbols with space min 2 symbols) without space\n", maxWord-2);
    do
    {
        gets(searchWord);

        if (lenght(searchWord)>=maxWord-1 || lenght(searchWord)<2 || savefromspace(searchWord)==1)
        {
            printf("ERROR. Invalid input. Write search word(max %d symbols with space min 2 symbols) without space\n", maxWord-2);
        }
    }
    while (lenght(searchWord)>=maxWord-1 || lenght(searchWord)<2 || savefromspace(searchWord)==1);
    printf("\nYour Search Word is: %s\n\n", searchWord);
}

int savefromspace(char Sword[])
{
    int theResult = 0;
    int i=0;

    while (NULL != Sword &&  '\0' != *(Sword + theResult))
    {
        if((int)Sword[theResult]==32)
        {
            i++;
        }

        theResult ++;
    }
    if (i>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int lenght(char word[])
{
    int theResult = 0;

    while (NULL != word &&  '\0' != *(word + theResult))
    {
        theResult ++;
    }

    return theResult;
}

int countWord(char searchWord[], char text[])
{
    int numb = 0;
    int kilkbukv = lenght(searchWord);
    int i=0;
    int congratulate=0;

    while (NULL != text &&  '\0' != *(text + numb))
    {
        if (searchWord[i]==text[numb] && i<kilkbukv && (int)text[numb]!=32)
        {
            if(searchWord[i+1]==text[numb+1])
            {
                i++;
            }
            else
            {
                i=0;
            }
            numb++;

            if (kilkbukv-1==i)
            {
                congratulate++;
                i=0;
            }
        }
        else
        {
            numb++;
        }
    }

    return congratulate;
}