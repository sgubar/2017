#include <stdio.h>
#include "dk_tool.h"

int main() {

    intTree *aTree=createIntTree();


    findNodeWithValue(aTree, 47);


    destroyIntTree(aTree);
    return 0;
}