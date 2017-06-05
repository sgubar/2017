
//#include "TestSymmetricList.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

charNode *createCharNode(char aChar)
{
    charNode *theNode = (charNode *)malloc(sizeof(charNode));
    
    
    theNode->value = aChar;
    theNode->prev = NULL;
    theNode->next = NULL;
    
    
    return theNode;
}

void freeCharNode(charNode *theNode)
{
    if(NULL != theNode)
        {
            free(theNode); //destroy a node
        }
}
