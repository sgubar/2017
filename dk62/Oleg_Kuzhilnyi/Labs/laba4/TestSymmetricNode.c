
//#include "TestSymmetricList.h"
#include "TestSymmetricNode.h"
#include <stdio.h>
#include <stdlib.h>


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
