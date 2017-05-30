#include <stdio.h>
#include <stdlib.h>
#include "TLFloat.h"
//#include "sort.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{

	FloatList *aList = TLCreateFloatList();
	if(NULL == aList)
	{
		return -1;	
	}
	
	TLAddFloatValueToList(aList,3.243);
	TLAddFloatValueToList(aList,7.243);
	TLAddFloatValueToList(aList,9.243);
	TLAddFloatValueToList(aList,4.243);
	TLAddFloatValueToList(aList,5.243);
	TLAddFloatValueToList(aList,6.243);
	TLAddFloatValueToList(aList,2.243);
	TLAddFloatValueToList(aList,8.243);
	
	TLPrintList(aList);
	
	printf("The value at index %d: %.3f\n", 5, TLFloatValueAtIndex(aList, 5));

	printf("The value at index %d: %f\n", 10, TLFloatValueAtIndex(aList, 10));
	
	printf("The count of value in the list: %d\n", aList->count);
	
	TLInsertFloatValueAtIndex(aList, 1256.7436, 0);
	TLPrintList(aList);
	TLDestroyFloatValueAtIndex(aList,8);
	TLPrintList(aList);
	
	float theSum = FindAverageInList(aList);
	deleteFirstFloatElement(aList, theSum);
	printf("\nAverage = %f\n", theSum);
	
		TLPrintList(aList);
	
//	printf("Before sorting.....\n");

	
//	printf("After sorting....\n");
//	shellSort(aList);
//	TLPrintList(aList);
	
	TLDestroyFloatList(aList);
	
	
	return 0;
}
