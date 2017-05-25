#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include"node.h"


void main() 
 {
	List*aList = CreateList();

	CountEntryPoints(aList);
	int count = CountList(aList);
	printf("\nNodes created : %d\n", count);

	printListNodebyNode(aList);
	FreeList(aList);
	_getch();


}
