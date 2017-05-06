#include <stdio.h>
#include "dk_tool.h"

int main() {

    intTree *aTree=createIntTree();
    insertIntValueToTree(aTree, 50);
    insertIntValueToTree(aTree, 45);
    insertIntValueToTree(aTree, 40);
    insertIntValueToTree(aTree, 46);


    findNodeWithValue(aTree, 47);


    destroyIntTree(aTree);
    return 0;
}