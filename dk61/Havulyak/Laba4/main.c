#include <stdio.h>
#include "TLIntList.h"
int main()
{
	IntList *theList = TLCreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	TLAddIntValueToList(theList, 34);
	TLAddIntValueToList(theList, 344);
	TLAddIntValueToList(theList, 343);
	TLAddIntValueToList(theList, 342);
	TLAddIntValueToList(theList, 345);
	TLAddIntValueToList(theList, 346);
	TLAddIntValueToList(theList, 347);
	TLAddIntValueToList(theList, 343);
	TLAddIntValueToList(theList, 345);
	
	TLPrintList1(theList);
	TLPrintList2(theList);
	
	TLDestroyIntList(theList);
}
