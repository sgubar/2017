#ifndef sort_h
#define sort_h
#include "List.h"

//sort array
void QuickSort_NodeList(IntList *aList, int b0, int e0);
void Shell_Sort_NodeList( IntList *aList );

void swapAddress(IntList *aList, IntNode *aNodeC, IntNode *aNodeB, int aLeftIn, int aRightIn);	
void swap (IntNode *var1, IntNode *var2);
int fileWrite(char *name_of_sort, int aSize, IntList *aList);
#endif
