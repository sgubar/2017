#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(void)
{
    intTree *Tree = createIntTree();
    
    insertIntValueToTree(Tree, 1);
    insertIntValueToTree(Tree, 2);
    insertIntValueToTree(Tree, 3);
    insertIntValueToTree(Tree, 4);
    insertIntValueToTree(Tree, 5);
    insertIntValueToTree(Tree, 6);
    insertIntValueToTree(Tree, 7);
    insertIntValueToTree(Tree, 8);
    insertIntValueToTree(Tree, 9);
    insertIntValueToTree(Tree, 10);
    insertIntValueToTree(Tree, 5);
    
    printTree(Tree);
    
    deleteNodeWithValue(Tree, 6);
    
    printTree(Tree);
    
    destroyIntTree(Tree);
    
    return 0;
}

