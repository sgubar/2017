#include <stdio.h>
#include "tree.h"
int main(void) {
    tree* info;
    char filename[100];
        printf("Please indicate the file with file-type.\n");
        scanf("%s", filename);
        if (!GetData(filename)) { //if function GetData did not find the file
            printf("File does not exist!\n");
            return 0;
        }
        info = New_tree();
        if (info == NULL) {
            printf("File is empty!\n");
            return 0;
        }
    char src;
    printf("Which letter do you want to find\n");
    scanf("%c",src);
    struct node* found = Search(info->Root,src);
    if(found != NULL)
        printf("Found\n");
    return 0;
}