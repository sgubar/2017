#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

int main()
{
	
	Tree *theTree = createTree();
	
	if(theTree != NULL)
	{
		
		fillElements(theTree);
		
		
		print(theTree);
		
		
		deleteRootElement(theTree);
		
		print(theTree);
		
		createNotSameElement(theTree);
		
		
		print(theTree);
		
		
		searchRandomChar(theTree);
		
		
		destroyTree(theTree);
		
		
		return 0;
	}
	
	
	return 1;
}
