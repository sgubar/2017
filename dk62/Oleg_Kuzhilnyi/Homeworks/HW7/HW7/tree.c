

#include "tree.h"
#include <stdlib.h>

void printDoubleTree(DoubleTree *aTree, int aTypeOfPassage)
{
    if(NULL != aTree)
    {
        
        printf("\t\t\t\t\t\tThe tree\n");
        
        switch(aTypeOfPassage)
        {
            case 1 :
                
                
                SymmetricPassage_And_PrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.2f\n",aTree->root->value);

        
            break;
    
            case 2 :
                
                PlainPassage_And_PrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.2f\n",aTree->root->value);


            break;
                
            case 3 :
                
                BackPassage_And_PrintNode(aTree->root);
                putchar('\n');
                
                printf("The root: %.2f\n",aTree->root->value);

                
            break;
        }
    }
}

void BackPassage_And_PrintNode(Double_Node *aNode)
{
    if(NULL != aNode)
    {
        BackPassage_And_PrintNode(aNode->leftChild);
        BackPassage_And_PrintNode(aNode->rightChild);
        printf(" %.2f ",aNode->value);
    }
}

void PlainPassage_And_PrintNode(Double_Node *aNode)
{
    if(NULL != aNode)
    {
        printf(" %.2f ",aNode->value);
        PlainPassage_And_PrintNode(aNode->leftChild);
        PlainPassage_And_PrintNode(aNode->rightChild);
    }
}


void SymmetricPassage_And_PrintNode(Double_Node *aNode)
{
    if(NULL != aNode)
    {
        SymmetricPassage_And_PrintNode(aNode->leftChild);
        printf(" %.2f ",aNode->value);
        SymmetricPassage_And_PrintNode(aNode->rightChild);
    }
}


Double_Node* FindMinNodeInBinarTree(Double_Node* root)
{
    while(root->leftChild != NULL) root = root->leftChild;
    return root;
}
// Function to search a delete a value from tree.


 Double_Node* DeleteNodeFromTree(DoubleTree *aTree,Double_Node *Node, double data)

{
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
             Double_Node *temp = Node;
            Node = Node->rightChild;
            free( temp);
            
            aTree->count--;
        }
    else if(Node->rightChild == NULL)       /*if have left children*/
        {
             Double_Node *temp = Node;
            Node = Node->leftChild;
            free(temp);
            
           aTree->count--;
        }
        //if have 2 children
    else
        {
             Double_Node *temp = FindMinNodeInBinarTree(Node->rightChild);
            Node->value = temp->value;
            Node->rightChild = DeleteNodeFromTree(aTree,Node->rightChild,temp->value);
        }

        aTree->count = aTree->count --;
    }

    return Node;
}
