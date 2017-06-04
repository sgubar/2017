//
//  main.c
//  HW7
//
//  Created by Maxim Salim on 04.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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
    //insertIntValueToTree(Tree, 5);
    
    deleteNodeWithValue(Tree, 1);
    
    printTree(Tree);
    
    //printf("%d\n", countNodesWithTree(Tree));
    
    
}

