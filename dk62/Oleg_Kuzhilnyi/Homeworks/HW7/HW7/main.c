<<<<<<< HEAD


#include <stdio.h>
#include "tree.h"


int main(int argc, const char * argv[]) {
	
    
    DoubleTree *TheTree = createDoubleTree();
    
    insertDoubleValueToTree(TheTree,  2.63);
    insertDoubleValueToTree(TheTree,  5.6);
    insertDoubleValueToTree(TheTree,  2.6);
    insertDoubleValueToTree(TheTree,  9.63);
    insertDoubleValueToTree(TheTree,  11.1);
    insertDoubleValueToTree(TheTree,  3.63);
    insertDoubleValueToTree(TheTree,  9.1);
    insertDoubleValueToTree(TheTree,  9.3);
    insertDoubleValueToTree(TheTree,  2.63);
    insertDoubleValueToTree(TheTree,  1.63);
    
    insertDoubleValueToTree(TheTree,  2.28);

    findNodeWithValue(TheTree,  2.28);

    printDoubleTree (TheTree,1);
    printf("The count of nodes: %d\n",TheTree->count);

    Double_Node *TheNode = TheTree->root;
        
    DeleteNodeFromTree(TheTree,TheNode,5.6);
    DeleteNodeFromTree(TheTree,TheNode,9.1);
    DeleteNodeFromTree(TheTree,TheNode,11.1);
    
     printDoubleTree (TheTree,1);
    printf("The count of nodes: %d\n",TheTree->count);

  //  printf("The count of nodes: %d\n",  countNodesWithTree(TheTree));



    
    destroyDoubleTree(TheTree);
    
	return 0;
}
=======
//
 //  main.c
 //  demoTree2
 //
 //  Created by Slava Gubar on 4/25/17.
 //  Copyright © 2017 Slava Gubar. All rights reserved.
 //
 
 #include <stdio.h>
 
 int main(int argc, const char * argv[]) {
 	// insert code here...
 	printf("Hello, World!\n");
 	return 0;
 }
>>>>>>> origin/master
