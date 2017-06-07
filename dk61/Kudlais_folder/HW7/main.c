#include <stdio.h>
#include "Lists.h"
int main() {
    int size;
    printf("Please take the size of array.\n");
    scanf("%i",size);
    float array[size];
    for (int i = 0; i < size; ++i) {
        printf("Please take the value of %i element.\n",i+1);
        scanf("%f",&array[i]);
    }
    GetData(array,size);
    tree* Tree = New_tree();
    PrintTree(Tree);
    printf("Hello, World!\n");
    FreeTree(Tree);
    return 0;
}