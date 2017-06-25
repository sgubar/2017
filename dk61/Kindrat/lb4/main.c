#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

int main()
{
	
	List *theList = createList();
	
	
	if(theList != NULL)
	{
		
		fillElements(theList);
		printList(theList);
		rePrintList(theList);
		deleteList(theList);
		
		return 0;
	}
	
	return 1;
}
