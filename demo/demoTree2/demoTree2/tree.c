

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
