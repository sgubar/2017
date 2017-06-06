#include <stdio.h>
#include <stdlib.h>
#include "hw6.h"

int main() 
{
	
	FloatList *aList = CreateFloatList();
	if(NULL == aList)
	{
		return -1;	
	}
	AddFloatValue(aList,3.283);
	AddFloatValue(aList,3.243);
	AddFloatValue(aList,8.143);
	AddFloatValue(aList,9.944);
	AddFloatValue(aList,6.193);
	AddFloatValue(aList,8.936);
	AddFloatValue(aList,1.458);
	AddFloatValue(aList,1.234);
	AddFloatValue(aList,9.876);
	
	PrintList(aList);
	
	printf("The value at index %d: %.3f\n", 5, FloatValueIndex(aList, 5));
	
	printf("The count of value in the list: %d\n", aList->count);
	
	InsertFloatValueIndex(aList, 2.825, 0);
	PrintList(aList);
	
	DeleteFloatValueIndex(aList,8);
	PrintList(aList);
	
	printf("\n");
	printf("\tBefore sorting:\n");
	PrintList(aList);
	
	printf("\n");
	printf("\tAfter sorting:\n");
	shellSort(aList);
	PrintList(aList);
	
	DeleteFloatList(aList);
	
	return 0;
}
