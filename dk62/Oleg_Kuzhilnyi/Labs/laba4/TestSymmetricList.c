#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "TestSymmetricList.h"
#include "TestSymmetricNode.h"

charList *CreateCharList()
{
    charList *TheList = (charList *)malloc(sizeof(charList));
    
    
    TheList->left = NULL;
    TheList->right = NULL;
    TheList->count = 0;
    
    
    return TheList;
}

void DestroyCharList(charList *theListForFree)
{
    if(NULL == theListForFree)
    {
        
        return;
        
    }
    charNode *currentNode = theListForFree->left;
    
    while(NULL != currentNode)
    {
        charNode *tempNodeForDelete = currentNode;
        currentNode = currentNode->next;
        free(tempNodeForDelete);
    }
    
    free(theListForFree); //destroy the list
}

charNode *InsertNodeTolist(charList *inputList, charNode *TheNewNode)
{
    if (NULL == TheNewNode || NULL == inputList)
    {
        return NULL; //check valid
    }
    
    
    if(NULL == inputList->left && NULL == inputList->right)
    
        
    {
        inputList->left = inputList->right = TheNewNode;
    }else
        
        
    {
        TheNewNode->prev = inputList->right;
        inputList->right->next = TheNewNode;
        inputList->right = TheNewNode;
    }
    
    inputList->count++;
    
    
    return TheNewNode;
}

int NodeCompare_FindSymmetric (charList *inputList)

{
    charNode *currentLeftNode = inputList->left;
    charNode *currentRightNode = inputList->right;
    do
    {
        if(currentLeftNode->value == currentRightNode->value){
            currentLeftNode = currentLeftNode->next;
            currentRightNode = currentRightNode->prev;
        }else
            {
                return 1;
            }
    }while(currentLeftNode != currentRightNode);
    
    return 0;
}


void printCharList(const charList *inputList)
{
    charNode *theNode = inputList->left;
    
    printf("The char List: ");
    
    while (NULL != theNode)
    {
        printf("(%c) ",theNode->value);
        theNode = theNode->next;
    }
}

 void ListWork()
{
    FILE *inputFile;
    
    
    char Data;
    
    
    charList *theList = CreateCharList();
    
    
    if((inputFile = fopen("/Users/air/Documents/Programming_C/Labs/Lab4/Lab4/inputs.txt", "r")) == NULL)
    {
        printf("File not found!\n");
        exit(1);
    }
    
    while((Data = fgetc(inputFile)) != EOF)
    {
        charNode *nodeToAdd = createCharNode(Data);
        
        InsertNodeTolist(theList, nodeToAdd);
    }
    
    if(NodeCompare_FindSymmetric(theList) == 0) //0 is symmetrical
    {
        printf("Input string is symmetrical\n");
        
    }else
    {
        printf("Input string is not symmetrical\n");
    }
    
    printCharList(theList);
    
    DestroyCharList(theList);
    
    
    fflush(inputFile);
    fclose(inputFile);
}

