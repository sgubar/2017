#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dk_tool.h"

charList *CreateList()
{
    charList *theList = (charList *)malloc(sizeof(charList));
    
    
    theList->left = NULL;
    theList->right = NULL;
    theList->count = 0;
    
    
    
    return theList;
}



charNode *NodeTolist(charList *inputList, charNode *NewNode)
{
    if (NULL == NewNode || NULL == inputList)
    {
        return NULL; //check valid
    }
    
    
    if(NULL == inputList->left && NULL == inputList->right)
    
        
    {
        inputList->left = inputList->right = NewNode;
    }else
        
        
    {
        NewNode->prev = inputList->right;
        inputList->right->next = NewNode;
        inputList->right = NewNode;
    }
    
    inputList->count++;
    
    
    return NewNode;
}

int Symmetrical (charList *inputList)

{
    charNode *currentLeftNode = inputList->left;
    charNode *currentRightNode = inputList->right;
    do
    {
        if(currentLeftNode->value == currentRightNode->value)
		{
            currentLeftNode = currentLeftNode->next;
            currentRightNode = currentRightNode->prev;
        }else
            {
                return 1;
            }
    }while(currentLeftNode != currentRightNode);
    
    return 0;
}




 int ListFile()
{
    FILE *fileslistom;
    
    
    char Data;
    
    
    charList *theList = CreateList();
    
    
    if((fileslistom = fopen("filelist.txt", "r")) == NULL)
    {
        printf("File not found!\n");
        return -1;
    }

      


    while((Data = fgetc(fileslistom)) != EOF)
    {
    	 if  ( Data == '\0'  )                    
  
		  {
		        
		 printf(" eeror");
		  return 0;
		  }
        charNode *nodeToAdd = createCharNode(Data);
        
        NodeTolist(theList, nodeToAdd);
    }
   
	
	 
    if(Symmetrical(theList) == 0) //0 is symmetrical
    {
        printf("Input string is symmetrical\n");
        
    }else
    {
        printf("Input string is not symmetrical\n");
    }
    

    
   
    
    
    fclose(fileslistom);
}
