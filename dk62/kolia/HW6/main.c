#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{

	FloatList *aList = CreateFloatList();
	if(NULL == aList)
	{
		return -1;
	}
	AddFloatValue(aList,3.293);
	AddFloatValue(aList,3.352);
	AddFloatValue(aList,8.143);
	AddFloatValue(aList,9.853);
	AddFloatValue(aList,6.282);
	AddFloatValue(aList,8.845);
	AddFloatValue(aList,1.547);
	AddFloatValue(aList,1.323);
	AddFloatValue(aList,9.657);

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
