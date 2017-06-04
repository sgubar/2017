//
//  tree.c
//  HW7
//
//  Created by Maxim Salim on 04.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//


#include "tree.h"
#include <stdlib.h>

IntNode *createIntNodeWithValue(int aValue)
{
    IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
    
    if (NULL != theNode)
    {
        theNode->leftChild = NULL;
        theNode->rightChild = NULL;
        theNode->value = aValue;
    }
    
    return theNode;
}

void destroyNode(IntNode *aNode)
{
    if (NULL != aNode)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);
        
        free(aNode);
    }
}

intTree *createIntTree()
{
    intTree *theTree = (intTree *)malloc(sizeof(intTree));
    
    if (NULL != theTree)
    {
        theTree->root = NULL;
        theTree->count = 0;
    }
    
    return theTree;
}

void destroyIntTree(intTree *aTree)
{
    if (NULL != aTree)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

void insertIntValueToTree(intTree *aTree, int aValue)
{
    if (NULL == aTree)
    {
        return;
    }
    
    IntNode *theNode = createIntNodeWithValue(aValue);
    if (NULL == theNode)
    {
        return;
    }
    
    if (NULL == aTree->root)
    {
        aTree->root = theNode;
        aTree->count ++;
    }
    else
    {
        IntNode *theCurrent = aTree->root;
        IntNode *theParent = NULL;
        
        while (1)
        {
            theParent = theCurrent;
            
            if (aValue < theCurrent->value)
            {
                theCurrent = theCurrent->leftChild;
                if (NULL == theCurrent)
                {
                    theParent->leftChild = theNode;
                    break;
                }
            }
            else
            {
                theCurrent = theCurrent->rightChild;
                if (NULL == theCurrent)
                {
                    theParent->rightChild = theNode;
                    break;
                }
            }
        }
        
        aTree->count ++;
    }
}

void deleteNodeWithValue(intTree *aTree, int aValue)
{
    if(NULL == aTree)
    {
        return;
    }
    IntNode *theParentNode = NULL;
    IntNode *aNodeToDelete = aTree->root;
    while (aValue != aNodeToDelete->value)
    {
        theParentNode = aNodeToDelete;
        aNodeToDelete = (aValue < aNodeToDelete->value)
        
        ? aNodeToDelete->leftChild
        : aNodeToDelete->rightChild;
        
        if (NULL == aNodeToDelete)
        {
            printf("Error, don't find this node\n");
            return;
        }
    }
    
    if(aNodeToDelete->leftChild == NULL && aNodeToDelete->rightChild == NULL)
    {
        if(NULL != theParentNode)
        {
            free(aNodeToDelete);
            aTree->count--;
            printf("Deleted!\n");
            return;
        }
    }
    
    else if(NULL == aNodeToDelete->leftChild)
    {
        if(NULL != theParentNode)
        {
            if(aNodeToDelete->value < theParentNode->value)
            {
                theParentNode->leftChild = aNodeToDelete->rightChild;
            }
            else
            {
                theParentNode->rightChild = aNodeToDelete->rightChild;
            }
        }
        else
        {
            aTree->root = aNodeToDelete->rightChild;
        }
    }
    
    else if(NULL == aNodeToDelete->rightChild)
    {
        
        if(NULL != theParentNode)
        {
            if(aNodeToDelete->value < theParentNode->value)
            {
                theParentNode->leftChild = aNodeToDelete->leftChild;
            }
            else
            {
                theParentNode->rightChild = aNodeToDelete->leftChild;
            }
            
        }
        else
        {
            aTree->root = aNodeToDelete->leftChild;
        }
    }
    
    else
    {
        IntNode *ParentOfReceiver = NULL;
        IntNode *Receiver = aNodeToDelete->rightChild;
        if(Receiver->leftChild == NULL && Receiver->rightChild == NULL)
        {
            if(NULL != theParentNode)
            {
                if(aNodeToDelete->value < theParentNode->value)
                {
                    theParentNode->leftChild = Receiver;
                }
                else
                {
                    theParentNode->rightChild = Receiver;
                }
                
            }
            else
            {
                aTree->root = Receiver;
            }
            Receiver->leftChild = aNodeToDelete->leftChild;
        }
        else
        {
            if(Receiver->leftChild == NULL)
            {
                if(NULL != theParentNode)
                {
                    theParentNode->rightChild = Receiver;
                }
                else
                {
                    aTree->root = Receiver;
                }
                Receiver->leftChild = aNodeToDelete->leftChild;
            }
            
            else
            {
                while(Receiver->leftChild != NULL)
                {
                    ParentOfReceiver = Receiver;
                    Receiver = Receiver->leftChild;
                }
                if(Receiver->rightChild != NULL)
                {
                    ParentOfReceiver->leftChild = Receiver->rightChild;
                }
                else
                {
                    ParentOfReceiver->leftChild = NULL;
                }
                if(NULL != theParentNode)
                {
                    theParentNode->rightChild = Receiver;
                }
                else
                {
                    aTree->root = Receiver;
                }
                Receiver->leftChild = aNodeToDelete->leftChild;
                Receiver->rightChild = aNodeToDelete->rightChild;
            }
        }														
    }
    
    free(aNodeToDelete);	
    aTree->count--;
    printf("Deleted!\n");
}

int countNodesWithTree(intTree *aTree)
{
    if (NULL != aTree)
    {
        return aTree->count;
    }
    return 0;
}

void printTree(intTree *aTree)
{
    if(NULL == aTree->root)
    {
        return;
    }
    plainPrintNode(aTree->root);
}


void plainPrintNode(IntNode *aNode)
{
    if(NULL != aNode)
    {
        printf("%d\n",aNode->value);
        plainPrintNode(aNode->leftChild);
        plainPrintNode(aNode->rightChild);
    }
}


