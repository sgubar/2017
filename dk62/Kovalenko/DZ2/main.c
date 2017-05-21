#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int X1;int X2;int X3;int Y1;int Y2;int Y3;
    int size;
    printf("pls enter a size of list:");
    scanf("%d", &size);
    printf("pls enter X1 Y1:");
    scanf("%d %d",&X1,&Y1);
    printf("pls enter X2 Y2:");
    scanf("%d %d",&X2,&Y2);
    printf("pls enter X3 Y3:");
    scanf("%d %d",&X3,&Y3);
    list *Tlist=create(size);
    data(Tlist, X1, Y1, X2, Y2, X3, Y3);
    Print(Tlist);
    space_size(Tlist);
    return 0;
}
