//
// Created by Oleg on 07.05.2017.
//

#include "dk_tree.h"
#include "wayList.h"
#include <stdlib.h>

//help function declaration
void destroyNode(doubleNode *aNode);
doubleNode *createDoubleNodeWithValue(double aValue);
doubleNode *findReceiver(doubleNode *aNodeToDelete);
void printNode(doubleNode *aNode, int typeBypass);



//create tree
doubleTree *createDoubleTree()
{
    doubleTree *aTree=(doubleTree *)malloc(sizeof(doubleTree));

    if(aTree!=NULL)
    {
        aTree->count=0;
        aTree->root=NULL;
    }

    return aTree;
}

//detroy tree
void destroyDoubleTree(doubleTree *aTree)
{
    if(aTree!=NULL)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

//insert value to tree
int insertDoubleValueToTree(doubleTree *aTree, double aValue)
{
    int theResult=-1;

    if(aTree==NULL)
    {
        printf("ERROR. Can't insert value in nonexistent tree\n");
        return theResult;
    }

    doubleNode *aNode=createDoubleNodeWithValue(aValue);
    if(aNode==NULL)
    {
        printf("ERROR. Node has not inserted. Problem with a memory\n");
        return theResult;
    }


    if(aTree->root==NULL)
    {
        aTree->root=aNode;
    }
    else
    {
        doubleNode *theCurrent=aTree->root;
        while(1)
        {
            if(theCurrent->value==aValue)
            {
                printf("can't be 2 the same elements\n");
                return theResult;
            }
            else if(theCurrent->value>aValue)
            {
                if(theCurrent->leftChild==NULL)
                {
                    theCurrent->leftChild=aNode;
                    break;
                }
                theCurrent=theCurrent->leftChild;
            }
            else if(theCurrent->value<aValue)
            {
                if(theCurrent->rightChild==NULL)
                {
                    theCurrent->rightChild=aNode;
                    break;
                }
                theCurrent=theCurrent->rightChild;
            }

        }

    }

    aTree->count++;
    theResult=0;

    return theResult;

}

//find node in tree
doubleNode *findNodeWithValue(doubleTree *aTree, double aValue)
{
    doubleNode *theResult=NULL;

    if(aTree==NULL)
        return theResult;

    if(aTree->root==NULL)
    {
        printf("ERROR. Not found. Tree haven't elements\n");
        return theResult;
    }
    else
    {
        wayList *aList=createWayList();
        int counter=0;

        doubleNode *theCurrent=aTree->root;

        addWayValueToList(aList, "root_Lev", counter, theCurrent->value);
        counter++;

        while(theCurrent->value!=aValue)
        {

            if(theCurrent->value>aValue)
            {
                theCurrent=theCurrent->leftChild;

                if(theCurrent==NULL)
                {
                    printf("Not found\n");
                    break;
                }
                addWayValueToList(aList, "left_Child_Lev", counter, theCurrent->value);
            }
            else
            {
                theCurrent=theCurrent->rightChild;

                if(theCurrent==NULL)
                {
                    printf("Not found\n");
                    break;
                }

                addWayValueToList(aList, "right_Child_Lev", counter, theCurrent->value);
            }

            counter++;
        }

        theResult=theCurrent;

        if(theCurrent!=NULL)
            printList(aList);

        destroyWayList(aList);
    }

    return theResult;

}

//print tree
void printTree(doubleTree *aTree, int typeBypass)
{
    if(aTree!=NULL)
    {
        if(aTree->count==0)
        {
            printf("Tree haven't elements\n");
            return;
        }
        printf("Tree (%i elements): ", aTree->count);
        printNode(aTree->root, typeBypass);
        printf("\n");
    }

}

//delete value in tree
int deleteNodeWithValue(doubleTree *aTree, double aValue)
{
    int theResult=-1;
    doubleNode *aNodeToDelete=NULL;
    doubleNode *aParentNodeToDelete=NULL;

    if(aTree==NULL)
    {
        printf("Not found. Tree haven't created\n");
        return theResult;
    }


    if(aTree->root==NULL)
    {
        printf("Not found. Tree haven't elements\n");
        return theResult;
    }
    else
    {
        aNodeToDelete=aTree->root;

        while(aNodeToDelete->value!=aValue)
        {
            aParentNodeToDelete=aNodeToDelete;
            aNodeToDelete->value>aValue
            ?(aNodeToDelete=aNodeToDelete->leftChild)
            :(aNodeToDelete=aNodeToDelete->rightChild);

            if(aNodeToDelete==NULL)
            {
                printf("Not found int for delete\n");
                return theResult;
            }
        }
    }

    if(aNodeToDelete->leftChild==NULL && aNodeToDelete->rightChild==NULL)
    {
        if(aParentNodeToDelete==NULL)
        {
            aTree->root=NULL;
        }
        else
        {
            (aParentNodeToDelete->value > aValue
             ?aParentNodeToDelete->leftChild = NULL
             :(aParentNodeToDelete->rightChild = NULL));
        }

        free(aNodeToDelete);
        theResult=0;
    }
    else if(aNodeToDelete->leftChild!=NULL && aNodeToDelete->rightChild==NULL)
    {
        if(aParentNodeToDelete==NULL)
        {
            aTree->root=aNodeToDelete->leftChild;
        }
        else
        {
            (aParentNodeToDelete->value > aValue
             ?aParentNodeToDelete->leftChild = aNodeToDelete->leftChild
             :(aParentNodeToDelete->rightChild = aNodeToDelete->leftChild));
        }

        free(aNodeToDelete);
        theResult=0;
    }
    else if(aNodeToDelete->leftChild==NULL &&aNodeToDelete->rightChild!=NULL)
    {

        if(aParentNodeToDelete==NULL)
        {
            aTree->root=aNodeToDelete->rightChild;
        }
        else
        {
            (aParentNodeToDelete->value>aValue
             ?aParentNodeToDelete->leftChild=aNodeToDelete->rightChild
             :(aParentNodeToDelete->rightChild=aNodeToDelete->rightChild));
        }

        free(aNodeToDelete);
        theResult=0;

    }
    else if(aNodeToDelete->leftChild!=NULL && aNodeToDelete->rightChild!=NULL)
    {
        doubleNode *receiver= findReceiver(aNodeToDelete);

        receiver->leftChild=aNodeToDelete->leftChild;
        receiver->rightChild=aNodeToDelete->rightChild;

        if(aParentNodeToDelete==NULL)
        {
            aTree->root=receiver;
        }
        else
        {
            receiver->value<aParentNodeToDelete->value
            ?aParentNodeToDelete->leftChild=receiver
            :(aParentNodeToDelete->rightChild=receiver);
        }

        free(aNodeToDelete);
        theResult=0;

    }

    aTree->count--;

    return theResult;
}


//help function
void destroyNode(doubleNode *aNode)
{
    if(aNode!=NULL)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);
        free(aNode);
    }
}

