#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int size;
	printf("enter sizo of list:\n");
	scanf("%d",&size);
    list *Tlist=create(size);
    data(Tlist, 7,8,9,4,5,6);
    data(Tlist, 17,18,19,14,15,16);
    data(Tlist, 27,28,29,24,25,26);
    Print(Tlist);
    space_size(Tlist);
    return 0;
}
