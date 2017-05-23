//
//  CharBinarTree.c
//  Lab5
//
//  Created by air on 5/21/17.
//  Copyright © 2017 Laba5. All rights reserved.
//

#include "CharBinarTree.h"
#include <stdlib.h>
#include <ctype.h>
static void destroyNode(Char_Node *aNode);
static Char_Node *createChar_NodeWithValue(char aValue);

CharTree *createCharTree()
{
    CharTree *theTree = (CharTree *)malloc(sizeof(CharTree));
    
    if (NULL != theTree)
    {
        theTree->root = NULL;
        theTree->count = 0;
    }
    
    return theTree;
}

void destroyCharTree(CharTree *aTree)
{
    if (NULL != aTree)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

void insertCharValueToTree(CharTree *aTree, char aValue)
{
    if (NULL == aTree)
    {
        return;
    }
    
    Char_Node *theNode = createChar_NodeWithValue(aValue);
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
        Char_Node *theCurrent = aTree->root;
        Char_Node *theParent = NULL;
        
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

Char_Node *findNodeWithValue(CharTree *aTree, char aValue)
{
    Char_Node *theCurrentNode = NULL;
    
    if (NULL != aTree)
    {
        Char_Node *theCurrentNode = aTree->root; ///< - start from root
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
        return theCurrentNode;
    }
    
    return theCurrentNode;
}

int count_NodesOfTree(CharTree *aTree)
{
    if(NULL != aTree)
        return aTree->count;
    
    
    return 0;
}

void printCharTree(CharTree *aTree, char aTypeOfPassage)
{
    if(NULL != aTree)
    {
        
        printf("\t\t\t\t\t\t\t\tThe tree\n");
        
        switch(aTypeOfPassage)
        {
            case 's' :
                
                
                SymmetricPassage_And_PrintNode(aTree->root);
                putchar('\n');

                printf("The root: %c\n",aTree->root->value);
                
                
                break;
                
            case 'p' :
                
                PlainPassage_And_PrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %c\n",aTree->root->value);
                
                
                break;
                
            case 'b' :
                
                BackPassage_And_PrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %c\n",aTree->root->value);
                
                
                break;
        }
    }
}

void BackPassage_And_PrintNode(Char_Node *aNode)
{
    if(NULL != aNode)
    {
        BackPassage_And_PrintNode(aNode->leftChild);
        BackPassage_And_PrintNode(aNode->rightChild);
        printf(" (%c) ",aNode->value);
    }
}

void PlainPassage_And_PrintNode(Char_Node *aNode)
{
    if(NULL != aNode)
    {
        printf(" (%c) ",aNode->value);
        PlainPassage_And_PrintNode(aNode->leftChild);
        PlainPassage_And_PrintNode(aNode->rightChild);
    }
}


void SymmetricPassage_And_PrintNode(Char_Node *aNode)
{
    if(NULL != aNode)
    {
        SymmetricPassage_And_PrintNode(aNode->leftChild);
        printf(" (%c) ",aNode->value);
        SymmetricPassage_And_PrintNode(aNode->rightChild);
    }
}


Char_Node* FindMinNodeInBinarTree(Char_Node* root)
{
    while(root->leftChild != NULL) root = root->leftChild;
    return root;
}
// Function to search a delete a value from tree.


Char_Node* DeleteNodeFromTree(CharTree *aTree,Char_Node *Node, char data)

{
    
    if(NULL == findNodeWithValue(aTree, data))
    {
        printf("Your element (%c) not found for delete\n",data);
        return NULL;
        
    }else
        
    if(Node == NULL) return Node;
    
    else if(data < Node->value)
        Node->leftChild = DeleteNodeFromTree(aTree,Node->leftChild,data);
    
    
    else if (data > Node->value)
        Node->rightChild = DeleteNodeFromTree(aTree,Node->rightChild,data);
    
    else {
        
        if(Node->leftChild == NULL && Node->rightChild == NULL) /*if no have children*/
        {
            free( Node);
            Node = NULL;
            
            aTree->count--;
        }
        
        //if have only one children
        else if(Node->leftChild == NULL)        /*if have right children*/
        {
            Char_Node *temp = Node;
            Node = Node->rightChild;
            free( temp);
            
            aTree->count--;
        }
        else if(Node->rightChild == NULL)       /*if have left children*/
        {
            Char_Node *temp = Node;
            Node = Node->leftChild;
            free(temp);
            
            aTree->count--;
        }
        //if have 2 children
        else
        {
            Char_Node *temp = FindMinNodeInBinarTree(Node->rightChild);
            Node->value = temp->value;
            Node->rightChild = DeleteNodeFromTree(aTree,Node->rightChild,temp->value);
        }
        
        aTree->count = aTree->count --;
    }
    
    return Node;
}

char chooseTypeOfPassage()
{
    char option = '\0';

    printf("Please Enter the type of Passage for print: (p)lain, (b)ack,(symmetric):\n");
    while  (
            option != 'b' &&
            option != 'p' &&
            option != 's'
           )
    {
        option = getchar();
    }
    
    return option;
    
}

char EnterNodeForDelete()
{
    char option = '\0';
    
    printf("Please Enter char node for delete with another register:\n");
    
    while  ( !isalpha(option) )
    {
        option = getchar();
    }
    
    return option;
    
}


char EnterNodeForFind()
{
    char option = '\0';
    
    printf("Please Enter char node for find in Tree:\n");
    
    while  ( !isalpha(option) )
    {
        option = getchar();
    }
    
    return option;
    
}

#pragma mark -
void destroyNode(Char_Node *aNode)
{
    if (NULL != aNode)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);
        
        free(aNode);
    }
}

Char_Node *createChar_NodeWithValue(char aValue)
{
    Char_Node *theNode = (Char_Node *)malloc(sizeof(Char_Node));
    
    if (NULL != theNode)
    {
        theNode->leftChild = NULL;
        theNode->rightChild = NULL;
        theNode->value = aValue;
    }
    
    return theNode;
}
