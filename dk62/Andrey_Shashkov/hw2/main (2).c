#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"


int main(int argc, char *argv[]) {
	
	printf("Enter a nomber of paralelepieds :");
	int counter = scan();
	mylist *List=createMyList(counter);
	int i;
    for(i=0; i<counter; i++)
    {
    addCoor(List);
    }
	printMyFigure(List);
	destroyMyList(List);
	return 0;
}
