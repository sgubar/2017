//
// Created by Oleg on 15.05.2017.
//

#include "dk_checker.h"
#include <stdlib.h>
#include <stdio.h>

//declaration
charNode *createCharNodeWithValue(char aCharValue);
char *readfile(FILE *aFile);

//create list
charList *createCharList()
{
    charList *aList=(charList *)malloc(sizeof(charList));

    if (aList!=NULL)
    {
        aList->count=0;

        aList->bracesLeft=0;
        aList->bracesRight=0;

        aList->bracketLeft=0;
        aList->bracketRight=0;

        aList->squareBracketsLeft=0;
        aList->squareBracketsRight=0;

        aList->head=NULL;
        aList->tail=NULL;
    }
    return aList;
}

//destroy list
void destroyCharList(charList *aList)
{
    if(aList==NULL)
    {
        return;
    }

    if(aList->tail!=NULL && aList->head!=NULL)
    {
        charNode *aNode=aList->head;

        while(aNode!=NULL)
        {
            charNode *aNodeToDelete=aNode;
            aNode=aNode->next;

            free(aNodeToDelete);
        }
    }

    free(aList);
}

//add int to end of list
int addCharValueToList(charList *aList, char aCharValue)
{
    int theResult=-1;

    if (aList!=NULL)
    {
        charNode *aNode=createCharNodeWithValue(aCharValue);

        if(aNode!=NULL)
        {
            if(aList->head==NULL && aList->tail==NULL)
            {
                aList->tail=aList->head=aNode;
            }
            else
            {
                // (head) a b c (tail) + d -> (head)a b c=>d (tail)
                charNode *aTail=aList->tail;
                aList->tail=aNode;
                aNode->prev=aTail;
                aTail->next=aNode;
            }

            aList->count++;
            theResult=0;
        }
    }

    return theResult;
}

// print list
void printList(charList *aList)
{
    if(aList==NULL || aList->count==0)
    {
        printf("Your List haven't elements\n");
        return;
    }

    //printf("LIST(%i elements):", aList->count);

    charNode *aNode=aList->head;
    int counter=0;

    while(counter<aList->count)
    {
        printf("%c\n", aNode->value);
        aNode=aNode->next;
        counter++;
    }
    printf("\n");

}

void checkFile(FILE *aFile)
{
    char *buffer=readfile(aFile);

    int i=0;

    charList *aList=createCharList();

    while(buffer[i]!='\0')
    {
        //check on comments
        if(buffer[i]=='/' && buffer[i+1]=='/')
        {
            while (buffer[i]!='\n')
            {
                if(buffer[i]==EOF)
                {
                    break;
                }
                i++;
            }
        }

        if(buffer[i]=='/' && buffer[i+1]=='*')
        {
            while (1)
            {
                i++;
                if((buffer[i]=='*' && buffer[i+1]=='/') || buffer[i+1]==EOF)
                {
                    break;
                }
            }
        }

        //main check
        switch (buffer[i])
        {
            case '{':

                addCharValueToList(aList, '{');
                aList->bracesLeft++;

                break;

            case '}':

                addCharValueToList(aList, '}');
                aList->bracesRight++;

                break;

            case '[':

                addCharValueToList(aList, '[');
                aList->squareBracketsLeft++;

                break;

            case ']':

                addCharValueToList(aList, ']');
                aList->squareBracketsRight++;

                break;

            case '(':

                addCharValueToList(aList, '(');
                aList->bracketLeft++;

                break;

            case ')':

                addCharValueToList(aList, ')');
                aList->bracketRight++;

                break;

            default:
                break;
        }

        i++;

    }

    printList(aList);

    printf("Count of brackets: %i\n", aList->count);

    if(aList->squareBracketsLeft!=aList->squareBracketsRight)
        printf("ERROR. Invalid square bracket balance. LeftBr:%i, RightBr:%i\n", aList->squareBracketsLeft, aList->squareBracketsRight);


    if(aList->bracketLeft!=aList->bracketRight)
        printf("ERROR. Invalid bracket balance. LeftBr:%i, RightBr:%i\n", aList->bracketLeft, aList->bracketRight);


    if(aList->bracesLeft!=aList->bracesRight)
        printf("ERROR. Invalid braces balance. LeftBr:%i, RightBr:%i\n", aList->bracesLeft, aList->bracesRight);

    if(aList->squareBracketsLeft==aList->squareBracketsRight && aList->bracketLeft==aList->bracketRight && aList->bracesLeft==aList->bracesRight)
        printf("All brackets are balanced\n");

    free (buffer);
    destroyCharList(aList);
}

//help function
charNode *createCharNodeWithValue(char aCharValue)
{
    charNode *aNode=(charNode *)malloc(sizeof(charNode));

    if (aNode!=NULL)
    {
        aNode->value=aCharValue;
        aNode->next=NULL;
        aNode->prev=NULL;
    }
    return aNode;
}

char *readfile(FILE *aFile)
{
    // count size of file
    fseek(aFile , 0 , SEEK_END);
    long lSize = ftell(aFile);
    rewind (aFile);

    char * buffer = (char*) malloc(sizeof(char) * lSize);
    if (buffer == NULL)
    {
        printf("ERROR. Your computer has problem with memory\n");
    }

    size_t check=fread(buffer, 1, (size_t)lSize, aFile);// считываем файл в буфер

    if(check==0)
    {
        printf("ERROR. File is epty or can't read\n");
    }
    return buffer;
}