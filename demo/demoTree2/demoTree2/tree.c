//
//  tree.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>

static void destroyNode(Double_Node *aNode);
static Double_Node *createDoubleNodeWithValue(double aValue);

DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	Double_Node *theNode = createDoubleNodeWithValue(aValue);
    
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
		Double_Node *theCurrent = aTree->root;
		Double_Node *theParent = NULL;

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

Double_Node *findNodeWithValue(DoubleTree *aTree, double aValue)
{
    Double_Node *theCurrentNode = NULL; ///< - start from root
	
	if (NULL != aTree)
	{
		Double_Node *theCurrentNode = aTree->root; ///< - start from root
		while (aValue != theCurrentNode->value) ///< - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
    }
	
	return theCurrentNode;
}
/*
void deleteNodeWithValue(DoubleTree *aTree, double aValue)
{
    Double_Node *theCurrentNode = NULL;
    Double_Node *theParentNode = NULL;


        if(NULL != aTree)
        {
            Double_Node *theParentNode = aTree->root;
            Double_Node *theCurrentNode = aTree->root;
            while(aValue != theCurrentNode->value)
            {
                
                theParentNode = theCurrentNode;

                theCurrentNode = (aValue < theCurrentNode->value)
                ? theCurrentNode->leftChild
                : theCurrentNode->rightChild;
                
                
                
                if(NULL == theCurrentNode)
                    return ;
                
            }
            
        }
    
    //if the node does not have children then just remove it
    if(NULL == theCurrentNode->leftChild && NULL == theCurrentNode->rightChild)
    {
        if(NULL != theParentNode)
        {
            if(theCurrentNode->value < theParentNode->value)
            {
                theParentNode->leftChild = NULL;
            }
            if(theCurrentNode->value > theParentNode->value)
            {
                theParentNode->rightChild = NULL;
            }
        }
    }
    else
    {
        if(NULL == theCurrentNode->leftChild)
        {
            if(NULL != theParentNode)
            {
                if(theCurrentNode->value < theParentNode->value)
                {
                    theParentNode->leftChild = theCurrentNode->rightChild;
                }
                if(theCurrentNode->value > theParentNode->value)
                {
                    theParentNode->rightChild = theCurrentNode->rightChild;
                }
            }
            else
                aTree->root = theCurrentNode->rightChild;
        }
        else
        {
            if(NULL == theCurrentNode->rightChild)
            {
                if(NULL != theParentNode)
                {
                    if(theCurrentNode->value < theParentNode->value)
                    {
                        theParentNode->leftChild = theCurrentNode->leftChild;
                    }
                    if(theCurrentNode->value > theParentNode->value)
                    {
                        theParentNode->rightChild = theCurrentNode->leftChild;
                    }
                }
                else
                    aTree->root = theCurrentNode->leftChild;
            }
            
            else
            {
                Double_Node *ParentOfReceiver = NULL;
                Double_Node *Receiver = theCurrentNode->rightChild;
                if(Receiver->leftChild == NULL && Receiver->rightChild == NULL)
                {
                    if(NULL != theParentNode)
                    {
                        if(theCurrentNode->value < theParentNode->value)
                        {
                            theParentNode->leftChild = Receiver;
                        }
                        if(theCurrentNode->value > theParentNode->value)
                        {
                            theParentNode->rightChild = Receiver;
                        }
                    }
                    else
                        aTree->root = Receiver;
                    Receiver->leftChild = theCurrentNode->leftChild;
                }
                else
                {
                    if(Receiver->leftChild == NULL)
                    {
                        if(NULL != theParentNode)					
                            theParentNode->rightChild = Receiver;					
                        else					
                            aTree->root = Receiver;								
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
                            ParentOfReceiver->leftChild = Receiver->rightChild;	
                        else
                            ParentOfReceiver->leftChild = NULL;
                        if(NULL != theParentNode)					
                            theParentNode->rightChild = Receiver;					
                        else					
                            aTree->root = Receiver;								
                        Receiver->leftChild = aNodeToDelete->leftChild;		
                        Receiver->rightChild = aNodeToDelete->rightChild;
                    }
                }														
            }
        }		
    }

    
    
}
*/
void mergeTrees(DoubleTree *aTreeDst, DoubleTree *aTreeSrc);

void printTree(DoubleTree *aTree);
int countNodesWithTree(DoubleTree *aTree);

#pragma mark -
void destroyNode(Double_Node *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

Double_Node *createDoubleNodeWithValue(double aValue)
{
	Double_Node *theNode = (Double_Node *)malloc(sizeof(Double_Node));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}



void printDoubleTree(DoubleTree *aTree, int aTypeOfPassage)
{
    if(NULL != aTree)
    {
        
        printf("\t\t\t\t\t\tThe tree\n");
        
        switch(aTypeOfPassage)
        {
            case 1 :
                
                
                SymmetricPrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.3f\n",aTree->root->value);

        
            break;
    
            case 2 :
                
                PlainPrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.3f\n",aTree->root->value);



            break;
                
            case 3 :
                
                BackPrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.3f\n",aTree->root->value);



            break;
        }
    }
}

void SymmetricPassage_And_PrintTree(Double_Node *aNode);
{
    if(NULL != aNode)
    {
        SymmetricPrintNode(aNode->leftChild);
        printf(" %.3f ",aNode->value);
        SymmetricPrintNode(aNode->rightChild);
    }
}

void PlainPassage_And_PrintTree(Double_Node *aNode);
{
    if(NULL != aNode)
    {
        printf(" %.3f ",aNode->value);
        PlainPrintNode(aNode->leftChild);
        PlainPrintNode(aNode->rightChild);
    }
}

void BackPassage_And_PrintTree(Double_Node *aNode);
{
    if(NULL != aNode)
    {
        BackPassage_And_PrintNode(aNode->leftChild);
        BackPassage_And_PrintTree(aNode->rightChild);
        printf(" %.3f ",aNode->value);
    }
}
