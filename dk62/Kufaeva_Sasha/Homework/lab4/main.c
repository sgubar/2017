#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

int main()
{
	//создаём пустой список
	List *theList = createList();
	
	//если создало список
	if(theList != NULL)
	{
		//заполняем его элементами
		fillElements(theList);
		
		//выводим список в нормальном порядке
		printList(theList);
		
		//выводим список как в задании
		rePrintList(theList);
		
		//удаляем список
		deleteList(theList);
		
		return 0;
	}
	
	return 1;
}
