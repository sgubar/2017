#include <GL/glut.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "binary_tree.h"
#include "List.h"
#include "draw.h"

int min;
int max;
int width;
int height;
int deltaY;
int SizeOfSquare;
int rootPosition_Y;
int MAX_DEPTH;

IntTree *aTree;
IntList *aList;

IntTree *createIntTree(void)
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

//return numbers from [a ... b]
int randomIntFromRange (int min, int max)
{
    return rand() % (max-min+1) + min;
}

void destroyIntTree(IntTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

int insertIntValueToTree(IntTree *aTree, int aValue)
{
    int theResult = -1;
	if (NULL == aTree)
	{
		return theResult;
	}

	TreeNode *theNode = createTreeNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return theResult;
	}

	//1. List is empty
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
		theResult = 0;
	}

	//2. Have a root at least
	else
	{
		TreeNode *theCurrent = aTree->root;
		TreeNode *theParent = NULL;

		while (1)
		{
			//tree doesn't have the same values
			if (aValue == theCurrent->value)
				return theResult;

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
		theNode->level = theParent->level + 1;
        theResult = 0;
		aTree->count ++;
	}
	return theResult;
}

TreeNode *findNodeWithValue(IntTree *aTree, int aValue)
{
	TreeNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
	    if (aTree->root != NULL)
		theCurrentNode = aTree->root;//<! - start from root

		while (aValue != theCurrentNode->value) //<! - walk through the tree
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

TreeNode *findParentOfTheNode(IntTree *aTree, TreeNode *aNode)
{
    TreeNode *theParent = NULL;

    if(NULL == aNode || NULL == aTree)
    {
        return theParent;
    }
	else
	{
        TreeNode *theCurrentNode = NULL;

        if(NULL != aTree->root)
		theCurrentNode = aTree->root; //<! - start from root

		while (aNode->value != theCurrentNode->value) //<! - walk through the tree
		{
		    theParent = theCurrentNode;
			theCurrentNode = (aNode->value < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	return theParent;
}

TreeNode *findReceiver(IntTree *aTree, TreeNode *aNodeToDestroy)
{
	if (NULL == aTree || NULL == aNodeToDestroy)
	{
	    return NULL;
	}
	else
    {
	    TreeNode *aReceiver = aNodeToDestroy->rightChild;
        if (NULL == aReceiver)
            return NULL;

		while ( 1 ) //<! - walk from aNodeToDestroy
		{
			if (NULL == aReceiver->leftChild)
			{
				break;
			}
			aReceiver = aReceiver->leftChild; // to the smallest Node
		}
	return aReceiver;
    }
}


int deleteNodeWithValue(IntTree *aTree, int aValue)
{
    //bad tree
	if(NULL == aTree)
		return -1;

	//empty list
	if(aTree->root == NULL)
        return -1;

    //find node to delete
	TreeNode *theCurrentNode = findNodeWithValue(aTree, aValue);
	//find her parent
    TreeNode *theParent = findParentOfTheNode(aTree, theCurrentNode);

	//Not found needed Value
	if (theCurrentNode == NULL || theParent == NULL)
        return -1;

    // 0. delete root = impossible
    if (theCurrentNode == aTree->root)
        return -1;

    //1. node == Leaf
    if (theCurrentNode->leftChild  == NULL &&
        theCurrentNode->rightChild == NULL)
    {
        if (theParent->leftChild == theCurrentNode)
            theParent->leftChild = NULL;
        else
            theParent->rightChild = NULL;
    }
    //2. Node have only 1 child
    if (theCurrentNode->leftChild  == NULL ||
        theCurrentNode->rightChild == NULL)
    {
        //node to delete in the left part
        if (theParent->leftChild == theCurrentNode)
        {
            //node to delete have bunch
            if (NULL != theCurrentNode->leftChild)
            //save left bunch
            theParent->leftChild = theCurrentNode->leftChild;
            else
            //save right bunch
            theParent->leftChild = theCurrentNode->rightChild;

            //refresh down-tree
            refreshLevel(aTree, theParent->leftChild);
        }
        //node to delete in the right part
        else
        {
            if (theParent->rightChild == theCurrentNode)
            {
                if (NULL != theCurrentNode->leftChild)
                    //save left bunch
                    theParent->rightChild = theCurrentNode->leftChild;
                else
                    //save right bunch
                    theParent->rightChild = theCurrentNode->rightChild;

                refreshLevel(aTree, theParent->rightChild);
            }
        }

    }
    //3. aNode have 2 children
    if (theCurrentNode->leftChild != NULL &&
        theCurrentNode->rightChild!= NULL)
    {
        TreeNode *aReceiver = findReceiver(aTree, theCurrentNode);

        //receiver = left leaf
        if (theCurrentNode->rightChild != aReceiver)
        {
            //rightChild of the Receiver take
            //the ParentOfTheReceiver on the left
            TreeNode *theParentOfReceiver = findParentOfTheNode(aTree, aReceiver);

                //save right bunch
            if (aReceiver->rightChild != NULL)
                theParentOfReceiver->leftChild = aReceiver->rightChild;
            else
                //nothing to save
                theParentOfReceiver->leftChild = NULL;

            //take left & right bunches by receiver
            aReceiver->leftChild = theCurrentNode->leftChild;
            aReceiver->rightChild = theCurrentNode->rightChild;

            aReceiver->level = theParent->level + 1;
            refreshLevel(aTree, theParentOfReceiver->leftChild);
        }

        //receiver = rightChild of Deleted Node
        if (theCurrentNode->rightChild == aReceiver)
        {
            aReceiver->leftChild = theCurrentNode->leftChild;
            aReceiver->level = theParent->level + 1;
            refreshLevel(aTree, aReceiver->rightChild);
        }

        //new pointer on receiver
        //from the parent of deletedNode
        if (theParent->leftChild == theCurrentNode)
            theParent->leftChild = aReceiver;
        else
            theParent->rightChild = aReceiver;


    }
    aTree ->count --;
    free(theCurrentNode);
    return 0;
}

//print information from a Nodes
void printTreeNode(TreeNode *aNode)
{
    if(NULL == aNode)
        return;

	printf("(%d|%d) ", aNode->value, aNode->level);
}

void printTree(IntTree *aTree, void(*method)(TreeNode *) )
{
	if (NULL != aTree)
	{
		if (aTree->count > 0)
		{
			method(aTree->root);
		}
		else
			printf("List is empty\n");
	}
	else
		printf("List is not exist");
}

// root - left - right
void straight(TreeNode *aNode)
{
    printTreeNode(aNode);
	if(aNode->leftChild != NULL)
        straight(aNode->leftChild);

	if(aNode->rightChild != NULL)
        straight(aNode->rightChild);
}

// from leaves to parents
void backward(TreeNode *aNode)
{
		if(aNode->leftChild != NULL)
		backward(aNode->leftChild);

	if(aNode->rightChild != NULL)
		backward(aNode->rightChild);

		printTreeNode(aNode);
}

//Left Leaves -> root -> right Leaf
//check nodes by recursion:  MIN -> {..} -> MAX value
void symmetry(TreeNode *aNode)
{
	if(aNode->leftChild != NULL)
		symmetry(aNode->leftChild);
		printTreeNode(aNode);

	if(aNode->rightChild != NULL)
		symmetry(aNode->rightChild);

}


void destroyNode(TreeNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

TreeNode *createTreeNodeWithValue(int aValue)
{
	TreeNode *theNode = (TreeNode *)malloc(sizeof(TreeNode));

	if (NULL != theNode)
	{
	    theNode->level = 0;
	    theNode->mark = 0;
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

IntTree *getIntTreeWithRandValues( int amount, bool state )
{
    IntTree *aTree = createIntTree();
    if(NULL == aTree)
        return NULL;
    int i;

    //sequence for Euclid's Sieve
    if(state  == 1)
    {
        for (i = 0; i < amount; i++)
            insertIntValueToTree(aTree, i+1);
    }
    else
    {
        for (i = 0; i < amount; i++)
            insertIntValueToTree(aTree, randomIntFromRange(min, max));
    }
    return aTree;
}


void refreshLevel(IntTree *aTree, TreeNode *aNode)
{
    if (NULL == aNode)
        return;

    // ParentLevel + 1
    aNode->level = findParentOfTheNode(aTree, aNode)->level + 1;
	if(aNode->leftChild != NULL)
        refreshLevel(aTree, aNode->leftChild);

	if(aNode->rightChild != NULL)
        refreshLevel(aTree, aNode->rightChild);
}

//debug for function Delete Node
void analysis(TreeNode *aNode)
{
    if (NULL != aNode)
    {
        printf("Information about TreeNode:\n");
        if ( aNode == aTree->root)
        {
            printf("ROOT");
            return;
        }
        printf("X = %d\n", getNodePos_X(aTree, aNode));
        printf("Y = %d\n", getNodePos_Y(aTree, aNode));

        printf("\nParent = ");
        printTreeNode(findParentOfTheNode(aTree, aNode));

        printf("\nTheNodeToDelete = ");
        printTreeNode(aNode);

        //if nodeToDel have 2 children print receiver
        if (NULL != aNode->rightChild  &&
            NULL != aNode->leftChild    )
        {
            printf("\nReceiver = ");
            printTreeNode(findReceiver(aTree, aNode));

            printf("\nParentOfTheReceiver = ");
            printTreeNode(findParentOfTheNode(aTree, (findReceiver(aTree, aNode))));
        }
        else
            printf("\nNode have 1 child\n");
    }
    else
        printf("Miss Click\n");
}


TreeNode *MarkNodeToDelete(IntTree *aTree, IntList *aList, int x_click, int y_click)
{
    if (NULL == aTree ||
        NULL == aList ||
        x_click < 0 ||
        x_click > width ||
        y_click < 0 ||
        y_click > height )
        return NULL;

    TreeNode *theCurrentNode = aTree->root;
    if (NULL == theCurrentNode)
        return NULL;

    //position for aTree->root
    int x_pos = getNodePos_X(aTree, theCurrentNode);
    int y_pos = getNodePos_Y(aTree, theCurrentNode);

    //don't attract with click under 5-th or higher 0 level
    if(y_click < y_pos || y_click > y_pos + MAX_DEPTH * deltaY + SizeOfSquare) //  5!?
        return NULL;

    while (1)
    {
        // click in the node
        if (y_click >= y_pos && y_click <= y_pos + SizeOfSquare)
        {
            if (x_click >= x_pos && x_click <= x_pos + SizeOfSquare)
            {

                if (theCurrentNode->mark == 0)
                {
                    AddIntValueToList(aList, theCurrentNode->value);
                }
                else
                {
                    DeleteValueFromIntList(aList, theCurrentNode->value);
                }

                //different states
                theCurrentNode->mark = (theCurrentNode->mark + 1) % 2;
                return theCurrentNode;
            }
        }

        //we had pass the Node = miss_click
        if (y_pos > y_click)
           break;

        //our node in the left part from the cursor
        if (x_click < x_pos)
            theCurrentNode = theCurrentNode->leftChild;
        else
            theCurrentNode = theCurrentNode->rightChild;

        if (theCurrentNode != NULL)
        {
            //refresh current position
            x_pos = getNodePos_X(aTree, theCurrentNode);
            y_pos = getNodePos_Y(aTree, theCurrentNode);
        }
        else
        {
            break;
        }
    }
    return NULL;
}

void Show_XY_pos(int x_mouse, int y_mouse)
{
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(x_mouse, y_mouse);
    glVertex2f(x_mouse+10, y_mouse);
    glVertex2f(x_mouse+10, y_mouse+10);
    glVertex2f(x_mouse, y_mouse+10);
    glEnd();

    int buffer = 20;
    char *string = (char*)malloc(sizeof(char)* buffer);
    char *str = (char*)malloc(sizeof(char)* buffer);

    strcpy(string, "X = ");
    itoa(x_mouse, str, 10);
    strcat (string, str);
    glColor3f(1, 0, 0);
    renderBitmapString(40, 20, GLUT_BITMAP_9_BY_15, string);

    strcpy(string, "Y = ");
    itoa(y_mouse, str, 10);
    strcat (string, str);
    glColor3f(0, 0.7, 1);
    renderBitmapString(40, 35, GLUT_BITMAP_9_BY_15, string);

    free(string);
    free(str);
}

int getNodePos_X(IntTree *aTree, TreeNode *aNode)
{
    if(NULL == aTree || NULL == aNode)
    {
        return -1;
    }

    TreeNode *theCurrentNode = aTree->root;

    // x for the ROOT
    int x = width / (2 << theCurrentNode->level) - SizeOfSquare/2;
    while(theCurrentNode->value != aNode->value)
    {
        if (NULL == theCurrentNode)
            break;

        if (aNode->value < theCurrentNode->value)
        {
            theCurrentNode = theCurrentNode -> leftChild;
            x -= width/(2 << theCurrentNode->level);
        }
        else
        {
            theCurrentNode = theCurrentNode -> rightChild;
            x += width/(2 << theCurrentNode->level);
        }
    }
    return x;
}

int getNodePos_Y(IntTree *aTree, TreeNode *aNode)
{
    return rootPosition_Y + aNode->level * deltaY;
}

void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);
