//
//  main.c
//  Lab5
//
//  Created by air on 5/21/17.
//  Copyright © 2017 Laba5. All rights reserved.
//
#include <stdio.h>
#include "CharBinarTree.h"


int main(int argc, const char * argv[]) {
    
    
    CharTree *TheTree = createCharTree();
    
    insertCharValueToTree(TheTree,  'D');
    insertCharValueToTree(TheTree,  'K');
    insertCharValueToTree(TheTree,  'O');
    insertCharValueToTree(TheTree,  'p');
    insertCharValueToTree(TheTree,  'P');
    insertCharValueToTree(TheTree,  'a');
    insertCharValueToTree(TheTree,  'c');
    insertCharValueToTree(TheTree,  't');
    insertCharValueToTree(TheTree,  'I');
    
    

    printCharTree(TheTree,chooseTypeOfPassage());
    
    printf("The count of nodes: %d\n", count_NodesOfTree(TheTree));
    
    Char_Node *aFindNode = findNodeWithValue(TheTree, EnterNodeForFind());
    if(NULL != aFindNode)
        printf("The find node: %c\n",aFindNode->value);
    else printf("The node not find in Tree\n");
   
    
    DeleteNodeFromTree(TheTree,TheTree->root,EnterNodeForDelete());
    DeleteNodeFromTree(TheTree,TheTree->root,EnterNodeForDelete());
    DeleteNodeFromTree(TheTree,TheTree->root,EnterNodeForDelete());
    
    
    printCharTree (TheTree,chooseTypeOfPassage());
    
    
    printf("The count of nodes: %d\n",count_NodesOfTree(TheTree));

    
    Char_Node *theFindNode = findNodeWithValue(TheTree, EnterNodeForFind());
    if(NULL != theFindNode)
        printf("The find node: %c\n",theFindNode->value);
    else printf("The node not find in Tree\n");
    
    
    
    
    
    destroyCharTree(TheTree);

    
    
    return 0;
}
