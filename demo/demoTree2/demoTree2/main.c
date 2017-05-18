//
//  main.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tree.h"


int main(int argc, const char * argv[]) {
	
    
    DoubleTree *TheTree = createDoubleTree();
    
    insertDoubleValueToTree(TheTree,  2.63);
    insertDoubleValueToTree(TheTree,  5.6);
    insertDoubleValueToTree(TheTree,  2.6);
    insertDoubleValueToTree(TheTree,  9.63);
    insertDoubleValueToTree(TheTree,  0.1);
    insertDoubleValueToTree(TheTree,  3.63);
    insertDoubleValueToTree(TheTree,  9.1);
    insertDoubleValueToTree(TheTree,  9.3);
    insertDoubleValueToTree(TheTree,  2.63);
    insertDoubleValueToTree(TheTree,  1.63);

     printDoubleTree (TheTree,1);

    
    
	return 0;
}
