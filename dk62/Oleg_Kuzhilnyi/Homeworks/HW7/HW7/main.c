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
        insertDoubleValueToTree(TheTree,  2.28);
    

        printDoubleTree (TheTree,1);
    
    printf("The count of nodes: %d\n", count_NodesOfTree(TheTree));

    
    Double_Node *aFineNode = findNodeWithValue(TheTree,  3.63);
    
    printf("The find element: %.3f\n",aFineNode->value);
    
    
        DeleteNodeFromTree(TheTree,TheTree->root,5.6);
        DeleteNodeFromTree(TheTree,TheTree->root,9.1);
        DeleteNodeFromTree(TheTree,TheTree->root,11.1);
        DeleteNodeFromTree(TheTree,TheTree->root,3.4);

    
         printDoubleTree (TheTree,2);
        printf("The count of nodes: %d\n",count_NodesOfTree(TheTree));
    
    
        destroyDoubleTree(TheTree);
    
    return 0;
}
