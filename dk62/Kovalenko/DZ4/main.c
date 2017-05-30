#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	FILE *file=fopen ("file.json","w");
    int size;
	printf("enter sizo of list:\n");
	scanf("%d",&size);
    list *Tlist=create(size);
    data(Tlist, 7,8,9,4,5,6);
    data(Tlist, 17,10,19,14,14,16);
    data(Tlist, 27,28,29,24,25,26);
    InsertionSorT(Tlist);
    Print(Tlist);
    filespace(file,Tlist);
    space_size(Tlist);
    fclose(file);
    return 0;
}