doubleNode *createDoubleNodeWithValue(double aValue)
{
    doubleNode *aNode=(doubleNode *)malloc(sizeof(doubleNode));

    if(aNode!=NULL)
    {
        aNode->rightChild=NULL;
        aNode->leftChild=NULL;
        aNode->value=aValue;
    }
    return aNode;
}

doubleNode *findReceiver(doubleNode *aNodeToDelete)
{
    doubleNode *aParentReceiver=aNodeToDelete;
    doubleNode *aReceiver=aNodeToDelete->rightChild;

    if(aReceiver->leftChild==NULL && aReceiver->rightChild==NULL)
    {
        aParentReceiver->rightChild=NULL;
    }
    else if(aReceiver->leftChild==NULL && aReceiver->rightChild!=NULL)
    {
        aParentReceiver->rightChild=aReceiver->rightChild;
    }
    else
    {
        while (1)
        {
            if(aReceiver->leftChild==NULL)
                break;

            aParentReceiver=aReceiver;
            aReceiver=aReceiver->leftChild;
        }

        if(aReceiver->rightChild==NULL)
        {
            aParentReceiver->leftChild=NULL;
        }
        else
        {
            aParentReceiver->leftChild=aReceiver->rightChild;
        }

    }

    return aReceiver;
}

void printNode(doubleNode *aNode, int typeBypass)
{
    if(aNode!=NULL)
    {
        if(typeBypass==2)
        {
            printf(" (%.3lf)", aNode->value);
        }
        printNode(aNode->leftChild, typeBypass);
        if(typeBypass==1)
        {
            printf(" (%.3lf)", aNode->value);
        }
        printNode(aNode->rightChild, typeBypass);
        if(typeBypass==3)
        {
            printf(" (%.3lf)", aNode->value);
        }

    }
}


